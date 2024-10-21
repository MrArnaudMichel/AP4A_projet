//
// Created by arnaud on 21/10/24.
//

#include "SensorFloat.h"

/**
 * Execute the sensor (override) and notify the server
 */
void SensorFloat::execute() {
    std::random_device rd;
    std::mt19937 re(rd());
    std::normal_distribution<float> distribution(15.0, 5.0);
    setValue(distribution(re));
    server->notify(*this, "environment", "Nouvelle valeur d'environement");
}

/**
 * display the sensor (override)
 * @param os output stream
 */
void SensorFloat::display(std::ostream &os) const {
    Sensor::display(os);
    os << *this;
}

/**
 * Display the sensor with the << operator
 * @param os output stream
 * @param obj sensor to display
 * @return the output stream
 */
std::ostream & operator<<(std::ostream &os, const SensorFloat &obj) {
    return os << static_cast<const Data<float> &>(obj);
}
