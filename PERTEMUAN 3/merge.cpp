#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // jumlah elemen bagian kiri
    int n2 = right - mid;     // jumlah elemen bagian kanan

    vector<int> L(n1), R(n2); // membuat array sementara

    // menyalin data ke array sementara L dan R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // membandingkan dan menggabungkan dua bagian array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // menyalin sisa elemen di L (jika ada)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // menyalin sisa elemen di R (jika ada)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama untuk melakukan merge sort (rekursif)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return; // kondisi berhenti jika hanya satu elemen

    int mid = left + (right - left) / 2; // mencari titik tengah

    // memanggil mergeSort untuk dua bagian
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // menggabungkan dua bagian yang sudah diurutkan
    merge(arr, left, mid, right);
}

// Fungsi untuk menampilkan isi array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Array sebelum diurutkan: ";
    printArray(data);

    mergeSort(data, 0, n - 1); // proses pengurutan

    cout << "Array setelah diurutkan: ";
    printArray(data);

    return 0;
}
