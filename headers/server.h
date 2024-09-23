//
// Created by arnaud on 16 Sep 2024.
//

#ifndef PROJET_SERVER_H
#define PROJET_SERVER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


class Server{
public:
    // Coplien architecture
    Server();
    Server(const Server& server);
    ~Server();
    Server& operator=(const Server&);


    // Overrides
    friend std::ostream &operator<<(Server& server, const std::string& content);

    // Getter and setters
    const std::string& getOutput();
    void setOutput(const std::string &_outputfile);
    void setOutput();

    // Static methods of output
    static void consoleWrite(const std::string& string);
    static void fileWrite(const std::string& content, const std::string& filename);

    static std::string getFormatedDate();

private:
    //Attributes
    std::string outputfile;
};
#endif //PROJET_SERVER_H
