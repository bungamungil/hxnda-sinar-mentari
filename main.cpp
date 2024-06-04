#include <iomanip>
#include <iostream>
using namespace std;

void printHeader();
string readUserInput(const string& prompt);
int askUserToChooseMotorcycle();
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
void printPaymentSteps(const string& name, double debt, double paymentPerMonth);

int main() {
    printHeader();
    string name = readUserInput("Nama   : ");
    string address = readUserInput("Alamat : ");
    int selectedMotorcycle = askUserToChooseMotorcycle();
    double interest; // Besaran bunga yang akan dibebankan kepada kreditur (dalam Rupiah)
    double price; // Harga kotor motor setelah ditambahkan bunga (dalam Rupiah)
    double debt; // Sisa pembayaran yang akan dicicil oleh kreditur (dalam Rupiah)
    double paymentPerMonth; // Nominal yang akan dibayarkan per bulannya oleh kreditur (dalam Rupiah)
    cout << fixed << setprecision(2);
    switch (selectedMotorcycle) {
        case 1:
            calculatePaymentTerms(17700000.0, &interest, &price, &debt, &paymentPerMonth);
            break;
        case 2:
            calculatePaymentTerms(20600000.0, &interest, &price, &debt, &paymentPerMonth);
            break;
        case 3:
            calculatePaymentTerms(24800000.0, &interest, &price, &debt, &paymentPerMonth);
            break;
        case 4:
            calculatePaymentTerms(24600000.0, &interest, &price, &debt, &paymentPerMonth);
            break;
        case 5:
            calculatePaymentTerms(18750000.0, &interest, &price, &debt, &paymentPerMonth);
            break;
        default:
            cout << "Terima kasih." << endl;
            return 0;
    }
    printPaymentSteps(name, debt, paymentPerMonth);
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

int askUserToChooseMotorcycle() {
    cout << "Daftar Harga Motor :" << endl;
    cout << "1. Beat CBS         Rp 17.700.000" << endl;
    cout << "2. Scoopy           Rp 20.600.000" << endl;
    cout << "3. Vario 150        Rp 24.800.000" << endl;
    cout << "4. Supra GTR        Rp 24.600.000" << endl;
    cout << "5. Genio CBS PLUS   Rp 18.750.000" << endl;
    cout << "6. Tidak Memilih" << endl;
    cout << "Tipe motor yang Anda pilih : ";
    int selectedMotorcycle;
    cin >> selectedMotorcycle;
    return selectedMotorcycle;
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

void printPaymentSteps(const string& name, double debt, double paymentPerMonth) {
    cout << "=================================================" << endl;
    cout << "Saudara " << name << ", berikut kami tampilkan rincian cicilan Anda :" << endl;
    double debtRemaining = debt;
    int month = 0;
    while (debtRemaining > 0.1) {
        debtRemaining = debtRemaining - paymentPerMonth;
        month += 1;
        cout << "Setelah cicilan ke-" << month << ", sisa pembayaran : " << debtRemaining << endl;
    }
    cout << "Info lebih lanjut hubungi Rina (0859xxxxxxxx)" << endl;
}