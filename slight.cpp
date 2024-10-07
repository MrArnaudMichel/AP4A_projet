//
// Created by arnaud on 07/10/24.
//

#include "slight.h"

Slight::~Slight() {
    delete data;
    delete server_;
}

inline void Slight::update() {
    Sensor<bool>::update();
}

void Slight::execute() {
    this->data->set_value(rand() % 2);
}
