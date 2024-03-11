#pragma once

#include <iostream>

using namespace std;

template<class T>
class ArrayT {
public:
    ArrayT(int capacity) : capacity(capacity), size(0), pAddr(new T[capacity]) {}

    // 拷贝构造
    ArrayT(const ArrayT &arr) {
        capacity = arr.capacity;
        size = arr.size;
        pAddr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            pAddr[i] = arr.pAddr[i];
        }
    }

    ArrayT &operator=(const ArrayT &arr) {
        // 先判断原来堆区是否有数据，如果有先释放
        if (pAddr != nullptr) {
            delete[] pAddr;
            pAddr = nullptr;
            capacity = 0;
            size = 0;
        }
        // 深拷贝
        capacity = arr.capacity;
        size = arr.size;
        pAddr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            pAddr[i] = arr.pAddr[i];
        }
        return *this;
    }

    void push_back(const T &value) {
        if (size >= capacity) {
            return;
        }
        pAddr[size++] = value;
    }

    void pop_back() {
        if (size <= 0) {
            return;
        }
        --size;
    }

    T &operator[](int index) {
        return pAddr[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    ~ArrayT() {
        if (pAddr != nullptr) {
            delete[] pAddr;
            pAddr = nullptr;
        }
    }

private:
    T *pAddr;  // 指针指向堆区开辟的真实数组
    int capacity; // 数组容量
    int size; // 数组大小
};