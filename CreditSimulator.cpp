//
// Created by Bunga Mungil on 05/06/24.
//

#include "CreditSimulator.h"

CreditSimulator::CreditSimulator(
    CustomerRepository* customerRepository,
    ProductRepository* productRepository,
    UserInterface* userInterface
) {
    this->customerRepository = customerRepository;
    this->productRepository = productRepository;
    this->userInterface = userInterface;
}

void CreditSimulator::run() {
    this->userInterface->start();
    auto* customer = this->userInterface->askCustomerInformation();
    this->customerRepository->store(customer);
    auto* products = this->productRepository->fetch();
    auto* selectedProduct = this->userInterface->askCustomerToChooseProduct(products);
    auto downPayment = this->userInterface->askCustomerToInputDownPayment(selectedProduct);
    auto* selectedTenor = this->userInterface->askCustomerToChooseTenor(selectedProduct);
    double interest = selectedProduct->getPrice() * selectedTenor->getPercentageInterest() / 100;
    double finalPrice = selectedProduct->getPrice() + interest;
    double repaymentValue = finalPrice - downPayment;
    double paymentPerMonth = repaymentValue / selectedTenor->getMonth();
    this->userInterface->showCreditSimulationResult(customer, selectedProduct, selectedTenor, downPayment, interest, finalPrice, repaymentValue, paymentPerMonth);
}
