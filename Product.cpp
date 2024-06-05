//
// Created by Bunga Mungil on 05/06/24.
//

#include "Product.h"

Product::Product(const string& productName, const double& price, const Payment& payment): payment(payment) {
    this->name = productName;
    this->price = price;
}

const string& Product::getName() const {
    return this->name;
}

const double& Product::getPrice() const {
    return this->price;
}

const Payment& Product::getPayment() const {
    return this->payment;
}
