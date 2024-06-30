#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string pegawai[] = {"Budi", "Kusno", "Gusno"};
const string nama_file = "data.txt";

// Linked list
struct Data{
    int no_id;
    string nama_apoteker;
    string tanggal;
    string nomor_bpjs;
    string nama_buyer;
    string nama_obat;
    int kode_obat;
    string expired_obat;
    string supplier;
    int jumlah;
    long harga_total;
    Data* next;
};
Data* HEAD = NULL;

////////////////////////////////////////////////////////////////
///////////////////////////////////

void get_data(){}

void set_data(){
    ofstream outFile(nama_file);

    if (!outFile) {
        cerr << "Ada yang salah, tidak bisa membaca file" << endl;
        return;
    }

    outFile.close();
}

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
    
    Data* newData = new Data;
    newData->tanggal = input_tanggal;
    newData->nomor_bpjs = input_nomor_bpjs;
    newData->nama_buyer = input_nama_buyer;
    newData->nama_obat = input_nama_obat;
    newData->kode_obat = input_kode_obat;
    newData->expired_obat = input_expired_obat;
    newData->supplier = input_supplier;
    newData->jumlah = input_jumlah;
    newData->harga_total = input_harga_total;
    newData->next = NULL;

    if (HEAD == NULL) HEAD = newData;
    else {
        Data* temp = HEAD;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newData;
    }

    // Menambahkan data ke file 
    set_data();
}

void add_data(){

};

// void add_receipts(string tanggal, int jumlah, long harga_total){
//     Receipts* newReceipts = new Receipts;
//     newReceipts->tanggal = tanggal;
//     newReceipts->jumlah = jumlah;
//     newReceipts->harga_total = harga_total;
//     newReceipts->next = NULL;

//     if (HEAD_Receipts == NULL) HEAD_Receipts = newReceipts;
//     else {
//         Receipts* temp = HEAD_Receipts;
//         while (temp->next != NULL) temp = temp->next;
//         temp->next = newReceipts;
//     }
// }

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
    get_data(); // Mengambil data dari file txt

    return 0;
}