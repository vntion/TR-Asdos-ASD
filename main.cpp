#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string pegawai[] = {"Budi", "Kusno", "Gusno"};
const string FILE = "data.txt";

// Linked list
struct Pharmacist{
    int no_id;
    string nama_apoteker;
    Pharmacist* next;
}; 
Pharmacist* HEAD_Pharmacist = NULL;

struct Medicine{
    string nama_obat;
    int kode_obat;
    string expired_obat;
    string supplier;
    Medicine* next;
};
Medicine* HEAD_Medicine = NULL;

struct Buyer{
    string nomor_bpjs;
    string nama_buyer;
   Buyer* next;
};
Buyer* HEAD_Buyer = NULL;

struct Receipts{
    string tanggal;
    // string nomor_bpjs;
    // string nama_buyer;
    // string nama_obat;
    int jumlah;
    long harga_total;
    Receipts* next;
};
Receipts* HEAD_Receipts = NULL;

////////////////////////////////////////////////////////////////
///////////////////////////////////

void search(){

}

// Input data
void create_med(){
    int input_jumlah_data; // Jumlah data yang ingin dimasukkan
    int input_no_id, input_kode_obat, input_jumlah;
    long input_harga_total;
    string input_nama_apoteker, input_nama_obat, input_expired_obat, input_supplier, input_nomor_bpjs, input_nama_buyer, input_tanggal, input_nomor_bpjs, input_nama_buyer, nama_obat;

    cout << "Masukkan Jumlah Data: ";
    cin >> input_jumlah_data;
    cout << endl << endl;

    int i = 1; // Iteration

    // User memasukkan input data 
    do {
        cout << "Data Apotik ke - " << i << endl << endl;

        cout << "Nama Pasien\t : ";
        cin >> input_nama_buyer;

        cout << "Nomor BPJS\t : ";
        cin >> input_nomor_bpjs;

        cout << "Tanggal\t : ";
        cin >> input_tanggal;

        cout << "Nama Obat\t : ";
        cin >> input_nama_obat;

        cout << "Kode Obat\t : ";
        cin >> input_kode_obat;

        cout << "Expired Obat\t : ";
        cin >> input_expired_obat;

        cout << "Supplier\t : ";
        cin >> input_supplier;

        cout << "Jumlah\t : ";
        cin >> input_jumlah;

        cout << "Harga Total\t : ";
        cin >> input_harga_total;

        
    } while (i != input_jumlah_data);

    // Setelah user memasukkan input, proses selanjutnya memasukkan input ke data

    Pharmacist* newPharmacist = new Pharmacist;
    newPharmacist->no_id = 1;
    newPharmacist->nama_apoteker = pegawai[0];
    newPharmacist->next = NULL;

    HEAD_Pharmacist = newPharmacist;

}
void read_med(){

}
void update_med(){

}
void delete_med(){

}


    // pharmacist* HEAD = new pharmacist;
	// new pharmacist->no_id = 2;
    // HEAD->na
	// HEAD->next = NULL;

	// pharmacist* B = new pharmacist;
	// B->data = 5;
	// B->next = NULL;
	// HEAD->next = B;

	// pharmacist* C = new pharmacist;
	// C->data = 7;
	// C->next = NULL;
	// B->next = C;

int main(){

    return 0;
}