#include <iostream>
#include "UniqueArray.h"

UniqueArray::UniqueArray() : DynamicArray() {}
UniqueArray::UniqueArray(int cap) : DynamicArray(cap) {}
UniqueArray::UniqueArray(const UniqueArray& other) : DynamicArray(other) {}

bool UniqueArray::contains(int value) {
    for (int i = 0; i < getSize(); i++) { // dizi verilen değeri içeriyormu kontrol edilir.
        if (get(i) == value) return true;
    }
    return false;
}

void UniqueArray::push(int value) {
    /*
    Burada kısa olması için direk contains fonksiyonu kullanıldı. Böylece eleman dizide
    mevcut ise tekrardan diziye eklenmesi engellendi. Eğer dizide yok ise zaten normal
    push fonksiyonu ile dizinin sonuna eklenir.
    */
    if (contains(value)) {
        cout << "HATA: Bu eleman zaten bu dizide mevcut (" << value << ")!" << endl;
    }
    else {
        DynamicArray::push(value);
    }
}