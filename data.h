//
// Created by arnaud on 23 Sep 2024.
//

#ifndef AP4A_PROJET_DATA_H
#define AP4A_PROJET_DATA_H
#include <ostream>

template <class T> class Data {
private:
    T value;
    char* name;
public:
    Data(): value(0), name(nullptr) {}
    Data(const Data<T>& other): value(other.value), name(other.name) {}
    ~Data() {
        delete name;
    }
    Data<T>& operator=(const Data<T>& other);

    explicit Data(const T &value)
        : value(value) {
    }

    friend std::ostream & operator<<(std::ostream &os, const Data &obj) {
        return os
               << obj.value
               << ";" << obj.name;
    }
};

#endif //AP4A_PROJET_DATA_H
