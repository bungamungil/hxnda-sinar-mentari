#include "CreditSimulator.h"
#include "DemoCustomerRepository.h"
#include "DemoProductRepository.h"
#include "SimpleCommandLineInterface.h"

int main() {
    CustomerRepository* customerRepository = new DemoCustomerRepository();
    ProductRepository* productRepository = new DemoProductRepository();
    UserInterface* userInterface = new SimpleCommandLineInterface();
    CreditSimulator simulator = CreditSimulator(customerRepository, productRepository, userInterface);
    simulator.run();
    return 0;
}
