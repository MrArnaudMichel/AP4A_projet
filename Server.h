//
// Created by arnaud on 14/10/24.
//

#ifndef SERVER_H
#define SERVER_H
#include "Sensors/Sensor.h"
#include <iostream>

// links of the github gist of the snippets: https://gist.github.com/Kielx/2917687bc30f567d45e15a4577772b02
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class Sensor;
class Server {
private:
    int uptime = 0;
public:
    //////////////////////////////
    /// Coplien architecture /////
    //////////////////////////////
    Server() = default;
    Server(const Server &server) = default;
    virtual ~Server() = default;
    Server &operator=(const Server &server) = default;

    void update();

    void notify(const Sensor &sensor, const std::string &filepath, const std::string &message);

    static std::string getDateFormatted();

    void log(const Sensor & sensor, const std::string & message);
    void logInFile(const Sensor & sensor, const std::string & filepath, const std::string & message);

    bool isFileEmpty(const std::string & filepath);

    void resume();
};



#endif //SERVER_H
