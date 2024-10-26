//
// Created by arnaud on 14/10/24.
//

#ifndef SERVER_H
#define SERVER_H
#include "Sensors/Sensor.h"
#include <iostream>

class Sensor;
class Server {
private:
    int uptime = 0;
public:
    //////////////////////////////
    /// Coplien architecture /////
    //////////////////////////////
    Server() = default;
    Server(const Server &server) = default;
    virtual ~Server() = default;
    Server &operator=(const Server &server) = default;

    void update();

    void notify(const Sensor &sensor, const std::string &filepath, const std::string &message);

    static std::string getDateFormatted();

    void log(const Sensor & sensor, const std::string & message);
    void logInFile(const Sensor & sensor, const std::string & filepath, const std::string & message);

    bool isFileEmpty(const std::string & filepath);

    void resume();
};



#endif //SERVER_H
