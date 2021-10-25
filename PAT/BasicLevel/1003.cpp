//
// Created by jun on 2020/4/24.
//

#include "BasicLevel.h"
/*
    1、形如xPATx都可以获得"答案正确"
    以下为正确:
    I.   PAT
    II.  APATA
    III. AAPATAA
    IV.  AAAPATAAA
    ==> 规律: 中间一个A，两边等量的A
    2、aPbTc是正确的，那么aPbATca也是正确的
    以I、II、III、IV、为例
    I.   PAT --> (as aPbTc)a=c=""，b="A" --> PAAT、PAAAAAT,中间多少个A均正确
    II.  APATA --> a=b=c="A" --> APAATAA(a="A", b=c="AA") --> APAAATAAA
    III. AAPATAA --> a=c="AA", b="A" --> AAPAATAAAA --> AAPAAATAAAAAA
    summary:
    1、仅含PAT
    2、P在T之前
    3、len(c) = len(a) * len(b)
    设输入为s，如
    01234
    APATA
    len(a) = pLastIndex
    len(b) = tLastIndex - pLastIndex - 1
    len(c) = len(s) - tLastIndex - 1

    key point:
    map
*/

int basicLevel1003() {
#ifdef ONLINE_JUDGE
#else
    freopen("1003.input", "r", stdin);
#endif
    int n, pLastIndex = 0, tLastIndex = 0, len_a = 0, len_b = 0, len_c = 0;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        map<char, int> countMap;
        for (int j = 0; j < s.size(); j++) {
            countMap[s[j]]++;
            if (s[j] == 'P') pLastIndex = j;
            else if (s[j] == 'T') tLastIndex = j;
        }
        len_a = pLastIndex;
        len_b = tLastIndex - pLastIndex - 1;
        len_c = s.size() - tLastIndex - 1;
        if (countMap.size() == 3 &&
            countMap['P'] == 1 &&
            countMap['T'] == 1 &&
            countMap['A'] > 0 &&
            tLastIndex - pLastIndex > 1 &&
            len_a * len_b == len_c)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
