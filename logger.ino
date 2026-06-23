#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <SPI.h>
#include <SD.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define CS_PIN 10

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long lastLogTime = 0;
const unsigned long logInterval = 100000;
unsigned long readingCount = 0;

void setup() {

  Serial.begin(9600);

  Serial.println();
  Serial.println(F("================================="));
  Serial.println(F("=====    SETUP STARTED     ====="));
  Serial.println(F("================================="));


  // Enable internal pull-ups to prevent I2C line lockups on Uno R4 Minima
  pinMode(SDA, INPUT_PULLUP);
  pinMode(SCL, INPUT_PULLUP);

  dht.begin();
  Serial.println(F("DHT OK"));

  // Allow a short delay for the OLED to stabilize (R4 lockup workaround)
  delay(500); 
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED INITIALIZATION FAILED!"));
    while (1);
  }

  Serial.println(F("OLED OK"));

  display.clearDisplay();
  display.setTextSize(1);
  // Critical line to prevent flickering and overlapping: White text, Black background
  display.setTextColor(SSD1306_WHITE, SSD1306_BLACK); 
  display.setCursor(0, 0);
  display.println(F("OLED OK"));
  display.display();

  Serial.println(F("STARTING SD..."));

  if (!SD.begin(CS_PIN)) {
    Serial.println(F("SD INITIALIZATION FAILED!"));
  }
  else {
    Serial.println(F("SD CARD READY"));

    if (!SD.exists("log.csv")) {
      Serial.println(F("CREATING LOG FILE"));
      File dataFile = SD.open("log.csv", FILE_WRITE);

      if (dataFile) {
        dataFile.println(F("reading,temp,hum"));
        dataFile.close();
        Serial.println(F("LOG FILE CREATED"));
      }
      else {
        Serial.println(F("FAILED TO OPEN LOG FILE"));
      }
    }
  }

  // Draw the screen template once on startup so we don't have to constantly clear it in the loop
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(20, 0);
  display.print(F("ENV METRICS"));
  display.drawFastHLine(0, 11, 128, SSD1306_WHITE); // A stylish separator line
  display.display();

  Serial.println(F("SETUP FINISHED"));
}

void loop() {
  Serial.println(F("LOOP STARTED"));

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println(F("DHT READ ERROR"));

    display.clearDisplay();
    display.setCursor(0, 20);
    display.setTextSize(2);
    display.println(F("DHT ERR"));
    display.display();

    delay(2000);
    return;
  }

  Serial.print(F("TEMP = "));
  Serial.println(temp);
  Serial.print(F("HUM  = "));
  Serial.println(hum);

  // --- OLED DISPLAY UPDATE ---
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);

  display.setCursor(0, 20);
  display.print(F("T:"));
  display.print(temp, 1);
  display.print(F(" C "));

  display.setCursor(0, 44);
  display.print(F("H:%"));
  display.print(hum, 1);
  display.print(F("   ")); 

  display.display();

  // --- SD CARD LOGGING ---
  unsigned long currentTime = millis();

  if (currentTime - lastLogTime >= logInterval || lastLogTime == 0) {
    Serial.println(F("SD WRITING STARTED"));

    File dataFile = SD.open("log.csv", FILE_WRITE);

    if (dataFile) {
      readingCount++;

      dataFile.print(readingCount);
      dataFile.print(F(","));
      dataFile.print(temp, 1);
      dataFile.print(F(","));
      dataFile.println(hum, 1);
      dataFile.close();

      Serial.print(F("RECORD "));
      Serial.print(readingCount);
      Serial.println(F(" WRITTEN"));
    }
    else {
      Serial.println(F("FAILED TO OPEN FILE"));
    }

    lastLogTime = currentTime;
    Serial.println(F("SD WRITING FINISHED"));
  }

  delay(2000);
}