#include "buffer_queue.h"

void createGeser(QueueGeser &Q) {
    Q.head = -1;
    Q.tail = -1;
    Q.shiftCount = 0;
}

bool isEmptyGeser(QueueGeser Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullGeser(QueueGeser Q) {
    return (Q.tail == CAPACITY - 1 && Q.head == 0);
}

void enqueueGeser(QueueGeser &Q, int nilai, int &nextNo) {
    if (isEmptyGeser(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.T[Q.tail] = {nextNo++, nilai};
    } else if (!isFullGeser(Q)) {
        Q.tail++;
        Q.T[Q.tail] = {nextNo++, nilai};
    }
}

void dequeueGeser(QueueGeser &Q, Rekaman &r) {
    if (!isEmptyGeser(Q)) {
        r = Q.T[Q.head];
        for (int i = Q.head; i < Q.tail; i++) {
            Q.T[i] = Q.T[i + 1];
            Q.shiftCount++;
        }
        Q.tail--;
        if (Q.tail < 0) {
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void createCircular(QueueCircular &Q) {
    Q.head = 0;
    Q.count = 0;
    Q.shiftCount = 0;
}

bool isEmptyCircular(QueueCircular Q) {
    return (Q.count == 0);
}

bool isFullCircular(QueueCircular Q) {
    return (Q.count == CAPACITY);
}

void enqueueCircular(QueueCircular &Q, int nilai, int &nextNo) {
    if (!isFullCircular(Q)) {
        int tailIdx = (Q.head + Q.count) % CAPACITY;
        Q.T[tailIdx] = {nextNo++, nilai};
        Q.count++;
    }
}

void dequeueCircular(QueueCircular &Q, Rekaman &r) {
    if (!isEmptyCircular(Q)) {
        r = Q.T[Q.head];
        Q.head = (Q.head + 1) % CAPACITY;
        Q.count--;
    }
}