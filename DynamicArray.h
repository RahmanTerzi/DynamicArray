#pragma once
#include <iostream>
using namespace std;


class DynamicArray {
private:
    int size;     // dizideki mevcut eleman sayısı
    int capacity; // dizinin toplam kapasitesi
    int* data;    // dinamik olarak ayrılmış dizi işaretçisi

public:
    // Constructor & Destructor Bildirimleri
    DynamicArray(); // parametresiz constructor 
    DynamicArray(int _capacity); // parametreli constructor 
    DynamicArray(const DynamicArray& other); // copy constructor
    ~DynamicArray(); // destructor

    // Metot Bildirimleri
    virtual void push(int value);
    void pop();
    int get(int index); 
    void set(int index, int value);
    int getSize();
    int getCapacity();
    bool isEmpty();
    void clear();
    void print();

    // Operator Aşırı Yükleme 
    int& operator[](int index);
    DynamicArray operator+(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    bool operator==(const DynamicArray& other);
    bool operator!=(const DynamicArray& other);
    
    friend ostream& operator<<(ostream& os, const DynamicArray& arr);
};