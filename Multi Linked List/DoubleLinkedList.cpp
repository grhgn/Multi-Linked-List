#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "DoubleLinkedList.h"
#include "Relasis.h"


void CreateTeller(list_teller &Ltell){
    first(Ltell) = NULL;
    last(Ltell) = NULL;
};
void CreateCustomer(list_customer &Lcustom){
    first(Lcustom) = NULL;
    last(Lcustom) = NULL;
};
address_teller alokasiTeller(infotype_teller X){
    address_teller P = new elmlist_teller;
    info(P).nama = X.nama;
    info(P).kontak = X.kontak;
    next(P) = NULL;
    prev(P) = NULL;
    Relasi(P) = NULL;
    return P;
};
address_customer alokasiCustomer(infotype_customer X){
    address_customer P = new elmlist_customer;
    info(P).nama = X.nama;
    info(P).alamat = X.alamat;
    next(P) = NULL;
    prev(P) = NULL;
    Relasi(P) = NULL;
    return P;
};
void dealokasiTeller(address_teller P){
    delete P;
};

void dealokasiCustomer(address_customer P){
    delete P;
};
address_customer findCustomer(list_customer Lcustom, infotype_customer X){
    address_customer P = first(Lcustom);
    if (first(Lcustom) == NULL){
        cout<<"Error Data Tidak Ditemukan"<<endl;
        P = NULL;
        return P;
    }
    else {
        while (info(P).nama != X.nama and next(P) != NULL){
            P = next(P);
        }
        if (info(P).nama == X.nama){
            return P;
        }
        else {
            P = NULL;
            return P;
        }
    }
};

address_teller findTeller (list_teller Ltell, infotype_teller X){
    address_teller P = first(Ltell);
    if (first(Ltell) == NULL){
        cout<<"Error Data Tidak Ditemukan"<<endl;
        P = NULL;
        return P;
    }
    else {
        while (info(P).nama != X.nama and next(P) != NULL){
            P = next(P);
        }
        if (info(P).nama == X.nama){
            return P;
        }
        else {
            P = NULL;
            return P;
        }
    }
};

void insertTeller(list_teller &Ltell, address_teller P){
    if(first(Ltell) == NULL){
        first(Ltell) = P;
        last(Ltell) = P;
    }
    else {
        next(P) = first(Ltell);
        prev(first(Ltell)) = P;
        first(Ltell) = P;
    }
};

void insertCustomer(list_customer &Lcustom, address_customer P){
    if(first(Lcustom) == NULL){
        first(Lcustom) = P;
        last(Lcustom) = P;
    }
    else {
        next(P) = first(Lcustom);
        prev(first(Lcustom)) = P;
        first(Lcustom) = P;
    }
};

void deleteFirstTeller(list_teller &Ltell, address_teller &P){
    if (first(Ltell) == last(Ltell)) {
        first(Ltell) = NULL;
        last(Ltell) = NULL;
    }
    else {
        P = first(Ltell);
        first(Ltell) = next(P);
        next(P) = NULL;
        prev(first(Ltell)) = NULL;
    }
};
void deleteAfterTeller(list_teller &Ltell, address_teller &P){
    if (first(Ltell) == last(Ltell)) {
        first(Ltell) = NULL;
        last(Ltell) = NULL;
    }
    else {
        address_teller Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLastTeller(list_teller &Ltell, address_teller &P){
    if (first(Ltell) == last(Ltell)) {
        first(Ltell) = NULL;
        last(Ltell) = NULL;
    }
    else {
        P = last(Ltell);
        last(Ltell) = prev(P);
        next(last(Ltell)) = NULL;
        prev(P) = NULL;
    }

};
void deleteFirstCustomer(list_customer &Lcustom, address_customer &P){
    if (first(Lcustom) == last(Lcustom)) {
        first(Lcustom) = NULL;
        last(Lcustom) = NULL;
    }
    else {
        P = first(Lcustom);
        first(Lcustom) = next(P);
        next(P) = NULL;
        prev(first(Lcustom)) = NULL;
    }
};
void deleteAfterCustomer(list_customer &Lcustom, address_customer &P){
    if (first(Lcustom) == last(Lcustom)) {
        first(Lcustom) = NULL;
        last(Lcustom) = NULL;
    }
    else {
        address_customer Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
};
void deleteLastCustomer(list_customer &Lcustom, address_customer &P){
    if (first(Lcustom) == last(Lcustom)) {
        first(Lcustom) = NULL;
        last(Lcustom) = NULL;
    }
    else {
        P = last(Lcustom);
        last(Lcustom) = prev(P);
        next(last(Lcustom)) = NULL;
        prev(P) = NULL;
    }

};

void printCustomer(list_customer Lcustom){
    if(first(Lcustom) == NULL){
        cout<<"Daftar Customer Kosong"<<endl;
    }
    else {
        address_customer P = first(Lcustom);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Customer = "<<info(P).nama<<endl;
            cout<<"Alamat Customer = "<<info(P).alamat<<endl;
            cout<<"Teller = ";
            address_relasi Q = Relasi(P);
            while (Q != NULL){
                cout<<info(Teller(Q)).nama<<" ,";
                Q = nextCustomer(Q);
            }
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

void printTeller(list_teller Ltell){
    if(first(Ltell) == NULL){
        cout<<"Daftar Teller Kosong"<<endl;
    }
    else {
        address_teller P = first(Ltell);
        while (P != NULL){
            cout<<endl;
            cout<<"Nama Teller = "<<info(P).nama<<endl;
            cout<<"Kontak Teller = "<<info(P).kontak<<endl;
            cout<<"Nasabah = ";
            address_relasi Q = Relasi(P);
            while (Q != NULL){
                cout<<info(Customer(Q)).nama<<" ,";
                Q = nextTeller(Q);
            }
            P = next(P);
            cout<<endl;
        }
    }
    cout<<endl;
};

void deleteCustomer(list_customer &Lcustom, infotype_customer X){
        if (first(Lcustom) == NULL){
        cout<<"Error Data Kosong"<<endl;
    }
    else {
        address_customer P = findCustomer(Lcustom, X);
        if (P == first(Lcustom)){
            deleteFirstCustomer(Lcustom, P);
        }
        else if (P == last(Lcustom)){
            deleteLastCustomer(Lcustom, P);
        }
        else if (P != NULL){
            deleteAfterCustomer(Lcustom, P);
        }
        else {
            cout<<"Data Tidak Ditemukan"<<endl;
        }
    }
};

void deleteTeller(list_teller &Ltell, infotype_teller X){
        if (first(Ltell) == NULL){
        cout<<"Error Data Kosong"<<endl;
    }
    else {
        address_teller P = findTeller(Ltell, X);
        while (info(P).nama != X.nama and P != NULL){
            P = next(P);
        }
        if (P == first(Ltell)){
            deleteFirstTeller(Ltell, P);
        }
        else if (P == last(Ltell)){
            deleteLastTeller(Ltell, P);
        }
        else if (P != last(Ltell) or P != first(Ltell)){
            deleteAfterTeller(Ltell, P);
        }
        else {
            cout<<"Data Tidak Ditemukan"<<endl;
        }
    }
};

