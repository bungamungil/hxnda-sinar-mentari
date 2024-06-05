//
// Created by Bunga Mungil on 05/06/24.
//

#include "Product.h"

Product::Product(const std::string& productName, const double& price) {
    this->name = productName;
    this->price = price;
}

const string& Product::getName() const {
    return this->name;
}

const double& Product::getPrice() const {
    return this->price;
}
