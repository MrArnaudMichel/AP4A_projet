//
// Created by arnaud on 16 Sep 2024.
//

#include <sstream>
#include "server.h"

#include "sensortemp.h"

Server::Server() {
    outputfile = "";
}

Server::Server(const Server &server) {
    outputfile = server.outputfile;
}

Server::~Server() = default;

Server &Server::operator=(const Server &) = default;

ostream &operator<<(Server &server, const string &content) {
    if (server.getOutput().empty()) {
        server.consoleWrite(content);
    } else {
        server.fileWrite(content, server.getOutput());
    }
    return cout;
}

const string &Server::getOutput() {
    return outputfile;
}

void Server::setOutput(const string &_outputfile) {
    outputfile = _outputfile;
}

void Server::setOutput() {
    outputfile = "";
}

void Server::consoleWrite(const string &string) {
    cout << string  << endl;
}

void Server::fileWrite(const string &content, const string &filename) {
    ofstream file("../logs/" + filename + ".csv");

    if (file) {
        file << content << "-" << getFormatedDate() << endl;
    }
    else {
        cerr << "Unable to open file " << filename << endl;
    }
    file.close();
}

string Server::getFormatedDate() {
    // Get the current time
    time_t now = time(nullptr);
    // Convert it to local time
    tm *ltm = localtime(&now);

    // Create a string stream to format the date and time
    ostringstream oss;

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

void Server::getData(Sensor &s) {
    ostringstream oss;
    oss << "=======================\n"
        << "Id: " << s.getId()
        << "\nValue: " << s.getData()
        << "\nDate: " << getFormatedDate() << std::endl;
    consoleWrite(oss.str());
    fileWrite(oss.str(), "test");
}
