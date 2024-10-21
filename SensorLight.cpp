//
// Created by arnaud on 21/10/24.
//

#include "SensorLight.h"

void SensorLight::execute() {
    setValue(rand()%2);
    server->notify(*this);
}
