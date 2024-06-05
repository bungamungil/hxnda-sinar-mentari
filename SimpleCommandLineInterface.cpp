//
// Created by Bunga Mungil on 05/06/24.
//

#include <iomanip>
#include <iostream>
#include "SimpleCommandLineInterface.h"
using namespace std;

struct CurrencyFormatter: std::numpunct<char> {
    char_type do_thousands_sep() const override { return '.'; }
    char_type do_decimal_point() const override { return ','; }
    string_type do_grouping() const override { return "\3"; }
};

void SimpleCommandLineInterface::start() {
    auto formatter = make_unique<CurrencyFormatter>();
    cout.imbue(locale(cout.getloc(), formatter.release()));
    cout << fixed << setprecision(2);
    cout << "=================================================" << endl;
    cout << "   SELAMAT DATANG DI HONDA SINAR MENTARI MOTOR   " << endl;
    cout << "            Jln. Raya Kaliwungu-Boja             " << endl;
    cout << "=================================================" << endl;
    cout << "Kredit Motor Paling Murah di Sini (^_^)!!        " << endl; // Fixed: Penulisan "di Sini sesuai kaidah Bahasa Indonesia yang baik dan benar
    cout << "=================================================" << endl;
}

Customer *SimpleCommandLineInterface::askCustomerInformation() {
    return new Customer(
        readUserInput("Nama   : "),
        readUserInput("Alamat : "),
        readUserInput("Email  : "),
        readUserInput("Telpon : ")
    );
}

Product *SimpleCommandLineInterface::askCustomerToChooseProduct(vector<Product> *products) {
    cout << "Daftar Harga Motor :" << endl;
    int productCount = 0;
    for(const Product& product: *products) {
        productCount += 1;
        cout << productCount << ". " << std::setfill(' ') << std::setw(24) << std::left << product.getName();
        cout << "Rp " << product.getPrice() << endl;
    }
    productCount += 1;
    cout << productCount << ". Tidak Memilih" << endl;
    cout << "Tipe motor yang Anda pilih : ";
    int selectedMotorcycle;
    cin >> selectedMotorcycle;
    if (selectedMotorcycle > products->size()) {
        throw invalid_argument("Product yang Anda pilih tidak tersedia. Terima kasih.");
    }
    return &products->at(selectedMotorcycle - 1);
}

double SimpleCommandLineInterface::askCustomerToInputDownPayment(Product *product) {
    double minimal = product->getPayment().getMinimumDownPayment();
    double downPayment;
    cout << "======================================================" << endl;
    cout << "Masukkan DP yang Anda inginkan (minimal Rp " << minimal << ") : ";
    cin >> downPayment;
    cout << "======================================================" << endl;
    if (downPayment < minimal) {
        throw invalid_argument("Down payment " + to_string(downPayment) + " tidak tersedia.");
    }
    return downPayment;
}

Tenor *SimpleCommandLineInterface::askCustomerToChooseTenor(Product *product) {
    auto* result = (Tenor*) malloc(sizeof(Tenor));
    cout << "Pilihan lama kredit yaitu :" << endl;
    for(Tenor tenor: product->getPayment().getTenors()) {
        cout << " - " << tenor.getMonth() << " bulan (bunga " << tenor.getPercentageInterest() << "%)" << endl;
    }
    cout << "Masukkan lama kredit yang Anda pilih : ";
    int selectedMonth;
    cin >> selectedMonth;
    for(Tenor tenor: product->getPayment().getTenors()) {
        if (tenor.getMonth() == selectedMonth) {
            *result = tenor;
            return result;
        }
    }
    throw invalid_argument("Tenor " + to_string(selectedMonth) + " bulann tidak tersedia.");
}

void SimpleCommandLineInterface::showCreditSimulationResult(
    Customer *customer,
    Product *product,
    Tenor *tenor,
    double downPayment,
    double interest,
    double finalPrice,
    double repaymentValue,
    double paymentPerMonth
) {
    cout << "Harga motor menjadi Rp " << finalPrice << endl;
    cout << "Dengan DP Rp " << downPayment << " maka cicilan perbulan = Rp " << paymentPerMonth << endl;
    cout << "=================================================" << endl;
    cout << "Saudara " << customer->getName() << ", berikut kami tampilkan rincian cicilan Anda :" << endl;
    double debtRemaining = repaymentValue;
    int month = 0;
    while (debtRemaining > 0.1) {
        debtRemaining = debtRemaining - paymentPerMonth;
        month += 1;
        cout << "Setelah cicilan ke-" << month << ", sisa pembayaran : Rp " << debtRemaining << endl;
    }
    cout << "Info lebih lanjut hubungi Rina (0859xxxxxxxx)" << endl;
}

string SimpleCommandLineInterface::readUserInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}