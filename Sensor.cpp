//
// Created by arnaud on 07/10/24.
//

#include "Sensor.h"

template<class T>
void Sensor<T>::update() {
    // simuler une mesure toute les x secondes
    if (timeRemaining == 0) {
        execute();
        timeRemaining = timeToUpdate;
        return;
    }
    timeRemaining--;
}

template<class T>
void Sensor<T>::sendData() {
    if (server_){
        std::ostringstream oss;
        oss << *this;
        // server->consoleWrite(oss.str());
        server_->getData(*this);
    }else {
        std::cerr << "Server is NULL" << std::endl;
    }
}
