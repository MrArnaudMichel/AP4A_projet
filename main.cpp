//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

#include "Sensors/SensorBool.h"
#include "Sensors/SensorFloat.h"
#include "Sensors/SensorInteger.h"

int main() {
    Server server;
    SensorBool sensor_light(&server, 2, "light");
    SensorFloat sensor_temperature(&server, 1, "temperature", 12.0, 3.0);
    SensorFloat sensor_humidity(&server, 3, "humidity");
    SensorInteger sensor_sound(&server, 4, "sound");

    Scheduler scheduler;
    scheduler.addSensor(&sensor_light);
    scheduler.addSensor(&sensor_temperature);
    scheduler.addSensor(&sensor_humidity);
    scheduler.addSensor(&sensor_sound);

    scheduler.simulation();
}
