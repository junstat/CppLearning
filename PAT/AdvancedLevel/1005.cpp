//
// Created by jun on 2020/5/7.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1005.txt", "r", stdin);
#endif
    string numEngMap[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string s;
    cin >> s;
    int res = 0;
    for (char c: s)
        res += c - '0';
    string strRes = to_string(res);
    for (int i = 0; i < strRes.length(); i++) {
        if (i) printf(" ");
        printf("%s", numEngMap[strRes[i] - '0'].c_str());
    }
    return 0;
}

