//
// Created by jun on 2020/7/18.
//
#include "BasicLevel.h"

/*
   input word -> stack words;
 */

int basicLevel1009() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1009.txt", "r", stdin);
#endif
    stack <string> words;
    string word;
    int notFirstPrint = 0;
    while (cin >> word)
        words.push(word);
    while (!words.empty()) {
        if (notFirstPrint) cout << " ";
        cout << words.top();
        words.pop();
        notFirstPrint = 1;
    }
    return 0;
}


int useVector() {
    // 2021-01-12 update
    vector<string> words;
    string word;
    while (cin >> word)
        words.push_back(word);

    reverse(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++) {
        if (i) cout << " ";
        cout << words[i];
    }
    return 0;
}