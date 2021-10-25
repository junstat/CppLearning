//
// @Time   : 2021/1/14 20:55
// @Author : junstat@163.com

#include "BasicLevel.h"

/*
    1、寻找第1、第2个字符串中匹配的字符
        1.1 第1次匹配的字符x，
            必须: 'A' <= x <= 'G' -> week[x]
        1.2   2         y,
            必须: 数字或 'A' <= y <= 'N' -> hour
    2、遍历第3、第4个字符串，取匹配的下标 -> minute
*/

int basicLevel1014() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1014.txt", "r", stdin);
#endif
    string a, b, c, d;
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> a >> b >> c >> d;
    char t[2];
    int i, cnt = 0, hour, minute = 0;
    for (i = 0; i < a.length() && i < b.length() && cnt < 2; i++) {
        if (a[i] != b[i])  /* skipping not matched char */
            continue;
        if (cnt == 0 && (a[i] >= 'A' && a[i] <= 'G')) /* first match */
            t[cnt++] = a[i];
        else if (
                cnt == 1 && /* second match */
                ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))
                )
            t[cnt++] = a[i];
    }

    for (i = 0; i < c.length() && i < d.length(); i++) {
        if (c[i] == d[i] && isalpha(c[i])) {
            minute = i;
            break;
        }
    }
    cout << week[t[0] - 'A'];
    hour = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
    printf(" %02d:%02d", hour, minute);
    return 0;
}

