#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

template<class T>
void print(T &a) {
    for (auto i: a) {
        cout << i << " ";
    }
    cout << endl;
}

template<class K, class V>
void print(map<K, V> &mp) {
    for (const auto &[k, v]: mp) {
        cout << "key = " << k << ", value = " << v << endl;
    }
    cout << "----------------------------------" << endl;
}