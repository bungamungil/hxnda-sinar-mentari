//
// Created by Bunga Mungil on 05/06/24.
//

#include <iomanip>
#include <iostream>
#include "CreditSimulator.h"
using namespace std;

struct CurrencyFormatter: std::numpunct<char> {
    char_type do_thousands_sep() const override { return '.'; }
    char_type do_decimal_point() const override { return ','; }
    string_type do_grouping() const override { return "\3"; }
};

void CreditSimulator::run() {
    auto formatter = make_unique<CurrencyFormatter>();
    cout.imbue(locale(cout.getloc(), formatter.release()));
    cout << fixed << setprecision(2);
    printHeader();
    Customer customer(
            readUserInput("Nama   : "),
            readUserInput("Alamat : "),
            readUserInput("Email  : "),
            readUserInput("Telpon : ")
    );
    Product selectedProduct = askUserToChooseMotorcycle();
    double interest; // Besaran bunga yang akan dibebankan kepada kreditur (dalam Rupiah)
    double price; // Harga kotor motor setelah ditambahkan bunga (dalam Rupiah)
    double debt; // Sisa pembayaran yang akan dicicil oleh kreditur (dalam Rupiah)
    double paymentPerMonth; // Nominal yang akan dibayarkan per bulannya oleh kreditur (dalam Rupiah)
    calculatePaymentTerms(&selectedProduct, &interest, &price, &debt, &paymentPerMonth);
    printPaymentSteps(&customer, debt, paymentPerMonth);
}

void CreditSimulator::printHeader() {
    cout << "=================================================" << endl;
    cout << "   SELAMAT DATANG DI HONDA SINAR MENTARI MOTOR   " << endl;
    cout << "            Jln. Raya Kaliwungu-Boja             " << endl;
    cout << "=================================================" << endl;
    cout << "Kredit Motor Paling Murah di Sini (^_^)!!        " << endl; // Fixed: Penulisan "di Sini sesuai kaidah Bahasa Indonesia yang baik dan benar
    cout << "=================================================" << endl;
}

string CreditSimulator::readUserInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

Product CreditSimulator::askUserToChooseMotorcycle() {
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
    vector<Product> products;
    products.push_back(Product("Beat CBS", 17'700'000, defaultPayment));
    products.push_back(Product("Scoopy", 20'600'000, defaultPayment));
    products.push_back(Product("Vario 150", 24'800'000, promoPayment));
    products.push_back(Product("Supra GTR", 24'600'000, defaultPayment));
    products.push_back(Product("Genio CBS PLUS", 18'750'000, defaultPayment));
    cout << "Daftar Harga Motor :" << endl;
    int productCount = 0;
    for(const Product product: products) {
        productCount += 1;
        cout << productCount << ". " << std::setfill(' ') << std::setw(24) << std::left << product.getName();
        cout << "Rp " << product.getPrice() << endl;
    }
    productCount += 1;
    cout << productCount << ". Tidak Memilih" << endl;
    cout << "Tipe motor yang Anda pilih : ";
    int selectedMotorcycle;
    cin >> selectedMotorcycle;
    if (selectedMotorcycle > products.size()) {
        throw invalid_argument("Product yang Anda pilih tidak tersedia. Terima kasih.");
    }
    return products[selectedMotorcycle - 1];
}

void CreditSimulator::calculatePaymentTerms(
        Product* product,
        double* interest,
        double* finalPrice,
        double* debt,
        double* paymentPerMonth
) {
    double initialPrice = product->getPrice();
    Tenor tenor = askUserToChooseTenor(&product->getPayment());
    double downPayment = askUserToInputDownPayment(product->getPayment().getMinimumDownPayment());
    *interest = initialPrice * tenor.getPercentageInterest() / 100;
    *finalPrice = initialPrice + *interest;
    *debt = *finalPrice - downPayment;
    *paymentPerMonth = *debt / tenor.getMonth();
    cout << "Harga motor menjadi Rp " << *finalPrice << endl;
    cout << "Dengan DP Rp " << downPayment << " maka cicilan perbulan = Rp " << *paymentPerMonth << endl;
}

Tenor CreditSimulator::askUserToChooseTenor(const Payment* payment) {
    cout << "Pilihan lama kredit yaitu :" << endl;
    for(Tenor tenor: payment->getTenors()) {
        cout << " - " << tenor.getMonth() << " bulan (bunga " << tenor.getPercentageInterest() << "%)" << endl;
    }
    cout << "Masukkan lama kredit yang Anda pilih : ";
    int selectedMonth;
    cin >> selectedMonth;
    for(Tenor tenor: payment->getTenors()) {
        if (tenor.getMonth() == selectedMonth) {
            return tenor;
        }
    }
    throw invalid_argument("Tenor " + to_string(selectedMonth) + " bulann tidak tersedia.");
}

double CreditSimulator::askUserToInputDownPayment(double minimal) {
    float downPayment;
    cout << "======================================================" << endl;
    cout << "Masukkan DP yang Anda inginkan (minimal Rp " << minimal << ") : ";
    cin >> downPayment;
    cout << "======================================================" << endl;
    if (downPayment < minimal) {
        throw invalid_argument("Down payment " + to_string(downPayment) + " tidak tersedia.");
    }
    return downPayment;
}

void CreditSimulator::printPaymentSteps(Customer* customer, double debt, double paymentPerMonth) {
    cout << "=================================================" << endl;
    cout << "Saudara " << customer->getName() << ", berikut kami tampilkan rincian cicilan Anda :" << endl;
    double debtRemaining = debt;
    int month = 0;
    while (debtRemaining > 0.1) {
        debtRemaining = debtRemaining - paymentPerMonth;
        month += 1;
        cout << "Setelah cicilan ke-" << month << ", sisa pembayaran : Rp " << debtRemaining << endl;
    }
    cout << "Info lebih lanjut hubungi Rina (0859xxxxxxxx)" << endl;
}
