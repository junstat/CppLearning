#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries) {
        int m = logs.size();
        vector<pair<int, int>> vp;
        for (const auto &it: logs) vp.emplace_back(it[1], it[0]);
        sort(vp.begin(), vp.end());

        auto q = queries.size();
        unordered_map<int, int> map; // to store the unique server ids in the current window

        vector<int> ans(q, 0);
        vector<pair<int, int>> time(q);
        for (int i = 0; i < q; ++i) time[i] = {queries[i], i};
        sort(time.begin(), time.end());
        int i = 0, j = 0;
        for (const auto &[end, ind]: time) {
            int start = max(0, end - x);

            while (j < m and vp[j].first <= end) {
                map[vp[j].second]++;
                j++;
            }
            while (i < m and vp[i].first < start) {
                if (map[vp[i].second] == 1) map.erase(vp[i].second);
                else map[vp[i].second]--;
                i++;
            }
            ans[ind] = n - map.size();
        }
        return ans;
    }
};