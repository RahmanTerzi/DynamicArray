#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray() {
    size = 0;
    capacity = 2;
    data = new int[capacity];
}

DynamicArray::DynamicArray(int _capacity) {
    size = 0;
    if (_capacity < 1) capacity = 1;
    else capacity = _capacity;
    data = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::push(int value) {
    if (size == capacity) { // eğer dizi doluysa dizi boyutunu iki katına çıkarır.
        int newCapacity = capacity * 2;
        int* temp = new int[newCapacity]; // gecici bir dizi ile bunu yapabiliriz.
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity; 
        cout << "Dizi boyutu iki katina cikarildi." << endl;
    }
    data[size] = value;
    size++;
}

void DynamicArray::pop() {
    if (size > 0) {
        size--; // aslında burada o değeri silmedik ama kullanıcı bunu fark edemez.
                // size değeri o değere erişimi engeller.
        cout << "Son eleman silindi. Yeni boyut: " << size << endl;
    }
    else {
        cout << "Bu dizi zaten bos! Silinecek eleman yok." << endl;
    }
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        cout << "HATA: Gecersiz index girildi!" << endl;
        return -1; // Hata durumunda bir deger donmeli
    }
    else return data[index];
}

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "HATA: Gecersiz index girildi!" << endl;
    }
    else {
        data[index] = value;
    }
}

int DynamicArray::getSize() {
    return size;
}

int DynamicArray::getCapacity() {
    return capacity;
}

bool DynamicArray::isEmpty() {
    return size == 0;
}

void DynamicArray::clear() {
    size = 0;
    cout << "dizi temizlendi ve kapasite korundu." << endl;
}

void DynamicArray::print() {
    if (size == 0) {
        cout << "Bu dizi bos!" << endl;
    }
    else {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) { // son elemana gelindiğinde virgül konulmaz.
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

// Operatorler
int& DynamicArray::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "HATA: Gecersiz index!" << endl;
        return data[0]; // burada bir int deger dondurmek zorunda bu yüzden mecburen dizinin ilk degerini dondurduk.
    }
    else 
        return data[index];
}

DynamicArray DynamicArray::operator+(const DynamicArray& other) {
    int newCapacity = size + other.size; // yeni dizinin kapasitesi diğer iki dizinin kapasiteleri toplamıdır.
    DynamicArray result(newCapacity);

    for (int i = 0; i < size; i++) { // önce birinci dizi yeni diziye eklenir.
        result.push(data[i]);
    }
    for (int i = 0; i < other.size; i++) { // sonra ikinci dizi yeni diziye eklenir.
        result.push(other.data[i]);
    }
    return result;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    // Eğer atama yapılan iki dizi aynıysa yani kendine atama yapıyorsa aynı diziyi döndürür.
    if (this == &other) return *this; 

    // Memory leak olmaması için kopyalama yapılan diziyi siliyoruz.
    delete[] data;

    // İçeriğini yeniliyoruz yani diğer dizinin özelliklerini aktarıyoruz.
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];

    // diğer dizinin elemanlarını buraya aktarıyoruz.
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

bool DynamicArray::operator==(const DynamicArray& other) {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) { // tüm elemanlar burada kontrol edilir.
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool DynamicArray::operator!=(const DynamicArray& other) {
    return !(*this == other); // == operatorunu kullanarak kodumuzu kısalttık.
}

// Friend fonksiyonu "DynamicArray::" on eki almaz!
ostream& operator<<(ostream& os, const DynamicArray& arr) {
    os << "[ ";
    for (int i = 0; i < arr.size; i++) {
        os << arr.data[i];
        if (i < arr.size - 1) os << ", ";
    }
    os << " ]";
    return os;
}