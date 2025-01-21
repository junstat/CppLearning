#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <cctype>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string ans;
        trim(s);
        split(s, "\\s+", words);
        reverse(words.begin(), words.end());
        join(words, ' ', ans);
        return ans;
    }

    void trim(string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));

        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    void split(const string &source, const string &delimiter, vector<string> &dest) {
        std::regex rgx(delimiter);
        std::sregex_token_iterator iter(source.begin(), source.end(), rgx, -1);
        std::sregex_token_iterator end;

        for (; iter != end; ++iter) {
            dest.push_back(*iter);
        }
    }

    void join(const vector<string> &source, const char &delim, string &dest) {
        for (int i = 0; i < source.size(); i++) {
            dest += source[i];
            if (i != source.size() - 1) {
                dest += delim;
            }
        }
    }
};

