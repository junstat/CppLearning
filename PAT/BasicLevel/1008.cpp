//
// Created by jun on 2021/1/12.
//
#include "BasicLevel.h"

/*
   n = 6, m = 2
   1 2 3 4      5  6
   0     n-m-1
   group1: 0 ~ n-m-1
   group2: n-m ~ n
   reverse 采用 algorithm
 */
int basicLevel1008() {
#ifdef ONLINE_JUDGE
#else
    freopen("1008.input", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    m = m % n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    reverse(nums.begin(), nums.begin() + n - m);
    reverse(nums.begin() + n - m, nums.end());
    reverse(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i) cout << " ";
        cout << nums[i];
    }
    return 0;
}