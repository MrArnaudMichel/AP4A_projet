//
// Created by arnaud on 14/10/24.
//

#ifndef SERVER_H
#define SERVER_H
#include "Sensors/Sensor.h"
#include <iostream>

class Sensor;
class Server {
public:
    void notify(const Sensor &sensor, const std::string &filepath, const std::string &message);

    std::string getDateFormatted();

    void log(const Sensor & sensor, const std::string & message);
    void logInFile(const Sensor & sensor, const std::string & filepath, const std::string & message);

    bool isFileEmpty(const std::string & filepath);
};



#endif //SERVER_H
