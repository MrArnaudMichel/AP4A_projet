//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

int main() {
    Server server;
    Sensor sensor(&server, 10);
    std::cout << sensor << std::endl;
}
