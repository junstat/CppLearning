#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        for (int i = a.size() - 1, j = b.size() - 1;
             i >= 0 || j >= 0;
             i--, j--) {
            int sum = carry;
            sum += i >= 0 ? a[i] - '0' : 0;
            sum += j >= 0 ? b[j] - '0' : 0;
            carry = sum >> 1;
            ans.push_back('0' + (sum & 1));
        }
        if (carry) ans.push_back('0' + carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};