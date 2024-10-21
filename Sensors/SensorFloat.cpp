//
// Created by arnaud on 21/10/24.
//

#include "SensorFloat.h"

void SensorFloat::execute() {
    setValue(((float)(rand() % 100) - 50) / 5);
    Server::notify(*this, "environment", "Nouvelle valeur d'environement");
}
