//
// @Time   : 2021/1/13 20:52
// @Author : junstat@163.com

#include "BasicLevel.h"
/*
   1. 数据分类: input num -> vectors[5]
   2. 对于每一类数据按照要求计算结果并输出即可
        2.1 偶数和
        2.2 交错和
        2.3 cnt
        2.4 平均数, 要求 %.1f
        2.5 max
 */
int basicLevel1012() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1012.txt", "r", stdin);
#endif
    vector<int> nums[5];
    int n, num, res1 = 0, res2 = 0, res5 = 0;
    double res4 = 0;
    cin >> n;
    // 1. input value
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums[num % 5].push_back(num);
    }

    // 2. calculating
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            if (i == 0 && nums[i][j] % 2 == 0) res1 += nums[i][j];
            else if (i == 1 && j % 2 == 0) res2 += nums[i][j];
            else if (i == 1 && j % 2 != 0) res2 -= nums[i][j];
            else if (i == 3) res4 += nums[i][j];
            else if (i == 4 && nums[i][j] > res5) res5 = nums[i][j];
        }
    }

    // 3. output
    for (int i = 0; i < 5; i++) {
        if (i) printf(" ");
        if ( ( i == 0 && res1 == 0) || ( i != 0 && nums[i].empty() ) ){
            printf("N");
            continue;
        }
        if ( i == 0 ) printf("%d", res1);
        else if ( i == 1 ) printf("%d", res2);
        else if ( i == 2 ) printf("%lu", nums[2].size());
        else if ( i == 3 ) printf("%.1f", res4 / nums[3].size());
        else if ( i == 4 ) printf("%d", res5);
    }
    return 0;
}