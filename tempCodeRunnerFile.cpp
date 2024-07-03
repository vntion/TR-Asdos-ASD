
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
    cout << "Kembali: 0" << endl << endl;