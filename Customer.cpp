//
// Created by Bunga Mungil on 05/06/24.
//

#include "Customer.h"

Customer::Customer(
        const std::string &customerName,
        const std::string &customerAddress,
        const std::string &customerEmail,
        const std::string &customerPhoneNumber
        ) {
    this->name = customerName;
    this->address = customerAddress;
    this->email = customerEmail;
    this->phoneNumber = customerPhoneNumber;
}

const string& Customer::getName() const {
    return this->name;
}

const string& Customer::getAddress() const {
    return this->address;
}

const string& Customer::getEmail() const {
    return this->email;
}

const string& Customer::getPhoneNumber() const {
    return this->phoneNumber;
}
