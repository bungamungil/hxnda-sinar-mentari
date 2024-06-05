//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_CREDITSIMULATOR_H
#define LABS_KREDIT_MOTOR_CREDITSIMULATOR_H

#include "CustomerRepository.h"
#include "ProductRepository.h"
#include "UserInterface.h"
using namespace std;

class CreditSimulator {
public:
    CreditSimulator(
        CustomerRepository* customerRepository,
        ProductRepository* productRepository,
        UserInterface* userInterface
    );
    void run();
    ~CreditSimulator() {
        delete customerRepository;
        delete productRepository;
        delete userInterface;
    }
private:
    CustomerRepository* customerRepository;
    ProductRepository* productRepository;
    UserInterface* userInterface;
};


#endif //LABS_KREDIT_MOTOR_CREDITSIMULATOR_H
