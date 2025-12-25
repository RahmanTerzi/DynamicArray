#pragma once
#include "DynamicArray.h"

class UniqueArray : public DynamicArray {
public:
    UniqueArray();
    UniqueArray(int cap);
    UniqueArray(const UniqueArray& other);

    bool contains(int value);
    void push(int value) override;
};