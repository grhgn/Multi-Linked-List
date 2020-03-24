#ifndef RELASIS_H_INCLUDED
#define RELASIS_H_INCLUDED
#include <stdio.h>
#include <iostream>
#define first(Lcustom) Lcustom.first
#define last(Lcustom) Lcustom.last
#define Teller(P) (P)->Teller
#define nextTeller(P) (P)->nextTeller
#define Customer(P) (P)->Customer
#define nextCustomer(P) (P)->nextCustomer
#include "DoubleLinkedList.h"

struct elmlist_relasi{
    address_teller Teller;
    address_relasi nextTeller;
    address_customer Customer;
    address_relasi nextCustomer;
};

struct list_relasi{};

address_relasi alokasiRelasi(address_customer Q, address_teller R);
void dealokasiRelasi(address_relasi P);
address_relasi findRelasiCustomer(address_customer Q, infotype_teller X);
address_relasi findRelasiTeller (address_teller Q, infotype_customer X);

void insertRelasiCustomer(address_customer P, address_relasi Q);
void insertRelasiTeller(address_teller P, address_relasi Q);

void printRelasiCustomer(address_customer P);
void printRelasiTeller(address_teller P);

void deleteFirstRelasiCustomer(address_customer &P, address_relasi Q);
void deleteAfterRelasiCustomer(address_customer &P, address_relasi Q);
void deleteLastRelasiCustomer(address_customer &P, address_relasi Q);
void deleteRelasiCustomer(address_customer &P, address_relasi Q);
void deleteFirstRelasiTeller(address_teller &P, address_relasi Q);
void deleteAfterRelasiTeller(address_teller &P, address_relasi Q);
void deleteLastRelasiTeller(address_teller &P, address_relasi Q);
void deleteRelasiTeller(address_teller &P, address_relasi Q);

int findmaxTeller(list_teller Ltell);
int findminTeller(list_teller Ltell);

bool maxTeller(address_customer P);
bool minCustomer(address_teller P);

#endif // RELASIS_H_INCLUDED
