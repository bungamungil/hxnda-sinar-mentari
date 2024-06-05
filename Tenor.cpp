//
// Created by Bunga Mungil on 05/06/24.
//

#include "Tenor.h"

Tenor::Tenor(const int& month, const int& percentageInterest) {
    this->month = month;
    this->percentageInterest = percentageInterest;
}

const int& Tenor::getMonth() const {
    return this->month;
}

const int& Tenor::getPercentageInterest() const {
    return this->percentageInterest;
}
