//
// Created by arnaud on 21/10/24.
//

#include "SensorFloat.h"

void SensorFloat::execute() {
    setValue(((float)(rand() % 100) - 50) / 5);
    Server::notify(*this, "environment", "Nouvelle valeur d'environement");
}

void SensorFloat::display(std::ostream &os) const {
    Sensor::display(os);
    os << *this;
}

std::ostream & operator<<(std::ostream &os, const SensorFloat &obj) {
    return os << static_cast<const Data<float> &>(obj);
}
