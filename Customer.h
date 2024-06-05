//
// Created by Bunga Mungil on 05/06/24.
//

#ifndef LABS_KREDIT_MOTOR_CUSTOMER_H
#define LABS_KREDIT_MOTOR_CUSTOMER_H

#include <string>
using namespace std;

class Customer {
public:
    Customer(
            const string& customerName,
            const string& customerAddress,
            const string& customerEmail,
            const string& customerPhoneNumber);
    const string& getName() const;
    const string& getAddress() const;
    const string& getEmail() const;
    const string& getPhoneNumber() const;
private:
    string name;
    string address;
    string email;
    string phoneNumber;
};


#endif //LABS_KREDIT_MOTOR_CUSTOMER_H
