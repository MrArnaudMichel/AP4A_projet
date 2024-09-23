//
// Created by arnaud on 23 Sep 2024.
//

#ifndef AP4A_PROJET_SENSOR_H
#define AP4A_PROJET_SENSOR_H

#include <string>
#include "server.h"

class Sensor{
private:
    static std::string id;
    std::string defaultType;
    float data;

    Server* server;

public:
    Sensor();
    Sensor(const Sensor& s);

    virtual ~Sensor();

    void update();
    void execute();

    static const string &getId();
    static void setId(const string &id);

    const string &getDefaultType() const;
    void setDefaultType(const string &defaultType);

    float getData() const;
    void setData(float data);

    Server& getServer() const;
    void setServer(Server *server);


};

#endif //AP4A_PROJET_SENSOR_H
