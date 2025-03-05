#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    int tahun;
};

// Validasi input angka
int validasiInput() {
    int angka;
    while (!(cin >> angka)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid! Masukkan angka: ";
    }
    return angka;
}

// Input Data Buku 
void inputBuku(Buku buku[], int &n) {
    cout << "Masukkan jumlah buku: ";
    n = validasiInput();
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Judul buku ke-" << (i + 1) << ": ";
        getline(cin, buku[i].judul);
        cout << "Tahun Terbit: ";
        buku[i].tahun = validasiInput();
        cin.ignore();
    }
}

// Menampilkan Data Buku
void tampilkanBuku(const Buku buku[], int n) {
    if (n == 0) {
        cout << "Belum ada data yang diinput!\n";
        return;
    }
    cout << "\nDaftar Buku:\n";
    for (int i = 0; i < n; i++) {
        cout << buku[i].tahun << " - " << buku[i].judul << endl;
    }
}

// Bubble Sort
void bubbleSort(Buku buku[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (buku[j].tahun > buku[j + 1].tahun) {
                swap(buku[j], buku[j + 1]);
            }
        }
    }
}

// Quick Sort
void quickSort(Buku buku[], int left, int right) {
    if (left >= right) return;
    int i = left, j = right;
    int pivot = buku[(left + right) / 2].tahun;
    while (i <= j) {
        while (buku[i].tahun < pivot) i++;
        while (buku[j].tahun > pivot) j--;
        if (i <= j) {
            swap(buku[i], buku[j]);
            i++;
            j--;
        }
    }
    quickSort(buku, left, j);
    quickSort(buku, i, right);
}

// Sequential Search
void sequentialSearch(const Buku buku[], int n, int tahun) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (buku[i].tahun == tahun) {
            cout << "Buku ditemukan: " << buku[i].judul << " (" << buku[i].tahun << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Buku tidak ditemukan.\n";
}

// Binary Search 
int binarySearch(const Buku buku[], int left, int right, int tahun) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (buku[mid].tahun == tahun) return mid;
        if (buku[mid].tahun < tahun) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    Buku buku[100]; 
    int n = 0, pilihan, tahun;
    bool sorted = false;

    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Input Data Buku\n";
        cout << "2. Tampilkan Data Buku\n";
        cout << "3. Urutkan dengan Bubble Sort\n";
        cout << "4. Urutkan dengan Quick Sort\n";
        cout << "5. Cari dengan Sequential Search\n";
        cout << "6. Cari dengan Binary Search\n";
        cout << "7. Keluar\n";
        cout << "Pilihan Anda: ";
        pilihan = validasiInput();
        cin.ignore();

        switch (pilihan) {
            case 1:
                inputBuku(buku, n);
                sorted = false;
                break;

            case 2:
                tampilkanBuku(buku, n);
                break;

            case 3:
                if (n == 0) cout << "Belum ada data!\n";
                else {
                    bubbleSort(buku, n);
                    sorted = true;
                    cout << "\n== Data telah diurutkan dengan Bubble Sort ==\n";
                    tampilkanBuku(buku, n);
                }
                break;

            case 4:
                if (n == 0) cout << "Belum ada data!\n";
                else {
                    quickSort(buku, 0, n - 1);
                    sorted = true;
                    cout << "\n== Data telah diurutkan dengan Quick Sort ==\n";
                    tampilkanBuku(buku, n);
                }
                break;

            case 5:
                if (n == 0) cout << "Belum ada data!\n";
                else {
                    cout << "Masukkan tahun yang dicari: ";
                    tahun = validasiInput();
                    sequentialSearch(buku, n, tahun);
                }
                break;

            case 6:
                if (n == 0) cout << "Belum ada data!\n";
                else if (!sorted) {
                    cout << "Data belum diurutkan! Gunakan Bubble Sort atau Quick Sort terlebih dahulu.\n";
                } else {
                    cout << "Masukkan tahun yang dicari: ";
                    tahun = validasiInput();
                    int index = binarySearch(buku, 0, n - 1, tahun);
                    if (index != -1)
                        cout << "Buku ditemukan: " << buku[index].judul << " (" << buku[index].tahun << ")\n";
                    else
                        cout << "Buku tidak ditemukan.\n";
                }
                break;

            case 7:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;

            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != 7);

    return 0;
}