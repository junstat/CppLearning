#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return isIsomorphicAux(s, t) && isIsomorphicAux(t, s);
    }

    bool isIsomorphicAux(const string &s, const string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> mp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = t[i];
            } else if (mp[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};