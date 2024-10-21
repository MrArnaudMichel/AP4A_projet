//
// Created by arnaud on 21/10/24.
//

#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <ostream>


template <class T>
class Data {
private:
    T value;
public:
    Data() = default;
    explicit Data(const T &value) : value(value) {}
    ~Data() = default;
    Data &operator=(const Data &data) = default;

    T getValue() const {
        return value;
    }
    void setValue(const T &value) {
        this->value = value;
    }

    std::ostream & toString() const {
        return std::cout << "Data: " << value << std::endl;
    }

    friend std::ostream & operator<<(std::ostream &os, const Data &obj) {
        return os << "value: " << obj.value;
    }
};



#endif //DATA_H
