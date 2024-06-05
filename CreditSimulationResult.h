//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_CREDITSIMULATIONRESULT_H
#define LABS_KREDIT_MOTOR_CREDITSIMULATIONRESULT_H


#include "Customer.h"
#include "Product.h"

class CreditSimulationResult {
public:
    CreditSimulationResult(
        Customer* customer,
        Product* product,
        Tenor* tenor,
        double downPayment,
        double interest,
        double finalPrice,
        double repaymentValue,
        double paymentPerMonth
    );
    Customer* getCustomer();
    Product* getProduct();
    Tenor* getTenor();
    double getDownPayment();
    double getInterest();
    double getFinalPrice();
    double getRepaymentValue();
    double getPaymentPerMonth();
    ~CreditSimulationResult() {
        delete customer;
        delete product;
        delete tenor;
    }
private:
    Customer* customer;
    Product* product;
    Tenor* tenor;
    double downPayment;
    double interest;
    double finalPrice;
    double repaymentValue;
    double paymentPerMonth;
};


#endif //LABS_KREDIT_MOTOR_CREDITSIMULATIONRESULT_H
