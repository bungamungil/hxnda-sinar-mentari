//
// Created by Bunga Mungil on 05/06/24.
//

#include "DemoProductRepository.h"

vector<Product>* DemoProductRepository::fetch() {
    // Todo: In real world app, this function could call data from DB or Rest API
    double defaultDownPayment = 500'000;
    auto defaultTenors = vector<Tenor>();
    defaultTenors.push_back(Tenor(12, 10));
    defaultTenors.push_back(Tenor(24, 20));
    defaultTenors.push_back(Tenor(36, 30));
    auto defaultPayment = Payment(defaultDownPayment, defaultTenors);
    double promoDownPayment = 250'000;
    auto promoTenors = vector<Tenor>();
    promoTenors.push_back(Tenor(12, 5));
    promoTenors.push_back(Tenor(24, 15));
    promoTenors.push_back(Tenor(36, 25));
    auto promoPayment = Payment(promoDownPayment, promoTenors);
    vector<Product>* products = new vector<Product>();
    products->push_back(Product("Beat CBS", 17'700'000, defaultPayment));
    products->push_back(Product("Scoopy", 20'600'000, defaultPayment));
    products->push_back(Product("Vario 150", 24'800'000, promoPayment));
    products->push_back(Product("Supra GTR", 24'600'000, defaultPayment));
    products->push_back(Product("Genio CBS PLUS", 18'750'000, defaultPayment));
    return products;
}
