//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_SIMPLECOMMANDLINEINTERFACE_H
#define LABS_KREDIT_MOTOR_SIMPLECOMMANDLINEINTERFACE_H


#include "UserInterface.h"

class SimpleCommandLineInterface: public UserInterface {
public:
    void start() override;
    Customer* askCustomerInformation() override;
    Product* askCustomerToChooseProduct(vector<Product>* products) override;
    double askCustomerToInputDownPayment(Product* product) override;
    Tenor* askCustomerToChooseTenor(Product* product) override;
    void showCreditSimulationResult(
            Customer* customer,
            Product* product,
            Tenor* tenor,
            double downPayment,
            double interest,
            double finalPrice,
            double repaymentValue,
            double paymentPerMonth
    ) override;
private:
    static string readUserInput(const string& prompt);
};


#endif //LABS_KREDIT_MOTOR_SIMPLECOMMANDLINEINTERFACE_H
