//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_DEMOCUSTOMERREPOSITORY_H
#define LABS_KREDIT_MOTOR_DEMOCUSTOMERREPOSITORY_H


#include "CustomerRepository.h"

class DemoCustomerRepository: public CustomerRepository {
    bool store(Customer *customer) override;
};


#endif //LABS_KREDIT_MOTOR_DEMOCUSTOMERREPOSITORY_H
