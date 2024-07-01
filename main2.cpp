#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

const string pegawai[] = {"Budi", "Kusno", "Gusno"};
const string nama_file = "data2.txt";

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

void get_data(){
    ifstream inFile(nama_file);

     if (!inFile) {
        cerr << "Ada yang salah, tidak bisa membaca file" << endl;
        return;
    }

    string line;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        string arr[11];
        int i = 0;
        stringstream ssin(line);
        while (ssin.good() && i < 11) {
            ssin >> arr[i];
            i++;
        }

        Data* newData = new Data;
        newData -> no_id = stoi(arr[0]);
        newData -> nama_apoteker = arr[1];
        newData -> tanggal = arr[2];
        newData->nomor_bpjs = arr[3];
        newData->nama_buyer = arr[4];
        newData->nama_obat = arr[5];
        newData->kode_obat = stoi(arr[6]);
        newData->expired_obat = arr[7];
        newData->supplier = arr[8];
        newData->jumlah = stoi(arr[9]);
        newData->harga_total = stol(arr[10]);
        newData->next = NULL;

        if (HEAD == NULL) HEAD = newData;
        else {
            Data* temp = HEAD;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newData;
        }
    }

    inFile.close();
}

void set_data() {
  ofstream outFile(nama_file);

  if (!outFile) {
    cerr << "Ada yang salah, tidak bisa membaca file" << endl;
    return;
  }

  Data * temp = HEAD;

  while (temp != NULL) {
    outFile << temp -> no_id << " " << temp -> nama_apoteker << " " << temp -> tanggal << " " << temp -> nomor_bpjs << " " << temp -> nama_buyer << " " << temp -> nama_obat << " " <<
    temp -> kode_obat << " " << temp -> expired_obat << " " << temp -> supplier << " " << temp -> jumlah << " " << temp -> harga_total << endl;
    temp = temp -> next;
  }

  outFile.close();
}

// Input data
void buat_data(){
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

void lihat_data(){

}

void tambah_data(){

}

void hapus_data(){

}

void edit_data(){
    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }

    int cari_id;
    cout << "Cari No ID yang mau diedit :";
    cin >> cari_id;

    // Cari id dari linked list
    Data* temp = HEAD;
    while (temp != NULL) {
        if (temp -> no_id == cari_id) break;
        temp = temp -> next;
    }

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

    int pilih_menu;

    cout << "1. NO ID \t"         << "5. NAMA BUYER \t"     << "9. SUPPLIER \t"     << endl;
    cout << "2. NAMA APOTEKER \t" << "6. NAMA OBAT \t"      << "10. JUMLAH \t"      << endl;
    cout << "3. TANGGAL \t"       << "7. KODE OBAT \t"      << "11. HARGA TOTAL \t" << endl;
    cout << "4. NO BPJS \t"       << "8. EXPIRED OBAT \t"   << "12. KEMBALI \t"     << endl;




}

void cari_data(){

}

void urutkan_data(){

}

int main(){
    get_data(); // Mengambil data dari file txt

    return 0;
}