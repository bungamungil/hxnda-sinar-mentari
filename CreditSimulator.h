//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_CREDITSIMULATOR_H
#define LABS_KREDIT_MOTOR_CREDITSIMULATOR_H

#include <string>
#include "CustomerRepository.h"
#include "ProductRepository.h"
using namespace std;

class CreditSimulator {
public:
    CreditSimulator(CustomerRepository* customerRepository, ProductRepository* productRepository);
    void run();
    ~CreditSimulator() {
        delete customerRepository;
        delete productRepository;
    }
private:
    CustomerRepository* customerRepository;
    ProductRepository* productRepository;
    static void printHeader();
    static string readUserInput(const string& prompt);
    static Product* askUserToChooseMotorcycle(vector<Product>* products);
    static void calculatePaymentTerms(
            Product* product,
            double* interest,
            double* finalPrice,
            double* debt,
            double* paymentPerMonth
    );
    static Tenor askUserToChooseTenor(const Payment* payment);
    static double askUserToInputDownPayment(double minimal);
    static void printPaymentSteps(Customer* customer, double debt, double paymentPerMonth);
};


#endif //LABS_KREDIT_MOTOR_CREDITSIMULATOR_H
