#include <string>
#include <valarray>
#include <cstring>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int index[26][2], res = 0, N = s.length(), mod = pow(10, 9) + 7;
        memset(index, -1, sizeof(int) * 52);
        for (int i = 0; i < N; ++i) {
            int c = s[i] - 'A';
            res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (auto & c : index)
            res = (res + (N - c[1]) * (c[1] - c[0]) % mod) % mod;
        return res;
    }
};