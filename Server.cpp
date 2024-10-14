//
// Created by arnaud on 14/10/24.
//

#include "Server.h"

#include <fstream>

void Server::notify(const Sensor &sensor) {
    logOnFile(sensor, "Sensor value updated");
    log(sensor, "Sensor value updated");
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

void Server::log(const Sensor &sensor, const std::string &message) {
    std::cout << "\033[1;35m" << getDateFormatted() << " - " << "\033[1;33m" << sensor << " - " << "\033[1;36m" <<
        message << std::endl;
}

void Server::logOnFile(const Sensor &sensor, const std::string &message) {
    std::ofstream file("log.csv", std::ios::app);

    if (file.is_open()) {
        if (isFileEmpty()) {
            file << "Date;Hour;SensorId;SensorValue;Message" << std::endl;
            // print pwd in green
            std::cout << "\033[1;32m" << "log.csv created at " << __FILE__ << "\033[0m" << std::endl;
        }
        file << getDateFormatted() << ";" << sensor << ";" << message << std::endl;
        file.close();
    }else{
        std::cerr << "Unable to open file" << std::endl;
    }
}

bool Server::isFileEmpty() {
    std::ifstream file("log.csv");
    return file.peek() == std::ifstream::traits_type::eof();
}


