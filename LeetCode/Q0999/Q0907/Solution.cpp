#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        long ans = 0;
        stack<int> st;
        for (int i = -1; i <= n; i++) {
            while (!st.empty() && getElement(arr, n, st.top()) > getElement(arr, n, i)) {
                int cur = st.top();
                st.pop();
                ans = (ans + (long) (cur - st.top()) * (i - cur) * arr[cur]) % MOD;
            }
            st.push(i);
        }
        return (int) ans;
    }

    int getElement(vector<int> &arr, int n, int i) {
        return (i == -1 || i == n) ? INT_MIN : arr[i];
    }

    long MOD = 1e9 + 7;
};