//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_PRODUCTREPOSITORY_H
#define LABS_KREDIT_MOTOR_PRODUCTREPOSITORY_H


#include "Product.h"

class ProductRepository {
public:
    virtual vector<Product>* fetch() = 0;
    virtual ~ProductRepository() = default;
};


#endif //LABS_KREDIT_MOTOR_PRODUCTREPOSITORY_H
