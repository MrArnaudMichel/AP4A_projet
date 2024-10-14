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
    static void notify(const Sensor & sensor);

    static std::string getDateFormatted();
};



#endif //SERVER_H
