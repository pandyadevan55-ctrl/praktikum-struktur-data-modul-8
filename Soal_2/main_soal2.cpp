#include <iostream>
#include "buffer_queue.h"

using namespace std;

int main() {
    cout << "=== SIMULASI BUFFER PENCATATAN HASIL UKUR ===\n\n";

    QueueGeser Q1;
    createGeser(Q1);
    int nextNo = 1;

    cout << "[UJI] Menulis 6 data: 12, -4, 7, 0, 15, 6\n";
    enqueueGeser(Q1, 12, nextNo);
    enqueueGeser(Q1, -4, nextNo);
    enqueueGeser(Q1, 7,  nextNo);
    enqueueGeser(Q1, 0,  nextNo);
    enqueueGeser(Q1, 15, nextNo);
    enqueueGeser(Q1, 6,  nextNo);

    cout << "Ambil 2 data dari Q1:\n";
    Rekaman r1, r2;
    dequeueGeser(Q1, r1);
    dequeueGeser(Q1, r2);
    cout << "Keluar -> " << r1.nomorUrut << ":" << r1.nilai << " dan " << r2.nomorUrut << ":" << r2.nilai << "\n";
    cout << "Total Pergeseran Versi 1: " << Q1.shiftCount << " rekaman\n\n";

    QueueCircular Q3;
    createCircular(Q3);
    int nextNo3 = 1;

    cout << "[UJI CIRCULAR] Menulis 6 data ke Circular Queue\n";
    enqueueCircular(Q3, 12, nextNo3);
    enqueueCircular(Q3, -4, nextNo3);
    enqueueCircular(Q3, 7,  nextNo3);
    enqueueCircular(Q3, 0,  nextNo3);
    enqueueCircular(Q3, 15, nextNo3);
    enqueueCircular(Q3, 6,  nextNo3);

    Rekaman r3_1, r3_2;
    dequeueCircular(Q3, r3_1);
    dequeueCircular(Q3, r3_2);
    cout << "Keluar Circular -> " << r3_1.nomorUrut << ":" << r3_1.nilai << " dan " << r3_2.nomorUrut << ":" << r3_2.nilai << "\n";
    cout << "Total Pergeseran Versi 3: " << Q3.shiftCount << " rekaman (selalu 0)\n";

    cout << "\n=== SIMULASI SOAL 2 SELESAI ===\n";
    return 0;
}