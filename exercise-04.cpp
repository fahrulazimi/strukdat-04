/*
	Nama 	  : Muhamad Fahrul Azimi
	NPM		  : 140810180027
	Kelas	  : A
	Deskripsi : Program ini membuat list pegawai
	Tanggal	  : 19 Maret 2019
*/

// nama file : exercise-04.cpp

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Elemtlist{
    string nama;
    int gaji;
    string bidang;
    Elemtlist* next;
};
typedef Elemtlist* pointer;
typedef pointer List;

void createList(List& First){
    First=NULL;
}


void createElemt(pointer& p){
    cout << "Input Data Pegawai :" <<endl;
    p = new Elemtlist;
    cout << "Nama	: "; cin.ignore(); getline(cin,p->nama);
    cout << "Gaji	: "; cin >> p->gaji;
    cout << "Bidang	: "; cin >> p->bidang;
    p->next=NULL;
}

void traversal(List First){
    pointer pB;
    cout<<"\tDAFTAR PEGAWAI\n";
    cout<<"     (NAMA  BIDANG  GAJI)\n\n";
    if (First==NULL){
        cout<<"    ^^LIST PEGAWAI KOSONG^^\n";
    }
    else{
        pB=First;
        while(pB!=NULL){
            cout << pB->nama << " " << pB->bidang << "  Rp. " << pB->gaji <<endl;
            pB=pB->next;
        }
    }
}

void insertFirst(List& First,pointer pBaru){
    if (First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast(List& First,pointer pBaru){
    pointer last;
    if (First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=pBaru;
    }
}

void deleteFirst(List& First,pointer pHapus){
    if (First==NULL){
        pHapus=NULL;
        cout<<"^^List Kosong, Tidak ada data yang dihapus^^" <<endl;
        cout << "^^Tekan <Enter> Untuk Mengulang^^";
        getch();
    }
    else if (First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast(List& First,pointer pHapus){
    pointer last,pre;
       if (First==NULL){
        pHapus=NULL;
        cout<<"^^List Kosong, Tidak ada data yang dihapus^^" <<endl;
        cout << "^^Tekan <Enter> Untuk Mengulang^^";
        getch();
    }
    else if (First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        last=First;
        pre=NULL;
        while(last->next!=NULL){
            pre=last;
            last=last->next;
        }
        pHapus=last;
        pre->next=NULL;
    }
}

void menu(List& First,pointer p){
    int pilih;
    do{
        system("cls");
        traversal(First);
        cout<<"\nPilihan Edit/Input Data:" <<endl;
        cout<<"1. Insert First" <<endl;
        cout<<"2. Insert Last" <<endl;
        cout<<"3. Delete First" <<endl;
        cout<<"4. Delete Last" <<endl;
        cout<<"5. Exit" <<endl;
        cout<<"Pilih (1-5): ";cin>>pilih;
        switch (pilih)
        {
            case 1:
            createElemt(p);
            insertFirst(First,p);
            break;

            case 2:
            createElemt(p);
            insertLast(First,p);
            break;

            case 3:
            deleteFirst(First,p);
            break;

            case 4:
            deleteLast(First,p);
            break;
            
            case 5:
            cout << "^^Terima Kasih Telah Menggunakan Program Ini^^";
            break;

            default:
            cout << "^^ANGKA YANG ANDA INPUT SALAH^^" <<endl;
            cout << "^^Tekan <Enter> Untuk Mengulang^^";
            getch();
            break;
        }
    }while(pilih!=5);
}

int main(){
    pointer p;
    List pegawai;
    createList(pegawai);
    menu(pegawai,p);
}
