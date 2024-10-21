//
// Created by arnaud on 21/10/24.
//

#include "SensorFloat.h"

void SensorFloat::execute() {
    std::random_device rd;
    std::mt19937 re(rd());
    std::normal_distribution<float> distribution(15.0, 5.0);
    setValue(distribution(re));
    server->notify(*this, "environment", "Nouvelle valeur d'environement");
}

void SensorFloat::display(std::ostream &os) const {
    Sensor::display(os);
    os << *this;
}

std::ostream & operator<<(std::ostream &os, const SensorFloat &obj) {
    return os << static_cast<const Data<float> &>(obj);
}
