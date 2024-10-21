//
// Created by arnaud on 14/10/24.
//

#include "Server.h"

#include <fstream>

void Server::notify(const Sensor &sensor, const std::string & filepath) {
    logOnFile(sensor, filepath, "Sensor value updated");
    log(sensor, "Sensor value updated");
}

std::string Server::getDateFormatted()  {
    time_t rawtime;
    tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y;%H:%M:%S",timeinfo);
    std::string str(buffer);

    return str;
}

void Server::log(const Sensor &sensor, const std::string &message) {
    std::cout << "\033[1;35mDate: " << getDateFormatted() << " - "
    << "\033[1;33mSensor(id;type;value): ";
    std::cout << sensor << " - ";
    std::cout << " \033[1;36mMessage: " << message << std::endl;
}


void Server::logOnFile(const Sensor &sensor, const std::string & filepath, const std::string &message) {
    std::string filename = filepath + ".csv";
    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {
        if (isFileEmpty(filename)) {
            file << "Date;Hour;SensorId;SensorType;SensorValue;Message" << std::endl;
            std::cout << "\033[1;32m" << filename + " created at " << __FILE__ << "\033[0m" << std::endl;
        }
        file << getDateFormatted() << ";";
        file << sensor << ";" << message << std::endl;
        file.close();
    }else{
        std::cerr << "Unable to open file" << std::endl;
    }
}

bool Server::isFileEmpty(const std::string & filepath) {
    std::ifstream file(filepath);
    return file.peek() == std::ifstream::traits_type::eof();
}


