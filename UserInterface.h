//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_USERINTERFACE_H
#define LABS_KREDIT_MOTOR_USERINTERFACE_H


#include "Customer.h"
#include "Product.h"
#include "CreditSimulationResult.h"

class UserInterface {
public:
    virtual void start() = 0;
    virtual Customer* askCustomerInformation() = 0;
    virtual Product* askCustomerToChooseProduct(vector<Product>* products) = 0;
    virtual double askCustomerToInputDownPayment(Product* product) = 0;
    virtual Tenor* askCustomerToChooseTenor(Product* product) = 0;
    virtual void showCreditSimulationResult(CreditSimulationResult* result) = 0;
    virtual ~UserInterface() = default;
};


#endif //LABS_KREDIT_MOTOR_USERINTERFACE_H
