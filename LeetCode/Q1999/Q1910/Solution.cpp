#include <string>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        return s.find(part) != string::npos ?
               removeOccurrences(s.erase(s.find(part), part.size()), part) : s;
    }
};