//
// Created by arnaud on 21/10/24.
//

#include "SensorInteger.h"

#include <set>

void SensorInteger::execute() {
    setValue(rand()%100);
    server->notify(*this, "sound", "Mise a jour du son");
}

void SensorInteger::display(std::ostream &os) const  {
    Sensor::display(os);
    os << *this;
}

std::ostream & operator<<(std::ostream &os, const SensorInteger &obj) {
    return os << static_cast<const Data<int> &>(obj);
}
