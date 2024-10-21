//
// Created by arnaud on 21/10/24.
//

#ifndef DATA_H
#define DATA_H
#include <iostream>


template <class T>
class Data {
private:
    T value;
protected:
    T getValue() const {
        return value;
    }
    void setValue(const T &value) {
        this->value = value;
    }
public:
    //////////////////////////////
    /// Coplien architecture /////
    //////////////////////////////
    Data() = default;
    explicit Data(const T &value) : value(value) {}
    ~Data() = default;
    Data &operator=(const Data &data) = default;



    friend std::ostream & operator<<(std::ostream &os, const Data &obj) {
        return os << obj.value;
    }
};



#endif //DATA_H
