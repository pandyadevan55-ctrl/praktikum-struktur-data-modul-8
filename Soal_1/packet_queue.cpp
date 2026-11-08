#include "packet_queue.h"

void createQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == nullptr && Q.tail == nullptr);
}

address alokasi(std::string kode, int berat) {
    address p = new Node;
    p->info.kode = kode;
    p->info.berat = berat;
    p->next = nullptr;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = nullptr;
}

void enqueue(Queue &Q, address p) {
    if (isEmptyQueue(Q)) {
        Q.head = p;
        Q.tail = p;
    } else {
        Q.tail->next = p;
        Q.tail = p;
    }
    Q.tail->next = nullptr;
}

void dequeue(Queue &Q, address &p) {
    if (isEmptyQueue(Q)) {
        p = nullptr;
    } else if (Q.head == Q.tail) {
        p = Q.head;
        Q.head = nullptr;
        Q.tail = nullptr;
        p->next = nullptr;
    } else {
        p = Q.head;
        Q.head = Q.head->next;
        p->next = nullptr;
    }
}

address findElm(Queue Q, std::string kode) {
    address p = Q.head;
    while (p != nullptr) {
        if (p->info.kode == kode) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

bool fFindElm(Queue A, Queue B, std::string kode) {
    return (findElm(A, kode) != nullptr || findElm(B, kode) != nullptr);
}

int nbList(Queue Q) {
    int count = 0;
    address p = Q.head;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void printInfo(Queue Q) {
    address p = Q.head;
    if (isEmptyQueue(Q)) {
        std::cout << "Kosong";
    } else {
        while (p != nullptr) {
            std::cout << p->info.kode << " (" << p->info.berat << "g)";
            if (p->next != nullptr) std::cout << ", ";
            p = p->next;
        }
    }
}

void delAll(Queue &Q) {
    address p;
    while (!isEmptyQueue(Q)) {
        dequeue(Q, p);
        dealokasi(p);
    }
}