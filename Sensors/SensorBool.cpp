//
// Created by arnaud on 21/10/24.
//

#include "SensorBool.h"

void SensorBool::execute() {
    setValue(rand()%2);
    Server::notify(*this, "light", "Récupération de la lumière");
}

void SensorBool::display(std::ostream &os) const  {
    Sensor::display(os);
    os << *this;
}

std::ostream & operator<<(std::ostream &os, const SensorBool &obj)  {
    return os << static_cast<const Data<bool> &>(obj);
}
