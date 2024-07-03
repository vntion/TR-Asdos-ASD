#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;


void cari_IDapoteker(){
    int search_id;

    do {
        cout << "Masukkan keyword id yang ingin dicari : ";
        cin >> search_id;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Masukkan input yang valid.\n";
        }
    } while (true);
    
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_id!=temp->no_id_apoteker){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp->no_id_apoteker << endl;
            cout << temp->nama_apoteker << endl;
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
                           
void cari_NAMAapoteker(){
    string search_Namaapoteker;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_Namaapoteker;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_Namaapoteker!=temp->nama_apoteker){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp->no_id_apoteker << endl;
            cout << temp->nama_apoteker << endl;
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
                            
void cari_tanggalReceipt(){
    string search_tanggal;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_tanggal;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_tanggal!=temp->tanggal){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> tanggal << endl;
            cout << temp-> jumlah << endl;
            cout << temp-> harga_total << endl;
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
                           
void cari_NObpjs(){
    string search_bpjs;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_bpjs;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;
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
                            
void cari_namabuyer(){
    string search_bpjs;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_bpjs;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;
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
                           
void cari_namaobat(){
    string search_obat;


    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_obat;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_obat!=temp->nama_obat){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp-> nama_obat << endl;
            cout << temp -> kode_obat << endl;
            cout << temp -> expired_obat << endl;
            cout << temp -> supplier << endl;
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
                            
void cari_kodeobat(){
    string search_idobat;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_idobat;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_idobat!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp-> nama_obat << endl;
            cout << temp -> kode_obat << endl;
            cout << temp -> expired_obat << endl;
            cout << temp -> supplier << endl;
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
                            
void cari_expobat(){
    string search_exp;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_exp;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_exp!=temp->expired_obat){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp-> nama_obat << endl;
            cout << temp -> kode_obat << endl;
            cout << temp -> expired_obat << endl;
            cout << temp -> supplier << endl;
            found = true;
            break;
            getchar();
            getchar();
        }
    }

    if(!found){
        cout << "data tidak ada";
        getchar();
        getchar();
    }
}
                           
void cari_NAMAsupplier(){
    string search_supplier;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_supplier;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_supplier!=temp->supplier){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp-> nama_obat << endl;
            cout << temp -> kode_obat << endl;
            cout << temp -> expired_obat << endl;
            cout << temp -> supplier << endl;
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
                           
void cari_jumlahobat(){
    string search_jmlobat;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_jmlobat;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_jmlobat!=temp->jumlah){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> tanggal << endl;
            cout << temp -> jumlah << endl;
            cout << temp -> harga_total << endl;
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
                          
void cari_hargatotal(){
    string search_bpjs;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_bpjs;
    bool found=false;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;
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

int main(){

    return 0;
}