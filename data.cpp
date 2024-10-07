//
// Created by arnaud on 23 Sep 2024.
//

#include "data.h"

template<class T> Data<T> & Data<T>::operator=(const Data<T> &other) {
    Data<T> temp(other);
    swap(*this, temp);
    return *this;
}
