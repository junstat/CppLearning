#include <vector>
#include "../../DataStructure/TreeNode.h"

using namespace std;

vector<TreeNode*> f[11];

auto init = [] {
    f[1] = {new TreeNode()};
    for (int i = 2; i < 11; i++) { // 计算 f[i]
        for (int j = 1; j < i; j++) { // 枚举左子树叶子数
            for (auto left : f[j]) { // 枚举左子树
                for (auto right : f[i - j]) { // 枚举右子树
                    f[i].push_back(new TreeNode(0, left, right));
                }
            }
        }
    }
    return 0;
}();

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return f[n % 2 ? (n + 1) / 2 : 0];
    }
};
