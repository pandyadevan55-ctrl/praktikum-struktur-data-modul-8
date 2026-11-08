#ifndef BUFFER_QUEUE_H
#define BUFFER_QUEUE_H

#include <iostream>

const int CAPACITY = 6;

struct Rekaman {
    int nomorUrut;
    int nilai;
};

struct QueueGeser {
    Rekaman T[CAPACITY];
    int head;
    int tail;
    int shiftCount;
};

void createGeser(QueueGeser &Q);
bool isEmptyGeser(QueueGeser Q);
bool isFullGeser(QueueGeser Q);
void enqueueGeser(QueueGeser &Q, int nilai, int &nextNo);
void dequeueGeser(QueueGeser &Q, Rekaman &r);

struct QueuePemadatan {
    Rekaman T[CAPACITY];
    int head;
    int tail;
    int shiftCount;
};

void createPemadatan(QueuePemadatan &Q);
bool isEmptyPemadatan(QueuePemadatan Q);
void enqueuePemadatan(QueuePemadatan &Q, int nilai, int &nextNo);
void dequeuePemadatan(QueuePemadatan &Q, Rekaman &r);

struct QueueCircular {
    Rekaman T[CAPACITY];
    int head;
    int count;
    int shiftCount;
};

void createCircular(QueueCircular &Q);
bool isEmptyCircular(QueueCircular Q);
bool isFullCircular(QueueCircular Q);
void enqueueCircular(QueueCircular &Q, int nilai, int &nextNo);
void dequeueCircular(QueueCircular &Q, Rekaman &r);

#endif