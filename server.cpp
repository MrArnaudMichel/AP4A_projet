//
// Created by arnaud on 16 Sep 2024.
//

#include <sstream>
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
    std::cout << string << " - " << Server::getFormatedDate() << std::endl;
}

void Server::fileWrite(const std::string& content, const std::string& filename) {
    std::ofstream file("logs/" + filename + ".log");

    if (file){
        file << content << "-" << Server::getFormatedDate() << std::endl;
    }
    file.close();
}

std::string Server::getFormatedDate() {
    // Get the current time
    time_t now = time(nullptr);
    // Convert it to local time
    tm *ltm = localtime(&now);

    // Create a string stream to format the date and time
    std::ostringstream oss;

    // Format the date and time
    oss << ltm->tm_mday << "/"
        << 1 + ltm->tm_mon << "/"
        << 1900 + ltm->tm_year << "-"
        << (ltm->tm_hour) % 24 << ":"
        << (ltm->tm_min) % 60 << ":"
        << ltm->tm_sec;

    // Return the formatted string
    return oss.str();
}
