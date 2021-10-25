//
// Created by jun on 2021/1/11.
//

#include "BasicLevel.h"

/*
 * 1. 预设最好成绩 maxScore = -1, 最低成绩minScore = 101,
 *    maxScoreName, maxScoreStuNum, minScoreName, minScoreStuNum
 * 2. 遍历读入 name, stuNum, score 根据score值，更新相应信息
 */

int basicLevel1004() {
#ifdef ONLINE_JUDGE
#else
    freopen("1004.input", "r", stdin);
#endif
    int n, score, maxScore = -1, minScore = 101;
    string name, stuNum, maxScoreName, maxScoreStuNum, minScoreName, minScoreStuNum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> name >> stuNum >> score;
        if (score > maxScore) {
            maxScore = score;
            maxScoreName = name;
            maxScoreStuNum = stuNum;
        }
        if (score < minScore) {
            minScore = score;
            minScoreName = name;
            minScoreStuNum = stuNum;
        }
    }
    cout << maxScoreName << " " << maxScoreStuNum << "\n"
         << minScoreName << " " << minScoreStuNum;
    return 0;
}
