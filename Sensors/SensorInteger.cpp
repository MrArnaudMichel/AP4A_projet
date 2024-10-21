//
// Created by arnaud on 21/10/24.
//

#include "SensorInteger.h"

#include <set>

void SensorInteger::execute() {
    setValue(rand()%100);
    Server::notify(*this, "sound");
}
