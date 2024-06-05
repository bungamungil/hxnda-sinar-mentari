//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_DEMOPRODUCTREPOSITORY_H
#define LABS_KREDIT_MOTOR_DEMOPRODUCTREPOSITORY_H


#include "ProductRepository.h"

class DemoProductRepository: public ProductRepository {
    vector<Product>* fetch() override;
};


#endif //LABS_KREDIT_MOTOR_DEMOPRODUCTREPOSITORY_H
