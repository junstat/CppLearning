#include <string>

using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        int k = 0, prev = 'z';
        for (const auto &c: word) {
            k += c <= prev;
            prev = c;
        }
        return k * 3 - word.size();
    }
};