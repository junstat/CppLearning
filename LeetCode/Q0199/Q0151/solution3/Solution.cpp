#include <queue>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        size_t start = 0;
        size_t end = s.size() - 1;
        while (start <= end && s[start] == ' ') {
            ++start;
        }
        while (start <= end && s[end] == ' ') {
            --end;
        }
        deque<string> dq;
        string word;
        while (start <= end) {
            char c = s[start];;
            if (!word.empty() && c == ' ') {
                dq.push_front(std::move(word));
                word = "";
            } else if (c != ' ') {
                word.push_back(c);
            }
            ++start;
        }
        dq.push_front(std::move(word));
        string ans;
        join(dq, " ", ans);
        return ans;
    }

    void join(const deque<string> &dq, const string &delimiter, string &ans) {
        stringstream ss;
        for (auto it = dq.begin(); it != dq.end(); ++it) {
            ss << *it;
            if (std::next(it) != dq.end()) {
                ss << delimiter;
            }
        }
        ans = ss.str();
    }
};