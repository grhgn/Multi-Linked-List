#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "Relasis.h"
#include "DoubleLinkedList.h"

address_relasi alokasiRelasi(address_customer Q, address_teller R){
    address_relasi P = new elmlist_relasi;
    Teller(P) = R;
    nextTeller(P) = NULL;
    Customer(P) = Q;
    nextCustomer(P) = NULL;
    return P;
};

void dealokasiRelasi(address_relasi P){
    delete(P);
};

address_relasi findRelasiCustomer(address_customer Q, infotype_teller X){
    address_relasi P = Relasi(Q);
    if (Relasi(Q) == NULL){
        P = NULL;
        return P;
    }
    while (info(Teller(P)).nama != X.nama and nextCustomer(P) != NULL){
        P = nextCustomer(P);
    }
    if (info(Teller(P)).nama == X.nama){
        return P;
    }
    else {
        P = NULL;
        return P;
    }
};



address_relasi findRelasiTeller (address_teller Q, infotype_customer X){
    address_relasi P = Relasi(Q);
    if (Relasi(Q) == NULL){
        P = NULL;
        return P;
    }
    while (info(Customer(P)).nama != X.nama and nextTeller(P) != NULL){
        P = nextTeller(P);
    }
    if (info(Customer(P)).nama == X.nama){
        return P;
    }
    else {
        P = NULL;
        return P;
    }
};

void insertRelasiCustomer(address_customer P, address_relasi Q){
    if(Relasi(P) == NULL){
        Relasi(P) = Q;
    }
    else {
        nextCustomer(Q) = Relasi(P);
        Relasi(P) = Q;
    }
};

void insertRelasiTeller(address_teller P, address_relasi Q){
    if(Relasi(P) == NULL){
        Relasi(P) = Q;
    }
    else {
        nextTeller(Q) = Relasi(P);
        Relasi(P) = Q;
    }
};

void printRelasiCustomer(address_customer P){
    address_relasi Q = Relasi(P);
    if (Q == NULL){
        cout<<"Belum Mengunjungi Teller"<<endl;
    }
    else{
        while(Q != NULL){
            cout<<"Nama Teller = "<<info(Teller(Q)).nama<<endl;
            cout<<"Kontak Teller = "<<info(Teller(Q)).kontak<<endl;
            cout<<endl;
            Q = nextCustomer(Q);
        }
    }
};

void printRelasiTeller(address_teller P){
    address_relasi Q = Relasi(P);
    if (Q == NULL){
        cout<<"Belum Melayani Nasabah"<<endl;
    }
    else{
        while(Q != NULL){
            cout<<"Nama Nasabah = "<<info(Customer(Q)).nama<<endl;
            cout<<"Alamat Nasabah = "<<info(Customer(Q)).alamat<<endl;
            cout<<endl;
            Q = nextTeller(Q);
        }
    }
};

void deleteFirstRelasiCustomer(address_customer &P, address_relasi Q){
    if(nextCustomer(Relasi(P)) == NULL){
        Relasi(P) = NULL;
    }
    else{
        Relasi(P) = nextCustomer(Q);
        nextCustomer(Q) = NULL;
    }
};

void deleteAfterRelasiCustomer(address_customer &P, address_relasi Q){
    if(nextCustomer(Relasi(P)) == NULL){
        Relasi(P) = NULL;
    }
    else{
        address_relasi Prec = Relasi(P);
        while(info(Teller(nextCustomer(Prec))).nama != info(Teller(Q)).nama){
            Prec = nextCustomer(Prec);
        }
        nextCustomer(Prec) = nextCustomer(Q);
        nextCustomer(Q) = NULL;
    }
};

void deleteLastRelasiCustomer(address_customer &P, address_relasi Q){
    if(nextCustomer(Relasi(P)) == NULL){
        Relasi(P) = NULL;
    }
    else{
        address_relasi Prec = Relasi(P);
        while(nextCustomer(nextCustomer(Prec)) != NULL){
            Prec = nextCustomer(Prec);
        }
        nextCustomer(Prec) = NULL;
    }
};

void deleteRelasiCustomer(address_customer &P, address_relasi Q){
    if (Relasi(P) == NULL){
        cout<<"Belum Mengunjungi Teller"<<endl;
    }
    else if (Q == Relasi(P)){
        deleteFirstRelasiCustomer(P, Q);
    }
    else if (nextCustomer(Q) == NULL){
        deleteLastRelasiCustomer(P, Q);
    }
    else if (Q != NULL){
        deleteAfterRelasiCustomer(P, Q);
    }
    else {
        cout<<"Error Data Tidak Ada"<<endl;
    }
};

void deleteFirstRelasiTeller(address_teller &P, address_relasi Q){
    if(nextTeller(Relasi(P)) == NULL){
        Relasi(P) = NULL;
    }
    else{
        Relasi(P) = nextTeller(Q);
        nextTeller(Q) = NULL;
    }
};

void deleteAfterRelasiTeller(address_teller &P, address_relasi Q){
    if(nextTeller(Relasi(P)) == NULL){
        Relasi(P) = NULL;
    }
    else{
        address_relasi Prec = Relasi(P);
        while(info(Customer(nextTeller(Prec))).nama != info(Customer(Q)).nama){
            Prec = nextTeller(Prec);
        }
        nextTeller(Prec) = nextTeller(Q);
        nextTeller(Q) = NULL;
    }
};

void deleteLastRelasiTeller(address_teller &P, address_relasi Q){
    if(nextTeller(Relasi(P)) == NULL){
        Relasi(P) = NULL;
    }
    else{
        address_relasi Prec = Relasi(P);
        while(nextTeller(nextTeller(Prec)) != NULL){
            Prec = nextTeller(Prec);
        }
        nextTeller(Prec) = NULL;
    }
};

void deleteRelasiTeller(address_teller &P, address_relasi Q){
    if (Relasi(P) == NULL){
        cout<<"Belum Melayani Nasabah"<<endl;
    }
    else if (Q == Relasi(P)){
        deleteFirstRelasiTeller(P, Q);
    }
    else if (nextTeller(Q) == NULL){
        deleteLastRelasiTeller(P, Q);
    }
    else if (Q != NULL){
        deleteAfterRelasiTeller(P, Q);
    }
    else {
        cout<<"Error Data Tidak Ada"<<endl;
    }
};

int findmaxTeller(list_teller Ltell){
    int i = 0;
    address_relasi Q = Relasi(first(Ltell));
    while (Q != NULL){
        i = i + 1;
        Q = nextTeller(Q);
    }
    address_teller P = first(Ltell);
    while(P != NULL){
        address_relasi R = Relasi(P);
        int j = 0;
        while (R != NULL){
        j = j + 1;
        R = nextTeller(R);
        }
        if(j >= i){
            i = j;
        }
        P = next(P);
    }
    return i;
};

int findminTeller(list_teller Ltell){
    int i = 0;
    address_relasi Q = Relasi(first(Ltell));
    while (Q != NULL){
        i = i + 1;
        Q = nextTeller(Q);
    }
    address_teller P = first(Ltell);
    while(P != NULL){
        address_relasi R = Relasi(P);
        int j = 0;
        while (R != NULL){
        j = j + 1;
        R = nextTeller(R);
        }
        if(j < i){
            i = j;
        }
        P = next(P);
    }
    return i;
};

bool maxTeller(address_customer P){
    int i = 0;
    address_relasi Q = Relasi(P);
    while (Q != NULL){
        i = i + 1;
        Q = nextCustomer(Q);
    }
    if (i == 3){
        return true;
    }
    else{
        return false;
    }
};

bool minCustomer(address_teller P){
    int i = 0;
    address_relasi Q = Relasi(P);
    while (Q != NULL){
        i = i + 1;
        Q = nextTeller(Q);
    }
    if (i == 1){
        return true;
    }
    else{
        return false;
    }
};
