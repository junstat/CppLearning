//
// Created by jun on 2021/1/11.
//

#include "BasicLevel.h"
/*
 * 10的100次幂已经超过long long的范围，只能用string保存；
 * 遍历数据源，逐位转成数字，并求和；
 */


/**
 * key point:
 * 数组：
 * string api
 * int -> str
 * str -> int
 */

using namespace std;

int basicLevel1002() {
#ifdef ONLINE_JUDGE
#else
    freopen("1002.input", "r", stdin);
#endif
    int res = 0;
    string source;
    string str[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    cin >> source;
    for (char c: source) {
        res += (c - '0');
    }
    string strRes = to_string(res);
    for (int i = 0; i < strRes.size(); i++) {
        if (i != 0) cout << " ";
        cout << str[strRes[i] - '0'];
    }
    return 0;
}