#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        vector<string> row;
        for (int i = 0; i < n;) {
            // row装载当前行所有word
            row.clear();
            row.push_back(words[i]);
            int cur = words[i++].size();
            while (i < n && cur + 1 + words[i].size() <= maxWidth) {
                cur += 1 + words[i].size();
                row.push_back(words[i++]);
            }

            // 当前行为最后一行，特殊处理为左对齐
            if (i == n) {
                string s = row[0];
                for (int k = 1; k < row.size(); ++k) {
                    s.append(" ");
                    s.append(row[k]);
                }
                while (s.size() < maxWidth) s.append(" ");
                ans.push_back(s);
                break;
            }
            // 如果当前行只有一个word，特殊处理为左对齐
            int cnt = row.size();
            if (cnt == 1) {
                string s = row[0];
                while (s.size() != maxWidth) s.append(" ");
                ans.push_back(s);
                continue;
            }

            // 其余为一般情况
            // wordWidth: 当前行单词总长度
            // spaceWidth: 当前行空格总长度
            // spaceItem: 往下取整后的单位空格长度
            int wordWidth = cur - (cnt - 1);
            int spaceWidth = maxWidth - wordWidth;
            int spaceItemWidth = spaceWidth / (cnt - 1);
            string spaceItem = "";
            for (int k = 0; k < spaceItemWidth; ++k)spaceItem.append(" ");
            string s;
            for (int k = 0, sum = 0; k < cnt; ++k) {
                string item = row[k];
                s.append(item);
                if (k == cnt - 1) break;
                s.append(spaceItem);
                sum += spaceItemWidth;
                // 剩余的间隙数量(可填入空格的次数)
                int remain = cnt - k - 1 - 1;
                // 剩余间隙数量 * 最小单位空格长度 + 当前空格长度 < 单词总长度
                // 则在当前间隙多补充一个空格
                if (remain * spaceItemWidth + sum < spaceWidth) {
                    s.append(" ");
                    ++sum;
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};