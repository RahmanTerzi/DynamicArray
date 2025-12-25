#pragma once
#include "DynamicArray.h"

class SortedArray : public DynamicArray {
public:
    SortedArray();
    SortedArray(int cap);
    SortedArray(const SortedArray& other);

    void push(int value) override;
    int binarySearch(int value);
};