//
// Created by arnaud on 23 Sep 2024.
//

#include <sstream>
#include <utility>
#include "sensortemp.h"

Sensor::Sensor() {
    this->id = "0";
    this->duree = 2;
    this->data = 0;
    this->server = nullptr;
    this->timeRemain = duree;
}

Sensor::Sensor(const Sensor &s) {
    this->id = s.id;
    this->duree = s.duree;
    this->data = s.data;
    this->server = s.server;
    this->timeRemain = duree;

}

Sensor::~Sensor() {
    delete this->server;
}

void Sensor::update() {
    // simuler une mesure toute les x secondes
    if (timeRemain == 0) {
        execute();
        timeRemain = duree;
        return;
    }
    timeRemain--;
}

void Sensor::execute() {
    this->data = rand() % 255;
    if (server){
        std::ostringstream oss;
        oss << *this;  // Use the overloaded '<<' operator to convert to string
        // server->consoleWrite(oss.str());
        server->getData(*this);
//        TODO: Il faudra envoye l'objet sur le serveur
        return;
    }
    std::cout << "On envoie sur le serveur" << this << std::endl;

}

string Sensor::getId() {
    return id;
}

float Sensor::getData() const {
    return data;
}


Sensor::Sensor(string id, int duree, Server *server) : id(std::move(id)),
                                                                           server(server), duree(duree) {
    this->timeRemain = duree;
}

ostream &operator<<(ostream &os, const Sensor &sensor) {
    os << "id: " << sensor.id << " data: " << sensor.data;
    return os;
}
