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
    freopen("input/1009.txt", "r", stdin);
#endif
    int lenA, lenB, coefficient, cnt = 0;
    scanf("%d", &lenA);
    double exponent, A[1001] = {0.0}, res[2001] = {0.0};
    for (int i = 0; i < lenA; i++) {
        scanf("%d %lf", &coefficient, &exponent);
        A[coefficient] = exponent;
    }
    scanf("%d", &lenB);
    for (int i = 0; i < lenB; i++) {
        scanf("%d %lf", &coefficient, &exponent);
        for (int j = 0; j < 1001; j++) {
            res[j + coefficient] += A[j] * exponent;
        }
    }

    for (int i = 2000; i >= 0; i--)
        if (res[i] != 0.0) cnt++;
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--)
        if (res[i] != 0.0) printf(" %d %.1f", i, res[i]);
    return 0;
}

