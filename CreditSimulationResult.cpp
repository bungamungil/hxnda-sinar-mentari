//
// Created by Bunga Mungil on 05/06/24.
//

#include "CreditSimulationResult.h"

CreditSimulationResult::CreditSimulationResult(
    Customer *customer,
    Product *product,
    Tenor *tenor,
    double downPayment,
    double interest,
    double finalPrice,
    double repaymentValue,
    double paymentPerMonth
) {
    this->customer = customer;
    this->product = product;
    this->tenor = tenor;
    this->downPayment = downPayment;
    this->interest = interest;
    this->finalPrice = finalPrice;
    this->repaymentValue = repaymentValue;
    this->paymentPerMonth = paymentPerMonth;
}

Customer *CreditSimulationResult::getCustomer() {
    return this->customer;
}

Product *CreditSimulationResult::getProduct() {
    return this->product;
}

Tenor *CreditSimulationResult::getTenor() {
    return this->tenor;
}

double CreditSimulationResult::getDownPayment() {
    return this->downPayment;
}

double CreditSimulationResult::getInterest() {
    return this->interest;
}

double CreditSimulationResult::getFinalPrice() {
    return this->finalPrice;
}

double CreditSimulationResult::getRepaymentValue() {
    return this->repaymentValue;
}

double CreditSimulationResult::getPaymentPerMonth() {
    return this->paymentPerMonth;
}
