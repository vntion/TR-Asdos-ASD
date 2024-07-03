#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <cstdlib>
#include <limits>
#include <windows.h>

//////////////////////////////////////////////////
WORD original = 0;



// Line and bar characters
const int lineH1 = 205, linev1 = 186;
const int corner1 = 201, corner2 = 187, corner3 = 200, corner4 = 188;
const int bar1 = 177, bar2 = 219;

// Function to set console text color
void SetConsoleColour(WORD* original, DWORD Colour) {
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *original = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

// Function to reset console text color to original
void ResetConsoleColour(WORD original) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), original);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}











////////////////////////////////////////////////////

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
void Nav_TambahData(){
    system("cls");
    
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
   
    ////////////////////////////////NAVIGASI////////////////////////////////////////
    for(int i=0 ;i<139;i++){
    gotoxy(i,0);cout << (char)lineH1;
    }//bar
    for(int i=0 ;i<139;i++){
    gotoxy(i,2);cout << (char)lineH1;
    }//bar
    gotoxy(50,1);cout << " [ =========== TAMBAH DATA =========== ]";
    SetConsoleColour(&original,FOREGROUND_GREEN |BACKGROUND_INTENSITY);
    gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
    gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
    gotoxy(65,4);cout << "[EDIT DATA]" << endl;
    gotoxy(85,4);cout << "[CARI DATA]" << endl;
    gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
    gotoxy(125,4);cout << "[KELUAR]" << endl;
    for(int i=0 ;i<139;i++){
    gotoxy(i,6);cout << (char)lineH1;
    }//bar
    ////////////////////////////////NAVIGASI////////////////////////////////////////
    gotoxy(5,7);cout << "Kembali: 0" << endl << endl;
}

void tambah_data(){
    int input_jumlah_data; // Jumlah data yang ingin dimasukkan
    int input_no_id, input_kode_obat, input_jumlah, input_no_id_pegawai;
    long input_harga_total, input_nomor_bpjs;
    string input_nama_apoteker, input_nama_obat, input_expired_obat, input_supplier, input_nama_buyer, input_tanggal, nama_obat;

    Nav_TambahData();

    while (true) {
    Nav_TambahData();
        gotoxy(53,8);cout<< "Masukkan Jumlah Data: ";
        cin >> input_jumlah_data;
        if (cin.fail() || input_jumlah_data < 0) {
            Nav_TambahData();
            gotoxy(53,10);cout << "Invalid input, masukkan angka bulat" << endl;
            clearInputBuffer();
            cin.get();
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
        Nav_TambahData();

        //Iterasi gotoxy

        cout << "\tData Apotik ke - " << i << endl << endl;

        while (true) {
            cout << "\t\t\t\t\t\tNo id\t\t : ";
            cin >> input_no_id;
            if (cin.fail() || input_no_id < 1) {
                cout << "\t\t\t\t\t\tInvalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        while (true) {
            cout << "\t\t\t\t\t\tNo id apoteker\t : ";
            cin >> input_no_id_pegawai;
            if (cin.fail() || input_no_id_pegawai < 1) {
                cout << "\t\t\t\t\t\tInvalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        cout << "\t\t\t\t\t\tNama Apoteker\t : ";
        getline(cin, input_nama_apoteker);

        cout << "\t\t\t\t\t\tNama Pasien\t : ";
        getline(cin, input_nama_buyer);

        while (true) {
            cout << "\t\t\t\t\t\tNomor BPJS\t : ";
            cin >> input_nomor_bpjs;
            if (cin.fail() || input_nomor_bpjs < 1) {
                cout << "\t\t\t\t\t\tInvalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        cout << "\t\t\t\t\t\tTanggal\t\t : ";
        getline(cin, input_tanggal);

        cout << "\t\t\t\t\t\tNama Obat\t : ";
        getline(cin, input_nama_obat);

        while (true) {
            cout << "\t\t\t\t\t\tKode Obat \t : ";
            cin >> input_kode_obat;
            if (cin.fail() || input_kode_obat < 1) {
                cout << "\t\t\t\t\t\tInvalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        cout << "\t\t\t\t\t\tExpired Obat\t : ";
        getline(cin, input_expired_obat);

        cout << "\t\t\t\t\t\tSupplier\t : ";
        getline(cin, input_supplier);

        while (true) {
            cout << "\t\t\t\t\t\tJumlah\t\t : ";
            cin >> input_jumlah;
            if (cin.fail() || input_jumlah < 1) {
                cout << "\t\t\t\t\t\tInvalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        while (true) {
            cout << "\t\t\t\t\t\tHarga total\t : ";
            cin >> input_harga_total;
            if (cin.fail() || input_harga_total < 1) {
                cout << "\t\t\t\t\t\tInvalid input, masukkan angka bulat" << endl;
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
    cout << endl << endl<<endl;
    cout << "============================================================================================================================================" << endl;
    cout << "\t\t\t\t\t\t\tData berhasil ditambahkan!"<<endl;
    cout << "============================================================================================================================================" << endl;
    cin.get();
}

void lihat_data(){
    system("cls");
    for(int i=0 ;i<139;i++){
    gotoxy(i,0);cout << (char)lineH1;
    }//bar

    gotoxy(60,1);cout << " LIHAT DATA " << endl;

    for(int i=0 ;i<139;i++){
    gotoxy(i,2);cout << (char)lineH1;
    }//bar
    
    if (HEAD == NULL) {
        cout << "\t\t\t\t\t\tBelum ada data :(";
        getch();
        return;
    }
    cout << endl << endl;
    Data* temp = HEAD;
    int i = 1;

    while (temp != NULL) {
        cout << "\tData Apotik ke - " << i << endl;
        cout << "\t\t\t\t\t\tNo id\t\t : " << temp -> no_id << endl;
        cout << "\t\t\t\t\t\tNo id apoteker\t : " << temp->no_id_apoteker << endl;
        cout << "\t\t\t\t\t\tNama Apoteker\t : " << temp -> nama_apoteker << endl;
        cout << "\t\t\t\t\t\tTanggal\t\t : " << temp -> tanggal << endl;
        cout << "\t\t\t\t\t\tNomor BPJS\t : " << temp -> nomor_bpjs << endl;
        cout << "\t\t\t\t\t\tNama Buyer\t : " << temp -> nama_buyer << endl;
        cout << "\t\t\t\t\t\tNama Obat\t : " << temp -> nama_obat << endl;
        cout << "\t\t\t\t\t\tKode Obat \t : " << temp -> kode_obat << endl;
        cout << "\t\t\t\t\t\tExpired Obat\t : " << temp -> expired_obat << endl;
        cout << "\t\t\t\t\t\tSupplier\t : " << temp -> supplier << endl;
        cout << "\t\t\t\t\t\tJumlah\t\t : " << temp -> jumlah << endl;
        cout << "\t\t\t\t\t\tHarga total\t : " << temp -> harga_total << endl << endl;
        temp = temp -> next;
        i++;
    }
    cout <<endl;
    cout << "============================================================================================================================================" << endl;
    getch();
}

void hapus_data(){
    //////////////////////////////////////////////////////////////////////////////////
    system("cls");
    for(int i=0 ;i<139;i++){
    gotoxy(i,0);cout << (char)lineH1;
    }//bar

    gotoxy(60,1);cout << " HAPUS DATA " << endl;

    for(int i=0 ;i<139;i++){
    gotoxy(i,2);cout << (char)lineH1;
    }//bar
    cout << endl << endl;
    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }
    cout << "Kembali: 0" << endl << endl;
    //////////////////////////////////////////////////////////////////////////////////

    // Render tabel data
    Data* temp = HEAD;
    int i = 1;

    while (temp != NULL) {
        cout << "\tData Apotik ke - " << i << endl;
        cout << "\t\t\t\t\t\tNo id\t\t : " << temp -> no_id << endl;
        cout << "\t\t\t\t\t\tNo id apoteker\t : " << temp->no_id_apoteker << endl;
        cout << "\t\t\t\t\t\tNama Apoteker\t : " << temp -> nama_apoteker << endl;
        cout << "\t\t\t\t\t\tTanggal\t\t : " << temp -> tanggal << endl;
        cout << "\t\t\t\t\t\tNomor BPJS\t : " << temp -> nomor_bpjs << endl;
        cout << "\t\t\t\t\t\tNama Buyer\t : " << temp -> nama_buyer << endl;
        cout << "\t\t\t\t\t\tNama Obat\t : " << temp -> nama_obat << endl;
        cout << "\t\t\t\t\t\tKode Obat \t : " << temp -> kode_obat << endl;
        cout << "\t\t\t\t\t\tExpired Obat\t : " << temp -> expired_obat << endl;
        cout << "\t\t\t\t\t\tSupplier\t : " << temp -> supplier << endl;
        cout << "\t\t\t\t\t\tJumlah\t\t : " << temp -> jumlah << endl;
        cout << "\t\t\t\t\t\tHarga total\t : " << temp -> harga_total << endl << endl;
        temp = temp -> next;
        i++;
    }
    cout << endl;
    cout << "============================================================================================================================================" << endl;
    cout << endl << endl;
    // Pencarian ID
    Data* search = HEAD;
    int cari_id;
    bool found = false;
    while (true) {
        while (true) {
            cout << "\tCari No ID yang mau dihapus : ";
            cin >> cari_id;
            if (cin.fail() || cari_id < 0) {
                cout << "\t input, masukkan angka bulat" << endl;
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
            cout << "\t tidak ditemukan!" << endl;
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
    cout << endl << endl;
    cout << "============================================================================================================================================" << endl;
    cout << "\t\t\t\t\t\tDATA BERHASIL DIHAPUS"<<endl;
    cout << "============================================================================================================================================" << endl;
    getch();

}

void edit_data(){
   system("cls");
    for(int i=0 ;i<139;i++){
    gotoxy(i,0);cout << (char)lineH1;
    }//bar

    gotoxy(60,1);cout << " EDIT DATA " << endl;

    for(int i=0 ;i<139;i++){
    gotoxy(i,2);cout << (char)lineH1;
    }//bar
    cout << endl << endl;

    if (HEAD == NULL) {
        cout << "\t\t\t\t\t\tBelum ada data :(";
        getch();
        return;
    }
    cout << "\tKembali: 0" << endl << endl;

    Data* temp = HEAD;

    int i = 1;

    while (temp != NULL) {
        cout << "\tData Apotik ke - " << i << endl;
        cout << "\t\t\t\t\t\tNo id\t\t : " << temp -> no_id << endl;
        cout << "\t\t\t\t\t\tNo id apoteker\t : " << temp->no_id_apoteker << endl;
        cout << "\t\t\t\t\t\tNama Apoteker\t : " << temp -> nama_apoteker << endl;
        cout << "\t\t\t\t\t\tTanggal\t\t : " << temp -> tanggal << endl;
        cout << "\t\t\t\t\t\tNomor BPJS\t : " << temp -> nomor_bpjs << endl;
        cout << "\t\t\t\t\t\tNama Buyer\t : " << temp -> nama_buyer << endl;
        cout << "\t\t\t\t\t\tNama Obat\t : " << temp -> nama_obat << endl;
        cout << "\t\t\t\t\t\tKode Obat \t : " << temp -> kode_obat << endl;
        cout << "\t\t\t\t\t\tExpired Obat\t : " << temp -> expired_obat << endl;
        cout << "\t\t\t\t\t\tSupplier\t : " << temp -> supplier << endl;
        cout << "\t\t\t\t\t\tJumlah\t\t : " << temp -> jumlah << endl;
        cout << "\t\t\t\t\t\tHarga total\t : " << temp -> harga_total << endl << endl;
        temp = temp -> next;
        i++;
    }
    cout << endl;
    cout << "============================================================================================================================================" << endl;
    cout << endl << endl;

    // Cari ID
    int cari_id;
    bool found = false;
    while (true) {
        
        cout << "\t\t\t\t\t\tCari No ID yang mau di edit :";
        while (true) {
            cin >> cari_id;
            if (cin.fail() || cari_id < 0) {
                cout << "\t\t\t\t\t\tInvalid input, masukkan angka bulat" << endl;
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
            cout << "\t\t\t\t\t\tData tidak ditemukan!" << endl;
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
    ///////////////////////////////////////////////////////////////////////////////////
    system("cls");
    for(int i=0 ;i<139;i++){
    gotoxy(i,0);cout << (char)lineH1;
    }//bar

    gotoxy(60,1);cout << " EDIT DATA " << endl;

    for(int i=0 ;i<139;i++){
    gotoxy(i,2);cout << (char)lineH1;
    }//bar
    cout << endl << endl;
    if (HEAD == NULL) {
        cout << "\t\t\t\t\t\tBelum ada data :(";
        getch();
        return;
    }
    cout << "Kembali: 0" << endl << endl;
    //////////////////////////////////////////////////////////////////////////////////
        
        gotoxy(50,6);cout << "Edit berdasarkan apa : "     << endl;
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
        if(search_idpengisian == temp->no_id){
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
    long search_bpjs;

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


void sort_ID(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->no_id > ptr1->next->no_id) {
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

void sort_IDapoteker(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->no_id_apoteker > ptr1->next->no_id_apoteker) {
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


void sort_NAMAapoteker(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->no_id_apoteker > ptr1->next->no_id_apoteker) {
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

void sort_tanggalReceipt(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->tanggal > ptr1->next->tanggal) {
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

void sort_NObpjs(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->nomor_bpjs > ptr1->nomor_bpjs) {
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

void sort_namabuyer(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->nama_buyer > ptr1->next->nama_buyer) {
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

void sort_namaobat(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->nama_obat > ptr1->next->nama_obat) {
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

void sort_kodeobat(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->kode_obat > ptr1->next->kode_obat) {
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

void sort_expobat(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->expired_obat > ptr1->next->expired_obat) {
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

void sort_NAMAsupplier(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->supplier > ptr1->next->supplier) {
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

void sort_jumlahobat(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->jumlah > ptr1->next->jumlah) {
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

void sort_hargatotal(Data*& HEAD){
    int swapped;
  Data* ptr1;
  Data* lptr = NULL;

  if (HEAD == NULL)
    return;

  do {
    swapped = 0;
    ptr1 = HEAD;

    while (ptr1->next != lptr) {
      if (ptr1->harga_total > ptr1->next->harga_total) {
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
   
    int choice1;

    do{
    ///////////////////////////////////////////////////////////////////////////////////
    system("cls");
    for(int i=0 ;i<139;i++){
    gotoxy(i,0);cout << (char)lineH1;
    }//bar

    gotoxy(60,1);cout << " URUTKAN DATA" << endl;

    for(int i=0 ;i<139;i++){
    gotoxy(i,2);cout << (char)lineH1;
    }//bar
    cout << endl << endl;
    if (HEAD == NULL) {
        cout << "\t\t\t\t\t\tBelum ada data :(";
        getch();
        return;
    }
    cout << endl;
    //////////////////////////////////////////////////////////////////////////////////
    
        cout << "Sort berdasarkan apa : "     << endl;
         cout << "1. NO ID \t"<< endl;
        cout << "2. NO ID PEGAWAI \t"<< endl;
        cout << "3. NAMA APOTEKER \t"<< endl;
        cout << "4. TANGGAL \t"<< endl;
        cout << "5. NO BPJS \t"<< endl;
        cout << "6. NAMA BUYER \t"<< endl;
        cout << "7. NAMA OBAT \t"<< endl;
        cout << "8. KODE OBAT \t"<< endl;
        cout << "9. EXPIRED OBAT \t"     << endl;
        cout << "10. SUPPLIER \t"     << endl;
        cout << "11. JUMLAH \t"      << endl;
        cout << "12. HARGA TOTAL \t" << endl;
        cout << "13. KEMBALI \t"      << endl;

        while (true) {
                cin >> choice1;

                if (cin.fail() || choice1 < 0) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

        switch (choice1) {
                        case 1:
                            sort_ID(HEAD);
                            printSorted(HEAD);
                            break;
                        case 2:
                            sort_IDapoteker(HEAD);
                            printSorted(HEAD);
                            break;
                        case 3:
                            sort_NAMAapoteker(HEAD);
                            printSorted(HEAD);
                            break;
                        case 4:
                            sort_tanggalReceipt(HEAD);
                            printSorted(HEAD);
                            break;
                        case 5:
                            sort_NObpjs(HEAD);
                            printSorted(HEAD);
                            break;
                        case 6:
                            sort_namabuyer(HEAD);
                            printSorted(HEAD);
                            break;
                        case 7:
                            sort_namaobat(HEAD);
                            printSorted(HEAD);
                            break;
                        case 8:
                            sort_kodeobat(HEAD);
                            printSorted(HEAD);
                            break;
                        case 9:
                            sort_expobat(HEAD);
                            printSorted(HEAD);
                            break;
                        case 10:
                            sort_NAMAsupplier(HEAD);
                            printSorted(HEAD);
                            break;
                        case 11:
                            sort_jumlahobat(HEAD);
                            printSorted(HEAD);
                            break;
                        case 12:
                            sort_hargatotal(HEAD);
                            printSorted(HEAD);
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

    }while(choice1 !=13);

}

void cari_data(){

    

    if (HEAD == NULL) {
        cout << "Belum ada data :(";
        getch();
        return;
    }
    int choice2;


    do{
    ///////////////////////////////////////////////////////////////////////////////////
    system("cls");
    for(int i=0 ;i<139;i++){
    gotoxy(i,0);cout << (char)lineH1;
    }//bar

    gotoxy(60,1);cout << "CARI DATA " << endl;

    for(int i=0 ;i<139;i++){
    gotoxy(i,2);cout << (char)lineH1;
    }//bar
    cout << endl << endl;
    if (HEAD == NULL) {
        cout << "\t\t\t\t\t\tBelum ada data :(";
        getch();
        return;
    }
    cout<< endl;
    //////////////////////////////////////////////////////////////////////////////////
        cout << "Cari berdasarkan apa : "     << endl;
         cout << "1. NO ID \t"<< endl;
        cout << "2. NO ID PEGAWAI \t"<< endl;
        cout << "3. NAMA APOTEKER \t"<< endl;
        cout << "4. TANGGAL \t"<< endl;
        cout << "5. NO BPJS \t"<< endl;
        cout << "6. NAMA BUYER \t"<< endl;
        cout << "7. NAMA OBAT \t"<< endl;
        cout << "8. KODE OBAT \t"<< endl;
        cout << "9. EXPIRED OBAT \t"     << endl;
        cout << "10. SUPPLIER \t"     << endl;
        cout << "11. JUMLAH \t"      << endl;
        cout << "12. HARGA TOTAL \t" << endl;
        cout << "13. KEMBALI \t"      << endl;

        while (true) {
                cin >> choice2;

                if (cin.fail() || choice2 < 0) {
                cout << "Invalid input, masukkan angka bulat" << endl;
                clearInputBuffer();
            } else {
                break;
            }
        }
        clearInputBuffer();

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
    }while(choice2 !=13);

}

void menuUtama(){
    int input;

    while (true) {
        system("cls");
        int key,select;
        for(int i=0 ;i<139;i++){
            gotoxy(i,0);cout << (char)lineH1;
        }//bar
        for(int i=0 ;i<139;i++){
            gotoxy(i,2);cout << (char)lineH1;
        }//bar
        gotoxy(50,1);cout << " [ =========== MENU UTAMA =========== ]";
        gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
        gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
        gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
        gotoxy(65,4);cout << "[EDIT DATA]" << endl;
        gotoxy(85,4);cout << "[CARI DATA]" << endl;
        gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
        gotoxy(125,4);cout << "[KELUAR]" << endl;
        for(int i=0 ;i<139;i++){
            gotoxy(i,6);cout << (char)lineH1;
        }//bar

        //navigation
        while((key = getch()) != 13 ){
                if (key == 77)
            {
            select++;
            if (select > 7)
                {
                select = 1;
                }
            
            }
                else if (key == 75)
            {
            select--;
            if (select < 1)
                {
                select = 7;
                }
            }

            if (select == 1){
                    system("cls");
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,0);cout << (char)lineH1;
                    }//bar
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,2);cout << (char)lineH1;
                    }//bar
                    gotoxy(50,1);cout << " [ =========== MENU UTAMA =========== ]";
                    SetConsoleColour(&original,FOREGROUND_GREEN |BACKGROUND_INTENSITY);
                    gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
                    gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
                    gotoxy(65,4);cout << "[EDIT DATA]" << endl;
                    gotoxy(85,4);cout << "[CARI DATA]" << endl;
                    gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
                    gotoxy(125,4);cout << "[KELUAR]" << endl;
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,6);cout << (char)lineH1;
                    }//bar
            }

            if (select == 2){
                    system("cls");
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,0);cout << (char)lineH1;
                    }//bar
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,2);cout << (char)lineH1;
                    }//bar
                    gotoxy(50,1);cout << " [ =========== MENU UTAMA =========== ]";
                    gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
                    SetConsoleColour(&original,FOREGROUND_GREEN |BACKGROUND_INTENSITY);
                    gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
                    gotoxy(65,4);cout << "[EDIT DATA]" << endl;
                    gotoxy(85,4);cout << "[CARI DATA]" << endl;
                    gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
                    gotoxy(125,4);cout << "[KELUAR]" << endl;
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,6);cout << (char)lineH1;
                    }//bar
            }

            if (select == 3){
                    system("cls");
                    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,0);cout << (char)lineH1;
                    }//bar
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,2);cout << (char)lineH1;
                    }//bar
                    gotoxy(50,1);cout << " [ =========== MENU UTAMA =========== ]";
                    gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
                    gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
                    SetConsoleColour(&original,FOREGROUND_GREEN |BACKGROUND_INTENSITY);
                    gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    gotoxy(65,4);cout << "[EDIT DATA]" << endl;
                    gotoxy(85,4);cout << "[CARI DATA]" << endl;
                    gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
                    gotoxy(125,4);cout << "[KELUAR]" << endl;
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,6);cout << (char)lineH1;
                    }//bar
            }

            if (select == 4){
                    system("cls");
                    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,0);cout << (char)lineH1;
                    }//bar
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,2);cout << (char)lineH1;
                    }//bar
                    gotoxy(50,1);cout << " [ =========== MENU UTAMA =========== ]";
                    gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
                    gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
                    gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
                    SetConsoleColour(&original,FOREGROUND_GREEN |BACKGROUND_INTENSITY);
                    gotoxy(65,4);cout << "[EDIT DATA]" << endl;
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    gotoxy(85,4);cout << "[CARI DATA]" << endl;
                    gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
                    gotoxy(125,4);cout << "[KELUAR]" << endl;
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,6);cout << (char)lineH1;
                    }//bar
            }

            if (select == 5){
                    system("cls");
                    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,0);cout << (char)lineH1;
                    }//bar
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,2);cout << (char)lineH1;
                    }//bar
                    gotoxy(50,1);cout << " [ =========== MENU UTAMA =========== ]";
                    gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
                    gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
                    gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
                    gotoxy(65,4);cout << "[EDIT DATA]" << endl;
                    SetConsoleColour(&original,FOREGROUND_GREEN |BACKGROUND_INTENSITY);
                    gotoxy(85,4);cout << "[CARI DATA]" << endl;
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
                    gotoxy(125,4);cout << "[KELUAR]" << endl;
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,6);cout << (char)lineH1;
                    }//bar
            }

            if (select == 6){
                    system("cls");
                    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,0);cout << (char)lineH1;
                    }//bar
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,2);cout << (char)lineH1;
                    }//bar
                    gotoxy(50,1);cout << " [ =========== MENU UTAMA =========== ]";
                    gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
                    gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
                    gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
                    gotoxy(65,4);cout << "[EDIT DATA]" << endl;
                    gotoxy(85,4);cout << "[CARI DATA]" << endl;
                    SetConsoleColour(&original,FOREGROUND_GREEN |BACKGROUND_INTENSITY);
                    gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    gotoxy(125,4);cout << "[KELUAR]" << endl;
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,6);cout << (char)lineH1;
                    }//bar
            }

            if (select == 7){
                    system("cls");
                    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,0);cout << (char)lineH1;
                    }//bar
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,2);cout << (char)lineH1;
                    }//bar
                    gotoxy(50,1);cout << " [ =========== MENU UTAMA =========== ]";
                    gotoxy(5,4);cout << "[TAMBAH DATA]" << endl;
                    gotoxy(25,4);cout << "[LIHAT DATA]" << endl;
                    gotoxy(45,4);cout << "[HAPUS DATA]" << endl;
                    gotoxy(65,4);cout << "[EDIT DATA]" << endl;
                    gotoxy(85,4);cout << "[CARI DATA]" << endl;
                    gotoxy(105,4);cout << "[URUTKAN DATA]" << endl;
                    SetConsoleColour(&original,FOREGROUND_GREEN |BACKGROUND_INTENSITY);
                    gotoxy(125,4);cout << "[KELUAR]" << endl;
                    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                    for(int i=0 ;i<139;i++){
                    gotoxy(i,6);cout << (char)lineH1;
                    }//bar
            }

        }
        
        // while (true) {
        //     cin >> input;

        //     if (cin.fail() || input < 1 || input > 7) {
        //         cout << "Masukkan input yang valid (1-7)" << endl;
        //         clearInputBuffer();
        //     } else {
        //         break;
        //     }
        // }
        // clearInputBuffer();

        if (select == 1) {
            tambah_data();
        }
        if (select == 2) {
            lihat_data();
        }
        if (select == 3) {
            hapus_data();
        }
        if (select == 4) {
            edit_data();
        }
        if (select == 5) {
            cari_data();
        }
        if (select == 6) {
            sort_data();
        }
        if (select == 7) {
            break;
        }
    }
}


int main(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleColour(&original,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    get_data(); // Mengambil data dari file txt
    menuUtama();

    return 0;
}
