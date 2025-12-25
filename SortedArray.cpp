#include <iostream>
#include "SortedArray.h"

SortedArray::SortedArray() : DynamicArray() {}
SortedArray::SortedArray(int cap) : DynamicArray(cap) {}
SortedArray::SortedArray(const SortedArray& other) : DynamicArray(other) {}

void SortedArray::push(int value) {
    DynamicArray::push(value); // Önce sona ekliyoruz.

    int i = getSize() - 1;

    // Sonra burada bu değeri uygun yerine yerleştriyoruz.
    while (i > 0) {
        int current = get(i);
        int prev = get(i - 1);

        if (current < prev) {
            set(i, prev);
            set(i - 1, current);
            i--;
        }
        else break;
    }
}

int SortedArray::binarySearch(int value) {
    /*
    Burada bulunan dizi her zaman sıralı olmak zorundadır. Ortadaki eleman
    seçilir ve kıyaslamalar ile sağındamı solundamı olduğu anlaşılır.
    Eğer sağındaysa solu, solundaysa sağı görmezden gelinir. Böylece
    kısa bir sürede aranan değer varsa bulunur.
    */
    int left = 0;
    int right = getSize() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midVal = get(mid);

        if (midVal == value) return mid;

        if (midVal < value) left = mid + 1;
        else right = mid - 1;
    }
    cout << "Bu eleman dizi icerisinde bulunmamaktadir!" << endl;
    return -1; // Bulunamadi
}