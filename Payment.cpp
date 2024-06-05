//
// Created by Bunga Mungil on 05/06/24.
//

#include "Payment.h"

Payment::Payment(const double& minimumDownPayment, const vector<Tenor>& tenors) {
    this->minimumDownPayment = minimumDownPayment;
    this->tenors = tenors;
}

const double& Payment::getMinimumDownPayment() const {
    return this->minimumDownPayment;
}

const vector<Tenor>& Payment::getTenors() const {
    return this->tenors;
}
