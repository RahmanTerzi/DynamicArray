#include <iostream>
#include "DynamicArray.h"
#include "SortedArray.h"
#include "UniqueArray.h"

using namespace std;

int main() {
    cout << "=== 1. DynamicArray ve Resize Testi ===" << endl;
    DynamicArray arr1(2); // Kapasite 2
    arr1.push(10);
    arr1.push(20);
    arr1.push(30); // Burada kapasite 4'e çıkmalı (Resize)
    cout << "Dizi: " << arr1 << endl; // Çıktı: [ 10, 20, 30 ]
    cout << "Boyut: " << arr1.getSize() << ", Kapasite: " << arr1.getCapacity() << endl;

    cout << "\n=== 2. Operator[] ve Atama Testi ===" << endl;
    arr1[0] = 99; // Set işlemi
    cout << "0. index degisti: " << arr1 << endl; // Çıktı: [ 99, 20, 30 ]

    cout << "\n=== 3. Deep Copy (Kopyalama) Kontrolü ===" << endl;
    DynamicArray arrCopy = arr1; // Copy Constructor çalışır
    arr1[0] = 555; // Sadece arr1 değişmeli, arrCopy bozulmamalı
    
    cout << "Orjinal (arr1): " << arr1 << endl;    // Çıktı: [ 555, 20, 30 ]
    cout << "Kopya   (arrCopy): " << arrCopy << endl; // Çıktı: [ 99, 20, 30 ] -> EĞER BU SATIR DEĞİŞMEMİŞSE DEEP COPY BAŞARILIDIR.

    cout << "\n=== 4. (+) Operatoru ve Birlestirme ===" << endl;
    DynamicArray arr2;
    arr2.push(40);
    arr2.push(50);
    DynamicArray arrTotal = arrCopy + arr2;
    cout << "Birlesim: " << arrTotal << endl; // Çıktı: [ 99, 20, 30, 40, 50 ]

    cout << "\n=== 5. SortedArray Testi ===" << endl;
    SortedArray sorted;
    sorted.push(50);
    sorted.push(10);
    sorted.push(30); // Araya eklemeli
    cout << "Sirali Dizi: " << sorted << endl; // Çıktı: [ 10, 30, 50 ]
    
    // Binary Search
    int idx = sorted.binarySearch(30);
    cout << "30 bulundu mu? Indeks: " << idx << endl; // 1 dönmeli
    sorted.binarySearch(99); // Bulunamadı hatası vermeli

    cout << "\n=== 6. UniqueArray Testi ===" << endl;
    UniqueArray unique;
    unique.push(5);
    unique.push(5); // HATA vermeli, eklememeli
    unique.push(10);
    cout << "Benzersiz Dizi: " << unique << endl; // Çıktı: [ 5, 10 ]
    
    cout << "10 var mi? " << (unique.contains(10) ? "Evet" : "Hayir") << endl;

    cout << "\n=== 7. Pop ve Clear Testi ===" << endl;
    unique.pop();
    cout << "Pop sonrasi: " << unique << endl; // [ 5 ]
    unique.clear();
    cout << "Clear sonrasi bos mu? " << (unique.isEmpty() ? "Evet" : "Hayir") << endl;

    return 0;
}