#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    string GetData(const string &data) {
        istringstream iss(data);
        vector<string> words;
        string word;
        while (iss >> word) words.push_back(word);
        auto ans = to_string(str2hex(words[2] + words[3])) + ",";
        bitset<8> bit3(str2hex(words[6]));
        ans += to_string(stoi(bit3.to_string().substr(0, 3), nullptr, 2)) + ",";
        auto n = words.size();
        ans += to_string(str2hex(words[n - 4]));
        for (auto i = n - 3; i < n; i++)
            ans += "." + to_string(str2hex(words[i]));
        return ans;
    }

    int str2hex(const string &s) {
        return stoi(s, nullptr, 16);
    }
};

// 以下为考题输入输出框架，此部分代码不建议改动
int main()
{
    string data;
    getline(cin, data);
    Solution solution;
    cout << solution.GetData(data);
    return 0;
}
