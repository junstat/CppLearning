//
// @Time   : 2021/1/16 10:58
// @Author : junstat@163.com

#include "BasicLevel.h"

/*
   1、德 >= H && 才 >= H  →  才德全尽， 按总分排序   一类
   2、德 >= H && 才 < H  →  德胜才，按总分排序 二类
   3、德 < H && 才 < H && 德 >= 才  →  “才德兼亡”但尚有“德胜才”，按总分排序 三类
   4、德 >= L && 才 >= L  →  录取，按总分排序，四类

   注意: 当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
 */

struct student {
    int id;
    int morality;
    int ability;
} input;

int basicLevel1015() {
#ifdef ONLINE_JUDGE
#else
    freopen("1015.input", "r", stdin);
#endif
    int n, l, h, m;
    cin >> n >> l >> h;
    m = n;
    vector<student> sortedStudents[4];
    for (int i = 0; i < n; i++) {
//        cin >> input.id >> input.morality >> input.ability;
        scanf("%d %d %d\n", &input.id, &input.morality, &input.ability);
        if (input.morality < l || input.ability < l) {
            m--;
        } else if (input.morality >= h && input.ability >= h) {
            sortedStudents[0].push_back(input);
        } else if (input.morality >= h && input.ability < h) {
            sortedStudents[1].push_back(input);
        } else if (input.morality < h && input.ability < h && input.morality >= input.ability) {
            sortedStudents[2].push_back(input);
        } else {
            sortedStudents[3].push_back(input);
        }
    }
    printf("%d\n", m);
    auto cmp = [](student a, student b) {
        if ((a.morality + a.ability) != (b.morality + b.ability))
            return (a.morality + a.ability) > (b.morality + b.ability);
        else if (a.morality != b.morality) {
            return a.morality > b.morality;
        } else {
            return a.id < b.id;
        }
    };
    for (auto &group: sortedStudents) {
        sort(group.begin(), group.end(), cmp);
        for (auto stu: group) {
            printf("%d %d %d\n", stu.id, stu.morality, stu.ability);
        }
    }
    return 0;
}