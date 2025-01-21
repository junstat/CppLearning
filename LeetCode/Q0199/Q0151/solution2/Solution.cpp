#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverseString(s, 0, s.size() - 1);
        reverseWordsAux(s);
        return cleanSpace(s);
    }

    string cleanSpace(string &s) {
        size_t n = s.size();
        size_t start = 0;
        size_t end = 0;
        while (end < n) {
            while (end < n && s[end] == ' ') {
                end++;
            }
            while (end < n && s[end] != ' ') {
                s[start++] = s[end++];
            }
            while (end < n && s[end] == ' ') {
                end++;
            }
            if (end < n) s[start++] = ' ';
        }
        return s.substr(0, start);
    }

    void reverseString(string &s, size_t start, size_t end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

    void reverseWordsAux(string &s) {
        size_t n = s.size();
        size_t start = 0;
        size_t end = 0;
        while (start < n) {
            while (start < end || start < n && s[start] == ' ') {
                start++;
            }
            while (end < start || end < n && s[end] != ' ') {
                end++;
            }
            reverseString(s, start, end - 1);
        }
    }
};
