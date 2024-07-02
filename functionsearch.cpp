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
                            
void cari_tanggalReceipt();
                           
void cari_NObpjs();
                            
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