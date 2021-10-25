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
    freopen("input/1008.txt", "r", stdin);
#endif
    int up = 6, down = 4, stop = 5, res = 0, cur = 0, goal;
    cin >> goal;
    while (cin >> goal) {
        if (goal > cur) {  // up
            res += (goal - cur) * up;
        } else {
            res += (cur - goal) * down;
        }
        res += stop;
        cur = goal;
    }
    printf("%d", res);
    return 0;
}

