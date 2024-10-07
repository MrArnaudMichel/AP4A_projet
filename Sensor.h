//
// Created by arnaud on 07/10/24.
//

#ifndef SENSOR_H
#define SENSOR_H
#include "data.h"
#include "server.h"


template <class T> class Sensor {
    int timeRemaining;
protected:
    int id;
    Data<T>*data;
    Server* server_;

    int timeToUpdate;
public:
    /**
     * Forme Canonique de Coplien
     */
    Sensor(): id(0), data(), server_(), timeToUpdate(0), timeRemaining(0){};
    Sensor(const Sensor &other)
        : id(other.id),
          data(other.data),
          server_(other.server_),
          timeToUpdate(other.timeToUpdate),
          timeRemaining(other.timeRemaining) {
    }
    Sensor & operator=(const Sensor &other) {
        if (this == &other)
            return *this;
        id = other.id;
        data = other.data;
        server_ = other.server_;
        timeToUpdate = other.timeToUpdate;
        timeRemaining = other.timeRemaining;
        return *this;
    }

    virtual ~Sensor() {
        delete data;
        delete server_;
    }

    virtual void update();
    virtual void execute();
    void sendData();

    void test(){};
};


#endif //SENSOR_H
