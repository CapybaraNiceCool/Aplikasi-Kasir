#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Barang {
    string nama;
    string kode;
    long long harga;
};

int main() {

    #pragma region Data_Barang
    vector<Barang> daftar_barang = {
        {"Buku Tulis", "BT001", 5000},
        {"Pensil", "PN002", 2000},
        {"Penghapus", "PG003", 1500},
        {"Pulpen", "PL004", 3000},
        {"Penggaris", "PG005", 2500},
        {"Indomie Goreng", "IM006", 3500},
        {"Teh Botol", "TB007", 4000},
        {"Aqua", "AQ008", 3000},
        {"Roti Tawar", "RT009", 8000},
        {"Susu UHT", "SU010", 6000},
        {"Cokelat", "CK011", 7000},
        {"Permen", "PM012", 1000},
        {"Kopi Instan", "KI013", 5000},
        {"Mie Instan", "MI014", 4000},
        {"Sarden", "SD015", 12000},
        {"Minyak Goreng", "MG016", 15000},
        {"Gula Pasir", "GP017", 10000},
        {"Tepung Terigu", "TT018", 8000},
        {"Beras", "BR019", 12000},
        {"Kecap Manis", "KM020", 9000}
    };
    #pragma endregion

    #pragma region Variabel
    string kode, nama_barang;
    long long harga_barang, jumlah_barang, subtotal, total = 0;
    long long diskon, total_akhir, bayar, kembalian;
    char lagi;
    bool ada;
    int pilihan;

    vector<string> daftar_nama;
    vector<long long> daftar_harga;
    vector<long long> daftar_jumlah;
    #pragma endregion

    do {
        #pragma region Menu
        cout << endl;
        cout << "1. Transaksi Baru" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilihan;
        #pragma endregion

        if (pilihan == 1) {

            #pragma region Reset_Transaksi
            total = 0;
            daftar_nama.clear();
            daftar_harga.clear();
            daftar_jumlah.clear();
            #pragma endregion

            #pragma region Input_Barang
            do {
                cout << "Masukkan Kode Barang : ";
                cin >> kode;

                ada = false;
                for (int i = 0; i < daftar_barang.size(); i++) {
                    if (daftar_barang[i].kode == kode) {
                        nama_barang = daftar_barang[i].nama;
                        harga_barang = daftar_barang[i].harga;
                        ada = true;
                    }
                }

                if (ada == true) {
                    cout << "Barang : " << nama_barang << " (" << harga_barang << ")" << endl;
                    cout << "Masukkan Jumlah : ";
                    cin >> jumlah_barang;

                    subtotal = harga_barang * jumlah_barang;
                    total += subtotal;

                    daftar_nama.push_back(nama_barang);
                    daftar_harga.push_back(harga_barang);
                    daftar_jumlah.push_back(jumlah_barang);

                    cout << "Subtotal : " << subtotal << endl;
                    cout << "Total : " << total << endl;
                } else {
                    cout << "Kode tidak ditemukan" << endl;
                }

                cout << "lagi (y/n) : ";
                cin >> lagi;

            } while (lagi == 'y' || lagi == 'Y');
            #pragma endregion

            #pragma region Diskon
            if (total >= 50000) {
                diskon = total * 10 / 100;
            } else if (total >= 25000) {
                diskon = total * 5 / 100;
            } else {
                diskon = 0;
            }
            total_akhir = total - diskon;
            #pragma endregion

            #pragma region Bayar
            cout << "Total Belanja : " << total << endl;
            cout << "Diskon : " << diskon << endl;
            cout << "Total Bayar : " << total_akhir << endl;

            cout << "Masukkan Uang Bayar : ";
            cin >> bayar;
            while (bayar < total_akhir) {
                cout << "Uang kurang " << total_akhir - bayar << ", bayar lagi : ";
                cin >> bayar;
            }
            kembalian = bayar - total_akhir;
            #pragma endregion

            #pragma region Struk
            cout << endl;
            cout << "======TOKO KASIR======" << endl;
            cout << "Jl. Raya No. 123, Kota Contoh" << endl;
            cout << "======================" << endl;

            for (int i = 0; i < daftar_nama.size(); i++) {
                long long sub = daftar_harga[i] * daftar_jumlah[i];
                cout << left << setw(20) << daftar_nama[i]
                     << right << setw(5) << daftar_jumlah[i] << " x "
                     << setw(8) << daftar_harga[i]
                     << setw(10) << sub << endl;
            }

            cout << "----------------------" << endl;
            cout << left << setw(20) << "Total" << right << setw(10) << total << endl;
            cout << left << setw(20) << "Diskon" << right << setw(10) << diskon << endl;
            cout << left << setw(20) << "Total Bayar" << right << setw(10) << total_akhir << endl;
            cout << left << setw(20) << "Bayar" << right << setw(10) << bayar << endl;
            cout << left << setw(20) << "Kembalian" << right << setw(10) << kembalian << endl;
            cout << "======================" << endl;
            cout << "Terima kasih" << endl;
            #pragma endregion
        }

    } while (pilihan != 2);

    cout << "Program selesai." << endl;
    return 0;
}