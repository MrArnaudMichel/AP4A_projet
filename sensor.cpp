//
// Created by arnaud on 23 Sep 2024.
//

#include "sensor.h"

Sensor::Sensor() {

}

Sensor::Sensor(const Sensor &s) {
    Sensor::id = Sensor::getId();
    this->data = s.getData();
    this->defaultType = s.getDefaultType();
    this->server = s.server; // Car le serveur est commun a tout les sensors
}

Sensor::~Sensor() {
    delete this->server;
}

void Sensor::update() {

}

void Sensor::execute() {

}

const string &Sensor::getId() {
    return id;
}

void Sensor::setId(const string &id) {
    Sensor::id = id;
}

const string &Sensor::getDefaultType() const {
    return defaultType;
}

void Sensor::setDefaultType(const string &defaultType) {
    Sensor::defaultType = defaultType;
}

float Sensor::getData() const {
    return data;
}

void Sensor::setData(float data) {
    Sensor::data = data;
}

Server *Sensor::getServer() const {
    return server;
}

void Sensor::setServer(Server *server) {
    Sensor::server = server;
}
