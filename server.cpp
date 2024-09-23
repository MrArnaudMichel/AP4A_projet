//
// Created by arnaud on 16 Sep 2024.
//

#include "server.h"

Server::Server() {
    outputfile = "";
}

Server::Server(const Server &server) {
    outputfile = server.outputfile;
}

Server::~Server() = default;

Server &Server::operator=(const Server &) = default;

std::ostream &operator<<(Server& server, const std::string& content) {
    if (server.getOutput().empty()) {
        Server::consoleWrite(content);
    } else {
        Server::fileWrite(content, server.getOutput());
    }
    return std::cout;
}

const std::string &Server::getOutput() {
    return outputfile;
}

void Server::setOutput(const std::string &_outputfile) {
    Server::outputfile = _outputfile;
}

void Server::setOutput() {
    Server::outputfile = "";
}

void Server::consoleWrite(const std::string& string) {
    std::cout << string << std::endl;
}

void Server::fileWrite(const std::string& content, const std::string& filename) {
    std::ofstream file("logs/" + filename + ".log");
    if (file){
        file << content << std::endl;
    }
    file.close();
}
