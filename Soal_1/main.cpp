#include <iostream>
#include "packet_queue.h"

using namespace std;

int main() {
    Queue A, B;
    createQueue(A);
    createQueue(B);

    int sentCount = 0;
    int sentWeight = 0;

    cout << "=== SIMULASI SISTEM SORTIR & PENGIRIMAN PAKET ===\n\n";

    cout << "[LANGKAH] Masukkan P17 (450), P28 (700), P36 (550) ke A\n";
    enqueue(A, alokasi("P17", 450));
    enqueue(A, alokasi("P28", 700));
    enqueue(A, alokasi("P36", 550));
    cout << "Isi A: "; printInfo(A); cout << "\n";
    cout << "Isi B: "; printInfo(B); cout << "\n\n";

    cout << "[LANGKAH] PINDAH 2\n";
    int n = 2;
    if (n > 0 && n <= nbList(A)) {
        for (int i = 0; i < n; i++) {
            address p;
            dequeue(A, p);
            enqueue(B, p);
        }
    }
    cout << "Isi A: "; printInfo(A); cout << "\n";
    cout << "Isi B: "; printInfo(B); cout << "\n";
    cout << "Hasil: Belum ada paket terkirim.\n\n";

    cout << "[LANGKAH] MASUK P42 600\n";
    if (!fFindElm(A, B, "P42")) {
        enqueue(A, alokasi("P42", 600));
    }
    cout << "Isi A: "; printInfo(A); cout << "\n";
    cout << "Isi B: "; printInfo(B); cout << "\n\n";

    cout << "[LANGKAH] PINDAH 3\n";
    n = 3;
    if (n > 0 && n <= nbList(A)) {
        for (int i = 0; i < n; i++) {
            address p;
            dequeue(A, p);
            enqueue(B, p);
        }
    } else {
        cout << "Ditolak: A hanya berisi " << nbList(A) << " paket.\n";
    }
    cout << "Isi A: "; printInfo(A); cout << "\n";
    cout << "Isi B: "; printInfo(B); cout << "\n\n";

    cout << "[LANGKAH] PINDAH 1\n";
    n = 1;
    if (n > 0 && n <= nbList(A)) {
        address p;
        dequeue(A, p);
        enqueue(B, p);
    }
    cout << "Isi A: "; printInfo(A); cout << "\n";
    cout << "Isi B: "; printInfo(B); cout << "\n\n";

    // 6. KIRIM 2
    cout << "[LANGKAH] KIRIM 2\n";
    int k = 2;
    if (k > 0 && k <= nbList(B)) {
        for (int i = 0; i < k; i++) {
            address p;
            dequeue(B, p);
            sentCount++;
            sentWeight += p->info.berat;
            dealokasi(p);
        }
    }
    cout << "Isi A: "; printInfo(A); cout << "\n";
    cout << "Isi B: "; printInfo(B); cout << "\n";
    cout << "Statistik Terkirim: " << sentCount << " paket, Total Berat: " << sentWeight << " gram.\n\n";

    cout << "[LANGKAH] CARI P36\n";
    address found = findElm(B, "P36");
    if (found != nullptr) {
        cout << "Ditemukan di B, berat " << found->info.berat << " gram.\n\n";
    } else {
        cout << "TIDAK DITEMUKAN.\n\n";
    }

    delAll(A);
    delAll(B);
    cout << "=== SIMULASI SELESAI ===\n";

    return 0;
}