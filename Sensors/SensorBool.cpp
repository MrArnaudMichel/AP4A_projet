//
// Created by arnaud on 21/10/24.
//

#include "SensorBool.h"

void SensorBool::execute() {
    setValue(rand()%2);
    Server::notify(*this, "light");
}
