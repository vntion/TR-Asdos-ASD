#include <iostream>
#include <stdlib.h>

using namespace std;


void cari_IDapoteker(){
    int search_id;

    cout << "Masukkan keyword id yang ingin dicari : ";
    cin >> search_id;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_id!=temp->no_id_apoteker){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp->no_id_apoteker << endl;
            cout << temp->nama_apoteker << endl;
        }
    }
}
                           
void cari_NAMAapoteker(){
    string search_Namaapoteker;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_Namaapoteker;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_Namaapoteker!=temp->nama_apoteker){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp->no_id_apoteker << endl;
            cout << temp->nama_apoteker << endl;
        }
    }
}
                            
void cari_tanggalReceipt(){
    string search_tanggal;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_tanggal;

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
        }
    }
}
                           
void cari_NObpjs(){
    string search_bpjs;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_bpjs;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;
        }
    }
}
                            
void cari_namabuyer(){
    string search_bpjs;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_bpjs;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;
        }
    }
}
                           
void cari_namaobat(){
    string search_obat;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_obat;

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
        }
    }
}
                            
void cari_kodeobat(){
    string search_idobat;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_idobat;

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
        }
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
        }
}
                           
void cari_NAMAsupplier(){
    string search_bpjs;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_bpjs;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;
        }
    }
}
                           
void cari_jumlahobat(){
    string search_bpjs;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_bpjs;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;
        }
    }
}
                          
void cari_hargatotal(){
    string search_bpjs;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_bpjs;

    Data* temp = HEAD;
    while (temp != NULL) {
        if(search_bpjs!=temp->nomor_bpjs){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp -> nomor_bpjs << endl;
            cout << temp-> nama_buyer << endl;
        }
    }
}

int main(){

    return 0;
}