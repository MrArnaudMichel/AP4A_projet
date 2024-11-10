//
// Created by arnaud on 21/10/24.
//

#include "SensorBool.h"

/**
 * Execute the sensor (override) and notify the server
 */
void SensorBool::execute() {
    setValue(rand()%2);
    server->notify(*this, "Récupération de la lumière");
}

/**
 * Display the sensor (override)
 * @param os output stream
 */
void SensorBool::display(std::ostream &os) const  {
    Sensor::display(os);
    os << *this;
}

/**
 * Display the sensor with the << operator
 * @param os output stream
 * @param obj sensor to display
 * @return the output stream
 */
std::ostream & operator<<(std::ostream &os, const SensorBool &obj)  {
    return os << static_cast<const Data<bool> &>(obj);
}
