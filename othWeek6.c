#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk mencari jumlah maksimum elemen yang dapat diambil dari kedua tumpukan
int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int sum = 0; // Variabel untuk menyimpan jumlah sementara
    int count = 0; // Variabel untuk menyimpan jumlah elemen yang diambil
    int a_index = 0; // Indeks untuk tumpukan a
    int b_index = 0; // Indeks untuk tumpukan b

    // Mencoba untuk menambahkan elemen dari tumpukan pertama (a) sebanyak mungkin
    while (a_index < a_count && sum + a[a_index] <= maxSum) {
        sum += a[a_index++];
        count++;
    }

    int maxCount = count; // Menyimpan jumlah maksimum sementara

    // Menambahkan elemen dari tumpukan kedua (b) satu per satu, jika memungkinkan
    while (b_index < b_count && a_index >= 0) {
        sum += b[b_index++];
        count++;

        // Memperbarui jumlah maksimum jika jumlah melebihi maxSum
        while (sum > maxSum && a_index > 0) {
            a_index--;
            sum -= a[a_index];
            count--;
        }

        // Memperbarui jumlah maksimum jika jumlah dari kedua tumpukan lebih besar
        if (sum <= maxSum && count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount; // Mengembalikan jumlah maksimum
}

int main() {
    // Contoh pemanggilan fungsi twoStacks
    int maxSum = 10;
    int a[] = {4, 2, 4, 6, 1};
    int b[] = {2, 1, 8, 5};
    int result = twoStacks(maxSum, sizeof(a) / sizeof(a[0]), a, sizeof(b) / sizeof(b[0]), b);
    printf("Jumlah maksimum elemen yang dapat diambil: %d\n", result);

    return 0;
}
