#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        sort(changed.begin(), changed.end());
        vector<int> ans;
        unordered_multiset<int> mark;
        for (int x: changed) {
            auto it = mark.find(x);
            if (it == mark.end()) { // x 不是双倍后的元素
                mark.insert(x * 2); // 标记一个双倍元素
                ans.push_back(x);
            } else { // x 是双倍后的元素
                mark.erase(it); // 清除一个标记
            }
        }
        // 只有所有双倍标记都被清除掉，才能说明 changed 是一个双倍数组
        return mark.empty() ? ans : vector<int>();
    }
};
