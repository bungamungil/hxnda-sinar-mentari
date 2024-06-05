//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_PRODUCT_H
#define LABS_KREDIT_MOTOR_PRODUCT_H

#include <string>
using namespace std;

class Product {
public:
    Product(const string& productName, const double& price);
    const string& getName() const;
    const double& getPrice() const;
private:
    string name;
    double price;
};


#endif //LABS_KREDIT_MOTOR_PRODUCT_H
