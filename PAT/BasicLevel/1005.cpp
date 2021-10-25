//
// Created by jun on 2021/1/11.
//
#include "BasicLevel.h"

/*
 * 1. 预设变量，记录覆盖数 int coverNums[101]; 记录输入数字 vector<int> inputNums(k);
 * 2. 遍历，读入数字 n
 *     若 n 已被覆盖，跳过处理下一个数组
 *     不然，计算 卡拉兹猜想
 * 3. 逆序排序 inputNums, 遍历，判断是否被覆盖
 * 
 * key point: vector、sort
 */

int basicLevel1005() {
#ifdef ONLINE_JUDGE
#else
    freopen("1005.input", "r", stdin);
#endif
    int k, n, coverNums[101] = {0}, notFirstPrint = 0;
    cin >> k;
    vector<int> inputNums(k);
    for (int i = 0; i < k; i++) {
        cin >> n;
        inputNums[i] = n;
        if (coverNums[n] == 1) continue;
        while (n != 1) {
            if (n % 2 != 0) n = 3 * n + 1;
            n /= 2;
            if (n < 101) {  // n在计算过程中可能超过100
                if (coverNums[n]) break;
                coverNums[n] = 1;
            }
        }
    }
    sort(inputNums.begin(), inputNums.end(), [](int a, int b) { return a > b; });
    for (int num: inputNums) {
        if (coverNums[num]) continue;
        if (notFirstPrint) cout << " ";  // 不是第一次输出先输出空格
        cout << num;
        notFirstPrint = 1;
    }
    return 0;
}