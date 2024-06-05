cmake_minimum_required(VERSION 3.28)
project(labs_kredit_motor)

set(CMAKE_CXX_STANDARD 17)

add_executable(labs_kredit_motor main.cpp
        Customer.cpp
        Customer.h
        Product.cpp
        Product.h
        Payment.cpp
        Payment.h
        Tenor.cpp
        Tenor.h
        CreditSimulator.cpp
        CreditSimulator.h
        CustomerRepository.h
        ProductRepository.h
        DemoCustomerRepository.cpp
        DemoCustomerRepository.h
        DemoProductRepository.cpp
        DemoProductRepository.h
)
