#ifndef AWAL_H_INCLUDED
#define AWAL_H_INCLUDED
#include <stdio.h>
#include <iostream>
#define first(Lcustom) Lcustom.first
#define last(Lcustom) Lcustom.last
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define Relasi(P) (P)->Relasi


using namespace std;

struct infotype_teller{
    string nama;
    string kontak;
};
struct infotype_customer{
    string nama;
    string alamat;
};


typedef struct elmlist_teller *address_teller;
typedef struct elmlist_customer *address_customer;
typedef struct elmlist_relasi *address_relasi;

struct elmlist_teller{
    infotype_teller info;
    address_relasi Relasi;
    address_teller next;
    address_teller prev;
};

struct elmlist_customer{
    infotype_customer info;
    address_relasi Relasi;
    address_customer next;
    address_customer prev;
};

struct list_teller{
    address_teller first;
    address_teller last;
};

struct list_customer{
    address_customer first;
    address_customer last;
};

void CreateCustomer(list_customer &Lcustom);
void CreateTeller(list_teller &Ltell);
address_customer alokasiCustomer(infotype_customer X);
address_teller alokasiTeller(infotype_teller X);
void dealokasiuser(address_customer P);
void dealokasiportal(address_teller P);
address_teller findTeller(list_teller Ltell, infotype_teller X);
address_customer findCustomer (list_customer Lcustom, infotype_customer X);

//* Insert *//
void insertCustomer(list_customer &Lcustom, address_customer P);
void insertTeller(list_teller &Ltell, address_teller P);
//*DELETE//*
void deleteFirstCustomer(list_customer &Lcustom, address_customer &P);
void deleteAfterCustomer(list_customer &Lcustom, address_customer &P);
void deleteLastCustomer(list_customer &Lcustom, address_customer &P);
void deleteFirstTeller(list_teller &Ltell, address_teller &P);
void deleteAfterTeller(list_teller &Ltell, address_teller &P);
void deleteLastTeller(list_teller &Ltell, address_teller &P);


void deleteTeller(list_teller &Ltell, infotype_teller X);
void deleteCustomer(list_customer &Lcustom,infotype_customer X);

//*Proses*//
void printCustomer(list_customer Lcustom);
void printTeller(list_teller Ltell);


void printWebnyaUser(list_customer Lcustom, list_teller Ltell, int X);
void printUsernyaWeb(list_customer Lcustom, list_teller Ltell, int X);


#endif // AWAL_H_INCLUDED
