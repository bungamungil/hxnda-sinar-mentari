#include <iomanip>
#include <iostream>
#include "Customer.h"
#include "Product.h"
using namespace std;

void printHeader();
string readUserInput(const string& prompt);
Product* askUserToChooseMotorcycle();
void calculatePaymentTerms(
    double initialPrice,
    double* interest,
    double* finalPrice,
    double* debt,
    double* paymentPerMonth
);
int calculatePercentageInterest(int tenor);
int askUserToChooseTenor();
double askUserToInputDownPayment();
void printPaymentSteps(Customer* customer, double debt, double paymentPerMonth);

struct CurrencyFormatter: std::numpunct<char> {
    char_type do_thousands_sep() const override { return '.'; }
    char_type do_decimal_point() const override { return ','; }
    string_type do_grouping() const override { return "\3"; }
};

int main() {
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
    Product* selectedProduct = askUserToChooseMotorcycle();
    double interest; // Besaran bunga yang akan dibebankan kepada kreditur (dalam Rupiah)
    double price; // Harga kotor motor setelah ditambahkan bunga (dalam Rupiah)
    double debt; // Sisa pembayaran yang akan dicicil oleh kreditur (dalam Rupiah)
    double paymentPerMonth; // Nominal yang akan dibayarkan per bulannya oleh kreditur (dalam Rupiah)
    if (selectedProduct != nullptr) {
        calculatePaymentTerms(selectedProduct->getPrice(), &interest, &price, &debt, &paymentPerMonth);
        printPaymentSteps(&customer, debt, paymentPerMonth);
    } else {
        cout << "Terima kasih." << endl;
    }
    return 0;
}


void printHeader() {
    cout << "=================================================" << endl;
    cout << "   SELAMAT DATANG DI HONDA SINAR MENTARI MOTOR   " << endl;
    cout << "            Jln. Raya Kaliwungu-Boja             " << endl;
    cout << "=================================================" << endl;
    cout << "Kredit Motor Paling Murah di Sini (^_^)!!        " << endl; // Fixed: Penulisan "di Sini sesuai kaidah Bahasa Indonesia yang baik dan benar
    cout << "=================================================" << endl;
}

string readUserInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

Product* askUserToChooseMotorcycle() {
    vector<Product*> products;
    products.push_back(new Product("Beat CBS", 17'700'000));
    products.push_back(new Product("Scoopy", 20'600'000));
    products.push_back(new Product("Vario 150", 24'800'000));
    products.push_back(new Product("Supra GTR", 24'600'000));
    products.push_back(new Product("Genio CBS PLUS", 18'750'000));
    cout << "Daftar Harga Motor :" << endl;
    int productCount = 0;
    for(const Product* product: products) {
        productCount += 1;
        cout << productCount << ". " << std::setfill(' ') << std::setw(24) << std::left << product->getName();
        cout << "Rp " << product->getPrice() << endl;
    }
    productCount += 1;
    cout << productCount << ". Tidak Memilih" << endl;
    cout << "Tipe motor yang Anda pilih : ";
    int selectedMotorcycle;
    cin >> selectedMotorcycle;
    if (selectedMotorcycle > products.size()) {
        return nullptr;
    }
    return products[selectedMotorcycle - 1];
}

void calculatePaymentTerms(
    double initialPrice,
    double* interest,
    double* finalPrice,
    double* debt,
    double* paymentPerMonth
) {
    int tenor = askUserToChooseTenor();
    double downPayment = askUserToInputDownPayment();
    int percentageInterest = calculatePercentageInterest(tenor);
    *interest = initialPrice * percentageInterest / 100;
    *finalPrice = initialPrice + *interest;
    *debt = *finalPrice - downPayment;
    *paymentPerMonth = *debt / tenor;
    cout << "Harga motor menjadi " << *finalPrice << endl;
    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << *paymentPerMonth << endl;
}

int calculatePercentageInterest(int tenor) {
    if (tenor == 12) {
        return 10;
    }
    if (tenor == 24) {
        return 20;
    }
    if (tenor == 36) {
        return 30;
    }
    throw invalid_argument("Tenor " + to_string(tenor) + " tidak tersedia.");
}

int askUserToChooseTenor() {
    cout << "Pilihan lama kredit yaitu : 12 bulan (bunga 10%)" << endl;
    cout << "                            24 bulan (bunga 20%)" << endl;
    cout << "                            36 bulan (bunga 30%)" << endl;
    cout << "Masukkan lama kredit yang Anda pilih : ";
    int tenor;
    cin >> tenor;
    return tenor;
}

double askUserToInputDownPayment() {
    float downPayment;
    cout << "======================================================" << endl;
    cout << "Masukkan DP yang Anda inginkan (minimal Rp 500.000) : ";
    cin >> downPayment;
    cout << "======================================================" << endl;
    if (downPayment < 500000) {
        throw invalid_argument("Down payment " + to_string(downPayment) + " tidak tersedia.");
    }
    return downPayment;
}

void printPaymentSteps(Customer* customer, double debt, double paymentPerMonth) {
    cout << "=================================================" << endl;
    cout << "Saudara " << customer->getName() << ", berikut kami tampilkan rincian cicilan Anda :" << endl;
    double debtRemaining = debt;
    int month = 0;
    while (debtRemaining > 0.1) {
        debtRemaining = debtRemaining - paymentPerMonth;
        month += 1;
        cout << "Setelah cicilan ke-" << month << ", sisa pembayaran : " << debtRemaining << endl;
    }
    cout << "Info lebih lanjut hubungi Rina (0859xxxxxxxx)" << endl;
}
