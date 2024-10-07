//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

int main() {
    Server server = Server();
//    server << "Hello world";
//    server.setOutput("default");
//    server << "Hello World on log file";
//    server.setOutput();
//    server << "Hello world";

    Scheduler sch;

    Sensor *s = new Sensor("0", 2, &server);
    Sensor *s2 = new Sensor("1", 3, &server);
    sch.addSensor(s);
    sch.addSensor(s2);
    sch.simulation();
}