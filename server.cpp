//
// Created by arnaud on 16 Sep 2024.
//

#include "server.h"

Server::Server() {
    outputfile = "0";
}

Server::Server(const Server &server) {
    outputfile = server.getOutput();
}

Server::~Server() = default;

void Server::consoleWrite(const std::string& string) {
    std::cout << "Hello world" << std::endl;
}

void Server::fileWrite(const std::string& content, const std::string& filename) {
    std::ofstream file("logs/" + filename + ".log");
    if (file){
        file << content << std::endl;
    }
    file.close();
}

std::ostream &operator<<(Server& server, const std::string& content) {
    if (server.getOutput() == "0") {
        Server::consoleWrite(content);
    } else {
        Server::fileWrite(content, server.getOutput());
    }
    return std::cout;
}

const std::string &Server::getOutput() const {
    return outputfile;
}

void Server::setOutput(const std::string &outputfile) {
    Server::outputfile = outputfile;
}

void Server::setOutput() {
    Server::outputfile = "0";
}