//
// Created by arnaud on 16 Sep 2024.
//

#include "main.h"

int main(){
    Server server = Server();
    server << "Hello world";
    server.setOutput("default");
    server << "Hello World1";
    return 0;
}