//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

#include "Sensors/SensorBool.h"
#include "Sensors/SensorFloat.h"
#include "Sensors/SensorInteger.h"

int main() {
    Server server;
    SensorBool sensor_light(&server, 2, "light", "lux");
    SensorFloat sensor_temperature(&server, 5, "temperature", "°C", 20.0, 5.0);
    SensorFloat sensor_humidity(&server, 3, "humidity", "g/m3");
    SensorInteger sensor_sound(&server, 4, "sound", "dB");

    Scheduler scheduler;
    scheduler.addSensor(&sensor_light);
    scheduler.addSensor(&sensor_temperature);
    scheduler.addSensor(&sensor_humidity);
    scheduler.addSensor(&sensor_sound);

    scheduler.addServer(&server);

    scheduler.simulation();
}
