#include <iostream>

using namespace std;


void cari_IDapoteker(){
    int search_id;

    cout << "Masukkan keyword id yang ingin dicari : ";
    cin >> search_id;

    Pharmacist* temp = HEAD_Pharmacist;
    while (temp != NULL) {
        if(search_id!=temp->no_id){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp->no_id << endl;
            cout << temp->nama_apoteker << endl;
        }
    }
}
                           
void cari_NAMAapoteker(){
    string search_Namaapoteker;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_Namaapoteker;

    Pharmacist* temp = HEAD_Pharmacist;
    while (temp != NULL) {
        if(search_Namaapoteker!=temp->nama_apoteker){
            temp = temp->next;
        }
        else{
            cout << "Data ditemukan !" << endl;
            cout << temp->no_id << endl;
            cout << temp->nama_apoteker << endl;
        }
    }
}
                            
void cari_tanggalReceipt(){
    string search_tanggal;

    cout << "Masukkan keyword nama yang ingin dicari : ";
    cin >> search_tanggal;

    Receipts* temp = HEAD_Receipts;
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

    Buyer* temp = HEAD_Buyer;
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
                            
void cari_namabuyer();
                           
void cari_namaobat();
                            
void cari_kodeobat();
                            
void cari_expobat();
                           
void cari_NAMAsupplier();
                           
void cari_jumlahobat();
                          
void cari_hargatotal();

int main(){

    return 0;
}