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

void set_data(){}

void search(){

}

// Input data
void create_med(){
    int input_jumlah_data; // Jumlah data yang ingin dimasukkan
    int input_no_id, input_kode_obat, input_jumlah;
    long input_harga_total;
    string input_nama_apoteker, input_nama_obat, input_expired_obat, input_supplier, input_nomor_bpjs, input_nama_buyer, input_tanggal, nama_obat;

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

        i++;
    } while (i != input_jumlah_data);

    // Setelah user memasukkan input, proses selanjutnya memasukkan input ke data
    add_medicine(input_nama_obat, input_kode_obat, input_expired_obat, input_supplier);    
    add_buyer(input_nomor_bpjs, input_nama_buyer);
    add_receipts(input_tanggal, input_jumlah, input_harga_total);

    // Menambahkan data ke file 
    set_data();
}

void add_medicine(string nama_obat, int kode_obat, string expired_obat, string supplier){
    Medicine* newMedicine = new Medicine;
    newMedicine->nama_obat = nama_obat;
    newMedicine->kode_obat = kode_obat;
    newMedicine->expired_obat = expired_obat;
    newMedicine->supplier = supplier;
    newMedicine->next = NULL;

    if (HEAD_Medicine == NULL) HEAD_Medicine = newMedicine;
    else {
        Medicine* temp = HEAD_Medicine;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newMedicine;
    }
}

void add_buyer(string nomor_bpjs, string nama_buyer) {
    Buyer* newBuyer = new Buyer;
    newBuyer->nomor_bpjs = nomor_bpjs;
    newBuyer->nama_buyer = nama_buyer;
    newBuyer->next = NULL;

    if (HEAD_Buyer == NULL) HEAD_Buyer = newBuyer;
    else {
        Buyer* temp = HEAD_Buyer;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newBuyer;
    }
}

void add_receipts(string tanggal, int jumlah, long harga_total){
    Receipts* newReceipts = new Receipts;
    newReceipts->tanggal = tanggal;
    newReceipts->jumlah = jumlah;
    newReceipts->harga_total = harga_total;
    newReceipts->next = NULL;

    if (HEAD_Receipts == NULL) HEAD_Receipts = newReceipts;
    else {
        Receipts* temp = HEAD_Receipts;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newReceipts;
    }
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
    // get_data();

    return 0;
}