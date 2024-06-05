#include "CreditSimulator.h"
#include "DemoCustomerRepository.h"
#include "DemoProductRepository.h"

int main() {
    CustomerRepository* customerRepository = new DemoCustomerRepository();
    ProductRepository* productRepository = new DemoProductRepository();
    CreditSimulator simulator = CreditSimulator(customerRepository, productRepository);
    simulator.run();
    return 0;
}
