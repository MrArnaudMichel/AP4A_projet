//
// Created by arnaud on 16 Sep 2024.
//

#ifndef PROJET_SERVER_H
#define PROJET_SERVER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


class Server{
public:
    // Coplien architecture
    Server();
    Server(const Server& server);
    ~Server();
    Server& operator=(const Server&);


    // Overrides
    friend ostream &operator<<(Server& server, const string& content);

    // Getter and setters
    const string& getOutput();
    void setOutput(const string &_outputfile);
    void setOutput();

    // Static methods of output
    static void consoleWrite(const string& string);
    static void fileWrite(const string& content, const string& filename);

    static string getFormatedDate();

private:
    //Attributes
    string outputfile;
};
#endif //PROJET_SERVER_H
