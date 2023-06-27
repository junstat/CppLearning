#include <vector>
#include <queue>

using namespace std;
typedef pair<int, pair<int, int>> sumPair;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        priority_queue<sumPair, vector<sumPair>, greater<>> pq;
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            pq.push({nums1[i] + nums2[0], {i, 0}});
        while (!pq.empty() && k--) {
            auto top = pq.top();
            int x = top.second.first, y = top.second.second;
            pq.pop();
            ans.push_back({nums1[x], nums2[y]});
            if (y == m - 1) continue;
            pq.push({nums1[x] + nums2[y + 1], {x, y + 1}});
        }
        return ans;
    }
};