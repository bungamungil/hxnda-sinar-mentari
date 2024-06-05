//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_PAYMENT_H
#define LABS_KREDIT_MOTOR_PAYMENT_H

#include <vector>
#include "Tenor.h"
using namespace std;

class Payment {
public:
    Payment(const double& minimumDownPayment, const vector<Tenor>& tenors);
    const double& getMinimumDownPayment() const;
    const vector<Tenor>& getTenors() const;
private:
    double minimumDownPayment;
    vector<Tenor> tenors;
};


#endif //LABS_KREDIT_MOTOR_PAYMENT_H
