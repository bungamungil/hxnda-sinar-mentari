//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_CUSTOMERREPOSITORY_H
#define LABS_KREDIT_MOTOR_CUSTOMERREPOSITORY_H


#include "Customer.h"

class CustomerRepository {
public:
    virtual bool store(Customer* customer) = 0;
    virtual ~CustomerRepository() = default;
};


#endif //LABS_KREDIT_MOTOR_CUSTOMERREPOSITORY_H
