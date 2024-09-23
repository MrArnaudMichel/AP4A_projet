//
// Created by arnaud on 23 Sep 2024.
//

#include <sstream>
#include "sensor.h"

Sensor::Sensor() {
    this->id = "0";
    this->duree = 2;
    this->defaultType = "float";
    this->data = 0;
    this->server = nullptr;
}

Sensor::Sensor(const Sensor &s) {
    this->id = s.id;
    this->duree = s.duree;
    this->defaultType = s.defaultType;
    this->data = s.data;
    this->server = s.server;
}

Sensor::~Sensor() {
    delete this->server;
}

void Sensor::update() {
    // simuler une mesure toute les x secondes
    if (duree == 0) {
        execute();
        duree = 2;
        return;
    }
    duree--;
}

void Sensor::execute() {
    this->data = (int)random() % 10;
    if (server){
        std::ostringstream oss;
        oss << *this;  // Use the overloaded '<<' operator to convert to string
        server->consoleWrite(oss.str());
        return;
    }
    std::cout << "On envoie sur le serveur" << this << std::endl;

}

Sensor::Sensor(const string &id, const string &defaultType, int duree, Server *server) : id(id),
                                                                                         defaultType(defaultType),
                                                                                         duree(duree), server(server) {}

ostream &operator<<(ostream &os, const Sensor &sensor) {
    os << "id: " << sensor.id << " defaultType: " << sensor.defaultType << " data: " << sensor.data;
    return os;
}
