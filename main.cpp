//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

int main() {
    Server server;
    Sensor sensor(&server, 10);
    Sensor sensor2(sensor);
    Sensor sensor3;

    std::cout << sensor << std::endl;
    std::cout << sensor2 << std::endl;
    std::cout << sensor3 << std::endl;

}
