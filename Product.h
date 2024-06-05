//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_PRODUCT_H
#define LABS_KREDIT_MOTOR_PRODUCT_H

#include <string>
#include "Payment.h"
using namespace std;

class Product {
public:
    Product(const string& productName, const double& price, const Payment& payment);
    const string& getName() const;
    const double& getPrice() const;
    const Payment& getPayment() const;
private:
    string name;
    double price;
    Payment payment;
};


#endif //LABS_KREDIT_MOTOR_PRODUCT_H
