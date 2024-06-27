#include <iostream>

using namespace std;

struct pharmacist{
    int no_id;
    string nama_apoteker;
    pharmacist* next;
};
struct medicine{
    string nama_obat;
    int kode_obat;
    string expired_obat;
    string supplier;
    medicine* next;

};
struct buyer{
    string nomor_bpjs;
    string nama_buyer;
   buyer* next;

};
struct receipts{
    string tanggal;
    string nomor_bpjs;
    string nama_buyer;
    string nama_obat;
    int quantity;
    long harga_total;
    receipts* next;

};

void search(){

}
void create_med(){

}
void read_med(){

}
void update_med(){

}
void delete_med(){

}


    pharmacist* HEAD = new pharmacist;
	new pharmacist->no_id = 2;
    HEAD->na
	HEAD->next = NULL;

	pharmacist* B = new pharmacist;
	B->data = 5;
	B->next = NULL;
	HEAD->next = B;

	pharmacist* C = new pharmacist;
	C->data = 7;
	C->next = NULL;
	B->next = C;


















int main(){

    return 0;
}