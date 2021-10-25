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
    freopen("input/1007.txt", "r", stdin);
#endif
    int k, sumOfHere = 0, res = -1, begin = 0, start = 0;
    scanf("%d", &k);
    int end = k - 1;
    vector<int> nums(k);
    for (int i = 0; i < k; i++) {
        cin >> nums[i];
        sumOfHere += nums[i];
        if (sumOfHere < 0) {
            sumOfHere = 0;
            begin = i + 1;
        } else if (sumOfHere > res) {
            res = sumOfHere;
            start = begin;
            end = i;
        }
    }
    if (res < 0) res = 0;
    printf("%d %d %d", res, nums[start], nums[end]);
    return 0;
}

