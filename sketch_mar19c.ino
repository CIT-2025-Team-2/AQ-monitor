#include <Wire.h>
#include "SparkFun_SCD30_Arduino_Library.h"

SCD30 airSensor;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    Wire.setClock(100000);

    if (!airSensor.begin(0x61)) {
        Serial.println("SCD30 not detected!");
        while (1);
    } else {
        Serial.println("SCD30 detected!");
    }
}

void loop() {
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