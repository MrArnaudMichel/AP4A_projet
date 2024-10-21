//
// Created by arnaud on 14/10/24.
//

#ifndef SERVER_H
#define SERVER_H
#include "Sensors/Sensor.h"
#include <iostream>
#include <ctime>

class Sensor;
class Server {
public:
    static void notify(const Sensor & sensor, const std::string & filepath);

    static std::string getDateFormatted();

    static void log(const Sensor & sensor, const std::string & message);
    static void logOnFile(const Sensor & sensor, const std::string & filepath, const std::string & message);

    static bool isFileEmpty(const std::string & filepath);
};



#endif //SERVER_H
