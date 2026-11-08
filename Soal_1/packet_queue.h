#ifndef PACKET_QUEUE_H
#define PACKET_QUEUE_H

#include <string>
#include <iostream>

struct Paket {
    std::string kode;
    int berat;
};

typedef Paket infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address next;
};

struct Queue {
    address head;
    address tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
address alokasi(std::string kode, int berat);
void dealokasi(address &p);
void enqueue(Queue &Q, address p);
void dequeue(Queue &Q, address &p);
address findElm(Queue Q, std::string kode);
bool fFindElm(Queue A, Queue B, std::string kode);
int nbList(Queue Q);
void printInfo(Queue Q);
void delAll(Queue &Q);

#endif