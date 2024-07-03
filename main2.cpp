#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <cstdlib>
#include <limits>

using namespace std;

const string nama_file = "data2.txt";
bool benar = false;

// Linked list
struct Data{
    int no_id;
    int no_id_apoteker;
    string nama_apoteker;
    string tanggal;
    long nomor_bpjs;
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

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void get_data(){
    ifstream inFile(nama_file);

     if (!inFile) {
        cerr << "Ada yang salah, tidak bisa membaca file" << endl;
        return;
    }

    string line;

    while (getline(inFile, line)) {
        string arr[12];
        int i = 0;
        stringstream data(line);
        string line2;
        while (data.good() && getline(data, line2, ';') && i < 12) {
            arr[i] = line2;
            i++;
        }

        Data* newData = new Data;
        newData -> no_id = stoi(arr[0]);
        newData->no_id_apoteker = stoi(arr[1]);
        newData -> nama_apoteker = arr[2];
        newData -> tanggal = arr[3];
        newData->nomor_bpjs = stol(arr[4]);
        newData->nama_buyer = arr[5];
        newData->nama_obat = arr[6];
        newData->kode_obat = stoi(arr[7]);
        newData->expired_obat = arr[8];
        newData->supplier = arr[9];
        newData->jumlah = stoi(arr[10]);
        newData->harga_total = stol(arr[11]);
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

  Data* temp = HEAD;

  while (temp != NULL) {
    outFile << temp -> no_id << ";" << temp->no_id_apoteker << ";" <<temp -> nama_apoteker << ";" << temp -> tanggal << ";" << temp -> nomor_bpjs << ";" << temp -> nama_buyer << ";" << temp -> nama_obat << ";" <<
    temp -> kode_obat << ";" << temp -> expired_obat << ";" << temp -> supplier << ";" << temp -> jumlah << ";" << temp -> harga_total << ";" << endl;
    temp = temp -> next;
  }

  outFile.close();
}

void tambah_data(){
    int input_jumlah_data; // Jumlah data yang ingin dimasukkan
    int input_no_id, input_kode_obat, input_jumlah, input_no_id_pegawai;
    long input_harga_total, input_nomor_bpjs;
    string input_nama_apoteker, input_nama_obat, input_expired_obat, input_supplier, input_nama_buyer, input_tanggal, nama_obat;

    system("cls");
    cout << "=====================================================================" << endl;
    cout << "||                           MASUKKAN DATA                         ||" << endl;
    cout << "=====================================================================" << endl;
    cout << "Kembali: 0" << endl << endl;

    while (true) {
        cout << "Masukkan Jumlah Data: ";
        cin >> input_jumlah_data;
        if (cin.fail() || input_jumlah_data < 0) {
            cout << "Invalid input, masukkan angka bulat" << endl;
            clearInputBuffer();
        } else {
            break;
        }
    }
    clearInputBuffer();
    if (input_jumlah_data == 0) return;
    cout << endl << endl;

    int i = 1; // Iteration

    // User memasukkan input data
    while (i <= input_jumlah_data) {
        cout << "Data Apotik ke - " << i << endl << endl;

        while (true) {
            cout << "No id : ";
            cin >> input_no_id;
            if (cin.fail() || input_no_id < 1) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        while (true) {
            cout << "No id apoteker : ";
            cin >> input_no_id_pegawai;
            if (cin.fail() || input_no_id_pegawai < 1) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        cout << "Nama Apoteker\t : ";
        getline(cin, input_nama_apoteker);

        cout << "Nama Pasien\t : ";
        getline(cin, input_nama_buyer);

        while (true) {
            cout << "Nomor BPJS \t: ";
            cin >> input_nomor_bpjs;
            if (cin.fail() || input_nomor_bpjs < 1) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        cout << "Tanggal\t : ";
        getline(cin, input_tanggal);

        cout << "Nama Obat\t : ";
        getline(cin, input_nama_obat);

        while (true) {
            cout << "Kode Obat \t: ";
            cin >> input_kode_obat;
            if (cin.fail() || input_kode_obat < 1) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        cout << "Expired Obat\t : ";
        getline(cin, input_expired_obat);

        cout << "Supplier\t : ";
        getline(cin, input_supplier);

        while (true) {
            cout << "Jumlah : ";
            cin >> input_jumlah;
            if (cin.fail() || input_jumlah < 1) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        while (true) {
            cout << "Harga total : ";
            cin >> input_harga_total;
            if (cin.fail() || input_harga_total < 1) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        i++;
   

        // Setelah user memasukkan input, proses selanjutnya memasukkan input ke data
        Data* newData = new Data;
        newData->no_id = input_no_id;
        newData->no_id_apoteker = input_no_id_pegawai;
        newData->nama_apoteker = input_nama_apoteker;
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
    }

    // Menambahkan data ke file
    set_data();

    cout << "=====================================================================" << endl;
    cout << "Data berhasil ditambahkan!";
    getch();
}

void lihat_data(){
    system("cls");
    cout << "=====================================================================" << endl;
    cout << "||                                LIHAT DATA                       ||" << endl;
    cout << "=====================================================================" << endl;


    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }
    
    Data* temp = HEAD;
    int i = 1;

    while (temp != NULL) {
        cout << "Data ke - " << i << endl;
        cout << "No id :" << temp -> no_id << endl;
        cout << "NO id pegawai :" << temp->no_id_apoteker << endl;
        cout << "Nama Apoteker :" << temp -> nama_apoteker << endl;
        cout << "Tanggal :" << temp -> tanggal << endl;
        cout << "No BPJS :" << temp -> nomor_bpjs << endl;
        cout << "Nama Buyer :" << temp -> nama_buyer << endl;
        cout << "Nama Obat :" << temp -> nama_obat << endl;
        cout << "Kode Obat :" << temp -> kode_obat << endl;
        cout << "Expired Obat :" << temp -> expired_obat << endl;
        cout << "Supplier :" << temp -> supplier << endl;
        cout << "Jumlah :" << temp -> jumlah << endl;
        cout << "Harga Total :" << temp -> harga_total << endl << endl;
        temp = temp -> next;
        i++;
    }

    cout << "=====================================================================" << endl;
    getch();
}

void hapus_data(){
    system("cls");
    cout << "=====================================================================" << endl;
    cout << "||                                 HAPUS DATA                      ||" << endl;
    cout << "=====================================================================" << endl;

    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }
    cout << "Kembali: 0" << endl << endl;

    // Render tabel data
    Data* temp = HEAD;
    int i = 1;

    while (temp != NULL) {
        cout << "Data ke - " << i << endl;
        cout << "No id :" << temp -> no_id << endl;
        cout << "NO id pegawai :" << temp->no_id_apoteker << endl;
        cout << "Nama Apoteker :" << temp -> nama_apoteker << endl;
        cout << "Tanggal :" << temp -> tanggal << endl;
        cout << "No BPJS :" << temp -> nomor_bpjs << endl;
        cout << "Nama Buyer :" << temp -> nama_buyer << endl;
        cout << "Nama Obat :" << temp -> nama_obat << endl;
        cout << "Kode Obat :" << temp -> kode_obat << endl;
        cout << "Expired Obat :" << temp -> expired_obat << endl;
        cout << "Supplier :" << temp -> supplier << endl;
        cout << "Jumlah :" << temp -> jumlah << endl;
        cout << "Harga Total :" << temp -> harga_total << endl << endl;
        temp = temp -> next;
    }
    cout << "=====================================================================" << endl;

    // Pencarian ID
    Data* search = HEAD;
    int cari_id;
    bool found = false;
    while (true) {
        while (true) {
            cout << "Cari No ID yang mau dihapus :";
            cin >> cari_id;
            if (cin.fail() || cari_id < 0) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        while (search != NULL) {
            if (search->no_id == cari_id) {
                found = true;
                break;
            }
            search = search -> next;
        }

        // Cek apakah data ditemukan atau tidak
        if (cari_id == 0) break;
        if (!found) {
            cout << "ID tidak ditemukan!";
            search = HEAD;
            getch();
        }
        if (found) break;
    }

    if (cari_id == 0) return;

    ///// Proses hapus data berdasarkan id
    Data* cur = HEAD;
    Data* prev = NULL;

    // Jika id yang dicari berada di awal linked list
    if (HEAD->no_id == cari_id) {
        HEAD = HEAD -> next;
        set_data();
        return;
    }

    // Jika id yang dicari tidak di awal linked list
    while (cur != NULL && cur->no_id != cari_id) {
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;

    // Menambahkan data ke file
    set_data();

    cout << "=====================================================================" << endl;
    cout << "Data berhasil dihapus";
    getch();

}

void edit_data(){
    system("cls");
    cout << "=====================================================================" << endl;
    cout << "||                                 EDIT DATA                       ||" << endl;
    cout << "=====================================================================" << endl;

    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }
    cout << "Kembali: 0" << endl << endl;

    Data* temp = HEAD;

    // Cari ID
    int cari_id;
    bool found = false;
    while (true) {
        cout << "Cari No ID yang mau diedit :";
        while (true) {
            cin >> cari_id;
            if (cin.fail() || cari_id < 0) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        // Cari id dari linked list
        while (temp != NULL) {
            if (temp -> no_id == cari_id) {
                found = true;
                break;
            }
            temp = temp -> next;
        }

        // Cek apakah data ditemukan atau tidak
        if (cari_id == 0) break;
        if (!found) {
            cout << "Data tidak ditemukan!" << endl;
            temp = HEAD;
            getch();
        }
        if (found) break;
    }

    if (cari_id == 0) return;

    int no_id;
    int no_id_apoteker;
    string nama_apoteker;
    string tanggal;
    long nomor_bpjs;
    string nama_buyer;
    string nama_obat;
    int kode_obat;
    string expired_obat;
    string supplier;
    int jumlah;
    long harga_total;

    int pilih_menu;
    bool is_again = true;

    // Pilih menu
    while (is_again) {
        system("cls");
        cout << "=====================================================================" << endl;
        cout << "||                                 EDIT DATA                       ||" << endl;
        cout << "=====================================================================" << endl;
        cout << "Edit berdasarkan apa : "     << endl;
        cout << "1. NO ID \t"         << "5. NO BPJS \t"     << "9. EXPIRED OBAT \t"     << endl;
        cout << "2. NO ID PEGAWAI \t" << "6. NAMA BUYER \t"     << "10. SUPPLIER \t"     << endl;
        cout << "3. NAMA APOTEKER \t" << "7. NAMA OBAT \t"      << "11. JUMLAH \t"      << endl;
        cout << "4. TANGGAL \t"       << "8. KODE OBAT \t"      << "12. HARGA TOTAL \t" << endl;
        cout << "13. KEMBALI \t"      << endl;
        cout << "Pilihan : ";

        while (true) {
            cin >> pilih_menu;
            if (cin.fail()) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        // Setelah memilih menu
        switch (pilih_menu) {
            case 1:
                cout << "No id baru : ";
                while (true) {
                    cin >> no_id;
                    if (cin.fail()) {
                        cout << "Invalid input, masukkan angka bulat" << endl;
                        clearInputBuffer();
                    } else {
                        break;
                    }
                }
                clearInputBuffer();
                temp -> no_id = no_id;
                break;
            case 2:
                cout << "No Id Apoteker baru : ";
                while (true) {
                    cin >> no_id_apoteker;
                    if (cin.fail()) {
                        cout << "Invalid input, masukkan angka bulat" << endl;
                        clearInputBuffer();
                    } else {
                        break;
                    }
                }
                clearInputBuffer();
                temp -> no_id_apoteker = no_id_apoteker;
                break;
            case 3:
                cout << "Nama Apoteker baru : ";
                getline(cin, nama_apoteker);
                temp -> nama_apoteker = nama_apoteker;
                break;
            case 4:
                cout << "Tanggal baru : ";
                getline(cin, tanggal);
                temp -> tanggal = tanggal;
                break;
            case 5:
                cout << "No BPJS baru : ";
                while (true) {
                    cin >> nomor_bpjs;
                    if (cin.fail()) {
                        cout << "Invalid input, masukkan angka bulat" << endl;
                        clearInputBuffer();
                    } else {
                        break;
                    }
                }
                temp -> nomor_bpjs = nomor_bpjs;
                break;
            case 6:
                cout << "Nama Buyer baru : ";
                getline(cin, nama_buyer);
                temp -> nama_buyer = nama_buyer;
                break;
            case 7:
                cout << "Nama Obat baru : ";
                getline(cin, nama_obat);
                temp -> nama_obat = nama_obat;
                break;
            case 8:
                cout << "Kode Obat baru : ";
                while (true) {
                    cin >> kode_obat;
                    if (cin.fail()) {
                        cout << "Invalid input, masukkan angka bulat" << endl;
                        clearInputBuffer();
                    } else {
                        break;
                    }
                }
                clearInputBuffer();
                temp -> kode_obat = kode_obat;
                break;
            case 9:
                cout << "Expired Obat baru : ";
                getline(cin, expired_obat);
                temp -> expired_obat = expired_obat;
                break;
            case 10:
                cout << "Supplier baru : ";
                getline(cin, supplier);
                temp -> supplier = supplier;
                break;
            case 11:
                cout << "Jumlah baru : ";
                while (true) {
                    cin >> jumlah;
                    if (cin.fail()) {
                        cout << "Invalid input, masukkan angka bulat" << endl;
                        clearInputBuffer();
                    } else {
                        break;
                    }
                }
                clearInputBuffer();
                temp -> jumlah = jumlah;
                break;
            case 12:
                cout << "Harga Total baru : ";
                while (true) {
                    cin >> harga_total;
                    if (cin.fail()) {
                        cout << "Invalid input, masukkan angka bulat" << endl;
                        clearInputBuffer();
                    } else {
                        break;
                    }
                }
                clearInputBuffer();
                temp -> harga_total = harga_total;
                break;
            case 13:
                cout << "Kembali" << endl;
                is_again = false;
                break;
            default:
                cout << "Pilih antara angka yang ada di menu (1-13)" << endl;
        }
    }

    // Menambahkan data ke file
    set_data();
}
void cari_id(){
    int search_idpengisian;

    do {
        cout << "Masukkan keyword id yang ingin dicari : ";
        cin >> search_idpengisian;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);
    
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_idpengisian!=temp->no_id){
            temp = temp->next;
        }
        else{
            cout << "No id :" << temp -> no_id << endl;
            cout << "NO id pegawai :" << temp->no_id_apoteker << endl;
            cout << "Nama Apoteker :" << temp -> nama_apoteker << endl;
            cout << "Tanggal :" << temp -> tanggal << endl;
            cout << "No BPJS :" << temp -> nomor_bpjs << endl;
            cout << "Nama Buyer :" << temp -> nama_buyer << endl;
            cout << "Nama Obat :" << temp -> nama_obat << endl;
            cout << "Kode Obat :" << temp -> kode_obat << endl;
            cout << "Expired Obat :" << temp -> expired_obat << endl;
            cout << "Supplier :" << temp -> supplier << endl;
            cout << "Jumlah :" << temp -> jumlah << endl;
            cout << "Harga Total :" << temp -> harga_total << endl << endl;
            
            found = true;
            getchar();
            getchar();
            break;
            system("cls");
        }
    }
    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void cari_IDapoteker(){
    int search_id;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_id;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);
    
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_id==temp->no_id_apoteker){
        
            cout << "Data ditemukan !" << endl;
            cout << temp->no_id_apoteker << endl;
            cout << temp->nama_apoteker << endl;
           
            found = true;
        
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
    }
}

                           
void cari_NAMAapoteker(){
    string search_Namaapoteker;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_Namaapoteker;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_Namaapoteker==temp->nama_apoteker){
        
            cout << "Data ditemukan !" << endl;
            cout << temp->no_id_apoteker << endl;
            cout << temp->nama_apoteker << endl << endl;
        
            found = true;
        }
        
        temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void cari_tanggalReceipt(){
    string search_tanggal;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_tanggal;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_tanggal == temp->tanggal){

            cout << "Data ditemukan !" << endl;
            cout << temp -> tanggal << endl;
            cout << temp-> jumlah << endl;
            cout << temp-> harga_total << endl;

            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}
                           
void cari_NObpjs(){
    int search_bpjs;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_bpjs;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs==temp->nomor_bpjs){

            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;

            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}
                            
void cari_namabuyer(){
    string search_namabuyer;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_namabuyer;

        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_namabuyer == temp->nama_buyer){

            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;

            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void cari_namaobat(){
    string search_obat;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_obat;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_obat == temp->nama_obat){

            cout << "Data ditemukan !" << endl;
            cout << temp-> nama_obat << endl;
            cout << temp -> kode_obat << endl;
            cout << temp -> expired_obat << endl;
            cout << temp -> supplier << endl;

            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void cari_kodeobat(){
    int search_IDobat;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_IDobat;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_IDobat==temp->kode_obat){

            cout << "Data ditemukan !" << endl;
            cout << temp-> nama_obat << endl;
            cout << temp -> kode_obat << endl;
            cout << temp -> expired_obat << endl;
            cout << temp -> supplier << endl;

            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void cari_expobat(){
    string search_exp;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_exp;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_exp==temp->expired_obat){

            cout << "Data ditemukan !" << endl;
            cout << temp-> nama_obat << endl;
            cout << temp -> kode_obat << endl;
            cout << temp -> expired_obat << endl;
            cout << temp -> supplier << endl;
            
            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void cari_NAMAsupplier(){
    string search_supplier;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_supplier;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp == NULL) {
        if(search_supplier!=temp->supplier){

            cout << "Data ditemukan !" << endl;
            cout << temp-> nama_obat << endl;
            cout << temp -> kode_obat << endl;
            cout << temp -> expired_obat << endl;
            cout << temp -> supplier << endl;

            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void cari_jumlahobat(){
    int search_jmlobat;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_jmlobat;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);

    bool found=false;

    Data* temp = HEAD;
    while (temp == NULL) {
        if(search_jmlobat != temp->jumlah){

            cout << "Data ditemukan !" << endl;
            cout << temp -> tanggal << endl;
            cout << temp -> jumlah << endl;
            cout << temp -> harga_total << endl;
            
            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void cari_hargatotal(){
    long search_hargatot;

    do {
        cout << "Masukkan keyword nama yang ingin dicari : ";
        cin >> search_hargatot;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        } else {
            benar = true; // Input valid, keluar dari loop
        }
    } while (!benar);
    
    bool found=false;

    Data* temp = HEAD;
    while (temp == NULL) {
        if(search_hargatot!=temp->harga_total){

            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;

            found = true;
        }
            temp = temp->next;
    }
            getchar();
            getchar();
            system("cls");

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}

void SortNamaApoteker(Data*& HEAD) {
  int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->nama_apoteker > ptr1->next->nama_apoteker) {
        int tempNoId = ptr1->no_id;
        ptr1->no_id = ptr1->next->no_id;
        ptr1->next->no_id = tempNoId;

        int tempNoIdApoteker = ptr1->no_id_apoteker;
        ptr1->no_id_apoteker = ptr1->next->no_id_apoteker;
        ptr1->next->no_id_apoteker = tempNoIdApoteker;

        string tempNamaApoteker = ptr1->nama_apoteker;
        ptr1->nama_apoteker = ptr1->next->nama_apoteker;
        ptr1->next->nama_apoteker = tempNamaApoteker;

        string tempTanggal = ptr1->tanggal;
        ptr1->tanggal = ptr1->next->tanggal;
        ptr1->next->tanggal = tempTanggal;

        long tempNomorBpjs = ptr1->nomor_bpjs;
        ptr1->nomor_bpjs = ptr1->next->nomor_bpjs;
        ptr1->next->nomor_bpjs = tempNomorBpjs;

        string tempNamaBuyer = ptr1->nama_buyer;
        ptr1->nama_buyer = ptr1->next->nama_buyer;
        ptr1->next->nama_buyer = tempNamaBuyer;

        string tempNamaObat = ptr1->nama_obat;
        ptr1->nama_obat = ptr1->next->nama_obat;
        ptr1->next->nama_obat = tempNamaObat;

        int tempKodeObat = ptr1->kode_obat;
        ptr1->kode_obat = ptr1->next->kode_obat;
        ptr1->next->kode_obat = tempKodeObat;

        string tempExpiredObat = ptr1->expired_obat;
        ptr1->expired_obat = ptr1->next->expired_obat;
        ptr1->next->expired_obat = tempExpiredObat;

        string tempSupplier = ptr1->supplier;
        ptr1->supplier = ptr1->next->supplier;
        ptr1->next->supplier = tempSupplier;

        int tempJumlah = ptr1->jumlah;
        ptr1->jumlah = ptr1->next->jumlah;
        ptr1->next->jumlah = tempJumlah;

        long tempHargaTotal = ptr1->harga_total;
        ptr1->harga_total = ptr1->next->harga_total;
        ptr1->next->harga_total = tempHargaTotal;

        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}


// void cari_IDapoteker(){
    
// }

                        
// void cari_NAMAapoteker(){
    
// }

// void cari_tanggalReceipt(){
    
// }
                           
// void cari_NObpjs(){
    
// }
                            
// void cari_namabuyer(){
    
// }

// void cari_namaobat(){
    
// }

// void cari_kodeobat(){
    
// }

// void cari_expobat(){
    
// }

// void cari_NAMAsupplier(){
    
// }

// void cari_jumlahobat(){
    
// }

// void cari_hargatotal(){
    
// }







void printSorted(Data*& HEAD) {
  Data* ptr = HEAD;
  while (ptr!= NULL) {
            cout << "No id :" << ptr -> no_id << endl;
            cout << "NO id pegawai :" << ptr->no_id_apoteker << endl;
            cout << "Nama Apoteker :" << ptr -> nama_apoteker << endl;
            cout << "Tanggal :" << ptr -> tanggal << endl;
            cout << "No BPJS :" << ptr -> nomor_bpjs << endl;
            cout << "Nama Buyer :" << ptr -> nama_buyer << endl;
            cout << "Nama Obat :" << ptr -> nama_obat << endl;
            cout << "Kode Obat :" << ptr -> kode_obat << endl;
            cout << "Expired Obat :" << ptr -> expired_obat << endl;
            cout << "Supplier :" << ptr -> supplier << endl;
            cout << "Jumlah :" << ptr -> jumlah << endl;
            cout << "Harga Total :" << ptr -> harga_total << endl << endl;
    ptr = ptr->next;
  }
  getch();
}

void sort_data(){
    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }

    int choice1;

    do{
        cout << "Sort berdasarkan apa : "     << endl;
        cout << "1. NO ID \t"         << "5. NO BPJS \t"     << "9. EXPIRED OBAT \t"     << endl;
        cout << "2. NO ID PEGAWAI \t" << "6. NAMA BUYER \t"     << "10. SUPPLIER \t"     << endl;
        cout << "3. NAMA APOTEKER \t" << "7. NAMA OBAT \t"      << "11. JUMLAH \t"      << endl;
        cout << "4. TANGGAL \t"       << "8. KODE OBAT \t"      << "12. HARGA TOTAL \t" << endl;
        cout << "13. KEMBALI \t"      << endl;

        cin >> choice1;
        switch (choice1) {
                        // case 1:
                        //     SortNamaApoteker();

                        //     break;
                        case 2:
                            SortNamaApoteker(HEAD);
                            printSorted(HEAD);
                            break;
                        // case 3:
                        //     cari_NAMAapoteker();
                        //     break;
                        // case 4:
                        //     cari_tanggalReceipt();
                        //     break;
                        // case 5:
                        //     cari_NObpjs();
                        //     break;
                        // case 6:
                        //     cari_namabuyer();
                        //     break;
                        // case 7:
                        //     cari_namaobat();
                        //     break;
                        // case 8:
                        //     cari_kodeobat();
                        //     break;
                        // case 9:
                        //     cari_expobat();
                        //     break;
                        // case 10:
                        //     cari_NAMAsupplier();
                        //     break;
                        // case 11:
                        //     cari_jumlahobat();
                        //     break;
                        // case 12:
                        //     cari_hargatotal();
                        //     break;
                        // case 13:
                        //     cout << "Keluar";
                        //     getch();
                        //     break;
                        default:
                            cout << "Pilih antara angka yang ada di menu (1-13)";
                            getch();
                            break;

        }
    }while(choice1 !=13);

}

void cari_data(){
    system("cls");
    cout << "=====================================================================" << endl;
    cout << "||                                 EDIT DATA                       ||" << endl;
    cout << "=====================================================================" << endl;

    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }
    int choice2;
    cout << "Kembali: 0" << endl << endl;

    do{
        cout << "Cari berdasarkan apa : "     << endl;
        cout << "1. NO ID \t"         << "5. NO BPJS \t"     << "9. EXPIRED OBAT \t"     << endl;
        cout << "2. NO ID PEGAWAI \t" << "6. NAMA BUYER \t"     << "10. SUPPLIER \t"     << endl;
        cout << "3. NAMA APOTEKER \t" << "7. NAMA OBAT \t"      << "11. JUMLAH \t"      << endl;
        cout << "4. TANGGAL \t"       << "8. KODE OBAT \t"      << "12. HARGA TOTAL \t" << endl;
        cout << "13. KEMBALI \t"      << endl << endl;

        while (true) {
            cin >> choice2;
            if (cin.fail()) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        if (choice2 == 0) break;
        switch (choice2) {
                        case 1:
                            cari_id();
                            break;
                        case 2:
                            cari_IDapoteker();
                            break;
                        case 3:
                            cari_NAMAapoteker();
                            break;
                        case 4:
                            cari_tanggalReceipt();
                            break;
                        case 5:
                            cari_NObpjs();
                            break;
                        case 6:
                            cari_namabuyer();
                            break;
                        case 7:
                            cari_namaobat();
                            break;
                        case 8:
                            cari_kodeobat();
                            break;
                        case 9:
                            cari_expobat();
                            break;
                        case 10:
                            cari_NAMAsupplier();
                            break;
                        case 11:
                            cari_jumlahobat();
                            break;
                        case 12:
                            cari_hargatotal();
                            break;
                        case 13:
                            cout << "Keluar";
                            getch();
                            break;
                        default:
                            cout << "Pilih antara angka yang ada di menu (1-13)";
                            getch();
                            break;

        }
    } while (choice2 != 13 );

}

void urutkan_data(){
    system("cls");
    cout << "=====================================================================" << endl;
    cout << "||                             URUTKAN DATA                        ||" << endl;
    cout << "=====================================================================" << endl;

    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }
}

void menuUtama(){
    int input;

    while (true) {
        system("cls");
        cout << "1. Tambah data \t" << endl;
        cout << "2. Lihat data \t" << endl;
        cout << "3. Hapus data \t" << endl;
        cout << "4. Edit data \t" << endl;
        cout << "5. Cari data \t" << endl;
        cout << "6. Urutkan data \t" << endl;
        cout << "7. Keluar \t" << endl;

        while (true) {
            cin >> input;

            if (cin.fail() || input < 1 || input > 7) {
                cout << "Masukkan input yang valid (1-7)" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        if (input == 1) {
            tambah_data();
        }
        if (input == 2) {
            lihat_data();
        }
        if (input == 3) {
            hapus_data();
        }
        if (input == 4) {
            edit_data();
        }
        if (input == 5) {
            cari_data();
        }
        if (input == 6) {
            sort_data();
        }
        if (input == 7) {
            break;
        }
    }
}

int main(){
    get_data(); // Mengambil data dari file txt
    menuUtama();

    return 0;
}
