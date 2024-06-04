#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    cout << "=================================================" << endl;
    cout << "   SELAMAT DATANG DI HONDA SINAR MENTARI MOTOR   " << endl;
    cout << "            Jln. Raya Kaliwungu-Boja             " << endl;
    cout << "=================================================" << endl;
    cout << "Kredit Motor Paling Murah di Sini (^_^)!!        " << endl; // Fixed: Penulisan "di Sini sesuai kaidah Bahasa Indonesia yang baik dan benar
    cout << "=================================================" << endl;
    cout << "Nama   : ";
    string name;
    getline(cin, name);
    cout << "Alamat : ";
    string address;
    getline(cin, address);
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
    double downPayment; // DP yang diisi oleh calon kreditur (dalam Rupiah)
    int tenor; // Tenor (lama kredit) yang dipilih calon kreditur (dalam bulan)
    double initialPrice; // Harga bersih motor yang dipilih calon kreditur (dalam Rupiah)
    double interest; // Besaran bunga yang akan dibebankan kepada kreditur (dalam Rupiah)
    double price; // Harga kotor motor setelah ditambahkan bunga (dalam Rupiah)
    double debt; // Sisa pembayaran yang akan dicicil oleh kreditur (dalam Rupiah)
    double paymentPerMonth; // Nominal yang akan dibayarkan per bulannya oleh kreditur (dalam Rupiah)
    cout << fixed << setprecision(2);
    switch (selectedMotorcycle) {
        case 1:
            cout << "======================================================" << endl;
            cout << "Masukkan DP yang Anda inginkan (minimal Rp 500.000) : ";
            cin >> downPayment;
            cout << "======================================================" << endl;
            if (downPayment >= 500000) {
                cout << "Pilihan lama kredit yaitu : 12 bulan (bunga 10%)" << endl;
                cout << "                            24 bulan (bunga 20%)" << endl;
                cout << "                            36 bulan (bunga 30%)" << endl;
                cout << "Masukkan lama kredit yang Anda pilih :";
                cin >> tenor;
                initialPrice = 17700000.0;
                if (tenor == 12) {
                    interest = initialPrice * 10 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 24) {
                    interest = initialPrice * 20 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 36) {
                    interest = initialPrice * 30 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                }
            } else {
                cout << "DP yang Anda masukkan tidak cukup. Terima kasih." << endl;
            }
            break;
        case 2:
            cout << "======================================================" << endl;
            cout << "Masukkan DP yang Anda inginkan (minimal Rp 500.000) : ";
            cin >> downPayment;
            cout << "======================================================" << endl;
            if (downPayment >= 500000) {
                cout << "Pilihan lama kredit yaitu : 12 bulan (bunga 10%)" << endl;
                cout << "                            24 bulan (bunga 20%)" << endl;
                cout << "                            36 bulan (bunga 30%)" << endl;
                cout << "Masukkan lama kredit yang Anda pilih : ";
                cin >> tenor;
                initialPrice = 20600000;
                if (tenor == 12) {
                    interest = initialPrice * 10 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 24) {
                    interest = initialPrice * 20 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 36) {
                    interest = initialPrice * 30 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                }
            } else {
                cout << "DP yang Anda masukkan tidak cukup. Terima kasih." << endl;
            }
            break;
        case 3:
            cout << "======================================================" << endl;
            cout << "Masukkan DP yang Anda inginkan (minimal Rp 500.000) : ";
            cin >> downPayment;
            cout << "======================================================" << endl;
            if (downPayment >= 500000) {
                cout << "Pilihan lama kredit yaitu : 12 bulan (bunga 10%)" << endl;
                cout << "                            24 bulan (bunga 20%)" << endl;
                cout << "                            36 bulan (bunga 30%)" << endl;
                cout << "Masukkan lama kredit yang Anda pilih : ";
                cin >> tenor;
                initialPrice = 24800000;
                if (tenor == 12) {
                    interest = initialPrice * 10 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 24) {
                    interest = initialPrice * 20 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 36) {
                    interest = initialPrice * 30 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                }
            } else {
                cout << "DP yang Anda masukkan tidak cukup. Terima kasih." << endl;
            }
            break;
        case 4:
            cout << "======================================================" << endl;
            cout << "Masukkan DP yang Anda inginkan (minimal Rp 500.000) : ";
            cin >> downPayment;
            cout << "======================================================" << endl;
            if (downPayment >= 500000) {
                cout << "Pilihan lama kredit yaitu : 12 bulan (bunga 10%)" << endl;
                cout << "                            24 bulan (bunga 20%)" << endl;
                cout << "                            36 bulan (bunga 30%)" << endl;
                cout << "Masukkan lama kredit yang Anda pilih : ";
                cin >> tenor;
                initialPrice = 24600000.0;
                if (tenor == 12) {
                    interest = initialPrice * 10 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 24) {
                    interest = initialPrice * 20 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 36) {
                    interest = initialPrice * 30 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                }
            } else {
                cout << "DP yang Anda masukkan tidak cukup. Terima kasih." << endl;
            }
            break;
        case 5:
            cout << "======================================================" << endl;
            cout << "Masukkan DP yang Anda inginkan (minimal Rp 500.000) : ";
            cin >> downPayment;
            cout << "======================================================" << endl;
            if (downPayment >= 500000) {
                cout << "Pilihan lama kredit yaitu : 12 bulan (bunga 10%)" << endl;
                cout << "                            24 bulan (bunga 20%)" << endl;
                cout << "                            36 bulan (bunga 30%)" << endl;
                cout << "Masukkan lama kredit yang Anda pilih : ";
                cin >> tenor;
                initialPrice = 18750000;
                if (tenor == 12) {
                    interest = initialPrice * 10 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 24) {
                    interest = initialPrice * 20 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                } else if (tenor == 36) {
                    interest = initialPrice * 30 / 100;
                    price = initialPrice + interest;
                    debt = price - downPayment;
                    paymentPerMonth = debt / tenor;
                    cout << "Harga motor menjadi " << price << endl;
                    cout << "Dengan DP " << downPayment << " maka cicilan perbulan = " << (paymentPerMonth) << endl;
                }
            } else {
                cout << "DP yang Anda masukkan tidak cukup. Terima kasih." << endl;
                return 0;
            }
            break;
        default:
            cout << "Terima kasih." << endl;
            return 0;
    }
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
    return 0;
}
