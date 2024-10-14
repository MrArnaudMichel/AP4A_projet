//
// Created by arnaud on 14/10/24.
//

#include "Server.h"

void Server::notify(const Sensor &sensor) {
    std::cout << getDateFormatted() << ";" << sensor << std::endl;
}

std::string Server::getDateFormatted()  {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y;%H:%M:%S",timeinfo);
    std::string str(buffer);

    return str;
}