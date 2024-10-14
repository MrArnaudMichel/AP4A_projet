//
// Created by arnaud on 14/10/24.
//

#ifndef SERVER_H
#define SERVER_H
#include "Sensor.h"
#include <iostream>
#include <ctime>

class Sensor;
class Server {
public:
    void notify(const Sensor & sensor);

    static std::string getDateFormatted() {
        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];

        time (&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer,sizeof(buffer),"%d-%m-%Y;%H:%M:%S",timeinfo);
        std::string str(buffer);

        return str;
    }
};



#endif //SERVER_H
