#include <Wire.h>
#include "SparkFun_SCD30_Arduino_Library.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Arduino_SensorKit.h"

SCD30 airSensor;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    Wire.setClock(100000);
    Oled.begin();
    Oled.setFlipMode(true);

    
    if (!airSensor.begin(0x61)) {
        Serial.println("SCD30 not detected!");
        while (1);
    }
    else {
        Serial.println("SCD30 detected!");
    }
    delay(2000);
}

void loop() {

    Oled.setFont(u8x8_font_chroma48medium8_r); 
    Oled.setCursor(0, 3);
    Oled.print("Temp: ");
    Oled.print(airSensor.getTemperature());
    Oled.println(" C");

    Oled.print("Humi: ");
    Oled.print(airSensor.getHumidity());
    Oled.println(" %");
    
    Oled.print("CO2: ");
    Oled.print(airSensor.getCO2());
    Oled.println(" ppm");

    delay(2000);


    if (airSensor.dataAvailable()) {
        Serial.print("CO2 (ppm): ");
        Serial.print(airSensor.getCO2());
        Serial.print(" | Temperature (°C): ");
        Serial.print(airSensor.getTemperature());
        Serial.print(" | Humidity (%): ");
        Serial.println(airSensor.getHumidity());
    } else {
        Serial.println("Waiting for data...");
    }
    delay(2000);
}