#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        combination(ans, cur, 1, k, n);
        return ans;
    }

    void combination(vector<vector<int>> &ans, vector<int> &cur, int start, int k, int n) {
        if (cur.size() == k && n == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i <= 9; i++) {
            cur.push_back(i);
            combination(ans, cur, i + 1, k, n - i);
            cur.pop_back();
        }
    }
};