//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_CREDITSIMULATOR_H
#define LABS_KREDIT_MOTOR_CREDITSIMULATOR_H

#include <string>
#include "Customer.h"
#include "Product.h"
using namespace std;

class CreditSimulator {
public:
    void run();
private:
    void printHeader();
    string readUserInput(const string& prompt);
    Product askUserToChooseMotorcycle();
    void calculatePaymentTerms(
            Product* product,
            double* interest,
            double* finalPrice,
            double* debt,
            double* paymentPerMonth
    );
    Tenor askUserToChooseTenor(const Payment* payment);
    double askUserToInputDownPayment(double minimal);
    void printPaymentSteps(Customer* customer, double debt, double paymentPerMonth);
};


#endif //LABS_KREDIT_MOTOR_CREDITSIMULATOR_H
