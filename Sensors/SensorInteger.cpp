//
// Created by arnaud on 21/10/24.
//

#include "SensorInteger.h"

#include <set>

/**
 * Execute the sensor (override) and notify the server
 */
void SensorInteger::execute() {
    setValue(rand()%100);
    server->notify(*this, "sound", "Mise a jour du son");
}

/**
 * Display the sensor (override)
 * @param os output stream
 */
void SensorInteger::display(std::ostream &os) const  {
    Sensor::display(os);
    os << *this;
}

/**
 * Display the sensor with the << operator
 * @param os output stream
 * @param obj sensor to display
 * @return the output stream
 */
std::ostream & operator<<(std::ostream &os, const SensorInteger &obj) {
    return os << static_cast<const Data<int> &>(obj);
}
