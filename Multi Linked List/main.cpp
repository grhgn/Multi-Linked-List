#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "DoubleLinkedList.h"
#include "Relasis.h"


using namespace std;

int main()
{
    int pil;
    list_teller Ltell;
    list_customer Lcustom;
    infotype_teller X;
    X.nama = "Rakha";
    X.kontak = "08112264401";
    infotype_teller Y;
    Y.nama = "Rafi";
    Y.kontak = "08122081202";
    infotype_customer A;
    A.nama = "IpulHap";
    A.alamat = "Komp.Terus Jaya";
    infotype_customer B;
    CreateTeller(Ltell);
    CreateCustomer(Lcustom);
    insertTeller(Ltell, alokasiTeller(X));
    insertTeller(Ltell, alokasiTeller(Y));
    insertCustomer(Lcustom, alokasiCustomer(A));
    address_relasi x = alokasiRelasi(first(Lcustom), first(Ltell));
    address_relasi y = alokasiRelasi(first(Lcustom), last(Ltell));
    insertRelasiCustomer(first(Lcustom), x);
    insertRelasiTeller(first(Ltell), x);
    insertRelasiCustomer(first(Lcustom), y);
    insertRelasiTeller(last(Ltell), y);
    menu:
    system("cls");
    cout<<"~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
    cout<<"|          Bank Ada-ada Saja          |"<<endl;
    cout<<"~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
    cout<<"|         ' Menu Transaksi '          |"<<endl;
    cout<<"| 1. Pendaftaran Customer             |"<<endl;
    cout<<"| 2. Pendaftaran Teller               |"<<endl;
    cout<<"| 3. Cetak Nasabah Yang Berkunjung    |"<<endl;
    cout<<"| 4. Cetak Teller Yang Melayani       |"<<endl;
    cout<<"| 5. Mengunjungi Teller               |"<<endl;
    cout<<"| 6. Melayani Customer                |"<<endl;
    cout<<"| 7. Hapus Customer                   |"<<endl;
    cout<<"| 8. Hapus Teller                     |"<<endl;
    cout<<"| 9. Hapus Relasi Customer            |"<<endl;
    cout<<"| 10. Hapus Relasi Teller             |"<<endl;
    cout<<"| 11. Cari Customer                   |"<<endl;
    cout<<"| 12. Cari Teller                     |"<<endl;
    cout<<"| 13. Teller Dengan Nasabah Tersedikit|"<<endl;
    cout<<"| 14. Teller Dengan Nasabah Terbanyak |"<<endl;
    cout<<"| 15. Keluar Aplikasi                 |"<<endl;
    cout<<"====================================="<<endl;
    cout<<"Pilihan anda --> ";cin>>pil;
    system("cls");

    switch(pil){
        case 1:{
            cout<<endl;
            cout<<"Nama Anda : ";cin>>A.nama;
            cout<<"Alamat Anda : ";cin>>A.alamat;
            address_customer P = findCustomer(Lcustom, A);
            cout<<endl;
            if (P != NULL){
                cout<<"Nama Sudah Terdaftar";
                getch();
                system("cls");
                goto menu;
            }
            else{
                insertCustomer(Lcustom, alokasiCustomer(A));
                cout<<"Data Telah Dimasukkan";
                getch();
                system("cls");
                goto menu;
            }
        };
        case 2:{
            cout<<endl;
            cout<<"Nama Anda : ";cin>>X.nama;
            cout<<"Kontak Anda : ";cin>>X.kontak;
            address_teller P = findTeller(Ltell, X);
            cout<<endl;
            if (P != NULL){
                cout<<"Nama Sudah Terdaftar";
                getch();
                system("cls");
            }
            else{
                infotype_customer Z;
                insertTeller(Ltell, alokasiTeller(X));
                cout<<"Data Telah Dimasukkan";
                getch();
                system("cls");
                printCustomer(Lcustom);
                cout<<"Anda Ingin Melayani Nasabah Mana = ";cin>>Z.nama;
                address_customer Q = findCustomer(Lcustom, Z);
                if(Q == NULL){
                    cout<<"Nama Ini Tidak Ditemukan";
                    getch();
                    deleteFirstTeller(Ltell, P);
                    system("cls");
                    goto menu;
                }
                else{
                    address_relasi R = alokasiRelasi(Q, first(Ltell));
                    insertRelasiCustomer(Q, R);
                    insertRelasiTeller(first(Ltell), R);
                    cout<<"Sukses";
                    getch();
                    system("cls");
                    goto menu;
                }
            }
            goto menu;
        };
        case 3:{
            cout<<endl;
            printCustomer(Lcustom);
            cout<<endl;
            cout<<"Kembali Ke Menu Utama";
            getch();
            system("cls");
            goto menu;
        };
        case 4:{
            cout<<endl;
            printTeller(Ltell);
            cout<<endl;
            cout<<"Kembali Ke Menu Utama";
            getch();
            system("cls");
            goto menu;
        };
        case 5:{
            cout<<endl;
            printCustomer(Lcustom);
            cout<<endl;
            infotype_customer Z;
            infotype_teller B;
            cout<<"Nama Anda = ";cin>>Z.nama;
            address_customer P = findCustomer(Lcustom, Z);
            if(P == NULL){
                cout<<"Nama Ini Tidak Ditemukan";
                getch();
                system("cls");
                goto menu;
            }
            else{
                system("cls");
                printTeller(Ltell);
                cout<<"Anda Ingin Menunjungi Teller Mana = ";cin>>B.nama;
                address_teller Q = findTeller(Ltell, B);
                if(Q == NULL){
                    cout<<"Nama Ini Tidak Ditemukan";
                    getch();
                    system("cls");
                    goto menu;
                }
                else{
                        infotype_teller C;
                    C.nama = "asd";
                    address_relasi R = alokasiRelasi(P, Q);
                    address_relasi S = findRelasiTeller(Q, Z);
                    cout<<endl;
                    if (maxTeller(P) == true){
                        cout<<"Anda Sudah Terlalu Banyak Mengungungi Teller";
                        getch();
                        system("cls");
                        goto menu;
                    }
                    else{
                        if (S == NULL){
                            insertRelasiCustomer(P, R);
                            insertRelasiTeller(Q, R);
                            cout<<"Sukses";
                            getch();
                            system("cls");
                            goto menu;
                        }
                        else {
                            cout<<"Anda Sudah Mengunjungi Teller Ini";
                            getch();
                            system("cls");
                            goto menu;
                        }
                    }
                }
            }
        };
        case 6:{
            cout<<endl;
            printTeller(Ltell);
            cout<<endl;
            infotype_customer Z;
            infotype_teller B;
            cout<<"Nama Anda = ";cin>>B.nama;
            address_teller P = findTeller(Ltell, B);
            if(P == NULL){
                cout<<"Nama Ini Tidak Ditemukan";
                getch();
                system("cls");
                goto menu;
            }
            else{
                system("cls");
                printCustomer(Lcustom);
                cout<<"Anda Ingin Melayani Nasabah Mana = ";cin>>Z.nama;
                address_customer Q = findCustomer(Lcustom, Z);
                if(Q == NULL){
                    cout<<"Nama Ini Tidak Ditemukan";
                    getch();
                    system("cls");
                    goto menu;
                }
                else{
                    address_relasi R = alokasiRelasi(Q, P);
                    address_relasi S = findRelasiTeller(P, info(Q));
                    if (S == NULL){
                        insertRelasiCustomer(Q, R);
                        insertRelasiTeller(P, R);
                        cout<<"Sukses";
                        getch();
                        system("cls");
                        goto menu;
                    }
                    else {
                        cout<<"Anda Sudah Mengunjungi Teller Ini";
                        getch();
                        system("cls");
                        goto menu;
                    }
                }
            }
        };
        case 7:{
            cout<<endl;
            printCustomer(Lcustom);
            infotype_customer Z;
            cout<<endl;
            if (first(Lcustom) == NULL){
                cout<<"Kembali Ke Menu Utama";
                getch();
                system("cls");
                goto menu;
            }
            else {
                cout<<"Nama Customer Yang Ingin Dihapus = ";cin>>Z.nama;
                address_customer P = findCustomer(Lcustom, Z);
                if(P == NULL){
                    cout<<"Nama Ini Tidak Ditemukan";
                    getch();
                    system("cls");
                    goto menu;
                }
                else{
                    address_relasi Q = Relasi(P);
                    while(Q != NULL){
                      deleteRelasiTeller(Teller(Q), Q);
                      Q = nextCustomer(Q);
                    };
                    deleteCustomer(Lcustom, Z);
                    cout<<"Kembali Ke Menu Utama";
                    getch();
                    system("cls");
                    goto menu;
                }
            }
        };
        case 8:{
            cout<<endl;
            printTeller(Ltell);
            infotype_teller Z;
            cout<<endl;
            if (first(Ltell) == NULL){
                cout<<"Kembali Ke Menu Utama";
                getch();
                system("cls");
                goto menu;
            }
            else {
                cout<<"Nama Teller Yang Ingin Dihapus = ";cin>>Z.nama;
                address_teller P = findTeller(Ltell, Z);
                if(P == NULL){
                    cout<<"Nama Ini Tidak Ditemukan";
                    getch();
                    system("cls");
                    goto menu;
                }
                else{
                    address_relasi Q = Relasi(P);
                    while(Q != NULL){
                      deleteRelasiCustomer(Customer(Q), Q);
                      Q = nextTeller(Q);
                    };
                    deleteTeller(Ltell, Z);
                    cout<<"Kembali Ke Menu Utama";
                    getch();
                    system("cls");
                    goto menu;
                }
            }
        };
        case 9:{
            cout<<endl;
            printCustomer(Lcustom);
            cout<<endl;
            infotype_customer Z;
            infotype_teller B;
            cout<<"Nama Anda = ";cin>>Z.nama;
            address_customer P = findCustomer(Lcustom, Z);
            if(P == NULL){
                cout<<"Nama Ini Tidak Ditemukan";
                getch();
                system("cls");
                goto menu;
            }
            else{
                system("cls");
                printRelasiCustomer(P);
                cout<<"Anda Ingin Menghapus Mana = ";cin>>B.nama;
                address_teller Q = findTeller(Ltell, B);
                if(Q == NULL){
                    cout<<"Nama Ini Tidak Ditemukan";
                    getch();
                    system("cls");
                    goto menu;
                }
                else{
                    address_relasi R = findRelasiCustomer(P, B);
                    deleteRelasiCustomer(P, R);
                    deleteRelasiTeller(Q, R);
                    cout<<"Sukses";
                    getch();
                    system("cls");
                    goto menu;
                }
            }
        };
        case 10:{
            cout<<endl;
            printTeller(Ltell);
            cout<<endl;
            infotype_customer Z;
            infotype_teller B;
            cout<<"Nama Anda = ";cin>>B.nama;
            address_teller P = findTeller(Ltell, B);
            if(P == NULL){
                cout<<"Nama Ini Tidak Ditemukan";
                getch();
                system("cls");
                goto menu;
            }
            else{
                system("cls");
                printRelasiTeller(P);
                cout<<"Anda Ingin Menghapus Mana = ";cin>>Z.nama;
                address_customer Q = findCustomer(Lcustom, Z);
                if(Q == NULL){
                    cout<<"Nama Ini Tidak Ditemukan";
                    getch();
                    system("cls");
                    goto menu;
                }
                else{
                    if(minCustomer(P) == true){
                        cout<<"Anda Minimal Memiliki 1 Nasabah";
                        getch();
                        system("cls");
                        goto menu;
                    }
                    else{
                        address_relasi R = findRelasiCustomer(Q, B);
                        deleteRelasiTeller(P, R);
                        deleteRelasiCustomer(Q, R);
                        cout<<"Sukses";
                        getch();
                        system("cls");
                        goto menu;
                    }
                }
            }
        };
        case 11:{
            cout<<endl;
            infotype_customer Z;
            cout<<"Anda Ingin Cari Siapa = ";cin>>Z.nama;
            cout<<endl;
            address_customer Q = findCustomer(Lcustom, Z);
            if (Q == NULL){
                cout<<"Pencarian Tidak Ditemukan";
                getch();
                system("cls");
                goto menu;
            }
            else{
                cout<<"Nama Customer = "<<info(Q).nama<<endl;
                cout<<"Alamat Customer = "<<info(Q).alamat<<endl;
                cout<<"Teller = ";
                address_relasi R = Relasi(Q);
                while (R != NULL){
                    cout<<info(Teller(R)).nama<<" ,";
                    R = nextCustomer(R);
                }
                cout<<endl;
                cout<<endl;
                cout<<"Kembali Ke Menu Utama";
                getch();
                system("cls");
                goto menu;
            };
        };
        case 12:{
            cout<<endl;
            infotype_teller Z;
            cout<<"Anda Ingin Cari Siapa = ";cin>>Z.nama;
            cout<<endl;
            address_teller Q = findTeller(Ltell, Z);
            if (Q == NULL){
                cout<<"Pencarian Tidak Ditemukan";
                getch();
                system("cls");
                goto menu;
            }
            else{
                cout<<"Nama Teller = "<<info(Q).nama<<endl;
                cout<<"Kontak Teller = "<<info(Q).kontak<<endl;
                cout<<"Nasabah = ";
                address_relasi R = Relasi(Q);
                while (R != NULL){
                    cout<<info(Customer(R)).nama<<" ,";
                    R = nextTeller(R);
                }
                cout<<endl;
                cout<<endl;
                cout<<"Kembali Ke Menu Utama";
                getch();
                system("cls");
                goto menu;
            };
        };
        case 13:{
            cout<<endl;
            int i = findminTeller(Ltell);
            cout<<"Nama Teller Dengan Nasabah Tersedikit = ";
            address_teller P = first(Ltell);
            while (P != NULL){
                int j = 0;
                address_relasi Q = Relasi(P);
                while( Q != NULL){
                    j = j + 1;
                    Q = nextTeller(Q);
                }
                if (j == i){
                    cout<<info(P).nama<<", ";
                }
                P = next(P);
            };
            cout<<endl;
            cout<<"Sebanyak "<<i<<" Nasabah"<<endl;
            cout<<endl;
            cout<<"Kembali Ke Menu Utama";
            getch();
            system("cls");
            goto menu;
        };
        case 14:{
            cout<<endl;
            int i = findmaxTeller(Ltell);
            cout<<"Nama Teller Dengan Nasabah Terbanyak = ";
            address_teller P = first(Ltell);
            while (P != NULL){
                int j = 0;
                address_relasi Q = Relasi(P);
                while( Q != NULL){
                    j = j + 1;
                    Q = nextTeller(Q);
                }
                if (j == i){
                    cout<<info(P).nama<<", ";
                }
                P = next(P);
            };
            cout<<endl;
            cout<<"Sebanyak "<<i<<" Nasabah"<<endl;
            cout<<endl;
            cout<<"Kembali Ke Menu Utama";
            getch();
            system("cls");
            goto menu;
        };
    }
    cout<<endl;
    cout<<"|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|"<<endl;
    cout<<"|Terima Kasih Telah Berkunjung|"<<endl;
    cout<<"|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|"<<endl;
}
