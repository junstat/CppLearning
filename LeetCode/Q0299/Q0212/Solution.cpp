#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        m = board.size(), n = board[0].size();
        for (const auto &w: words) insert(w);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int u = board[i][j] - 'a';
                if (root->tns[u] != nullptr) {
                    vis[i][j] = true;
                    dfs(i, j, root->tns[u], board);
                    vis[i][j] = false;
                }
            }
        }
        for (const auto &s: uniqWords) ans.push_back(s);
        return ans;
    }

private:
    struct TrieNode {
        string s;
        TrieNode *tns[26];
    };

    TrieNode *root = new TrieNode();

    set<string> uniqWords;
    vector<string> ans;
    int dirs[4][2] = {{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}};
    int n, m;
    bool vis[15][15];

    void insert(const string s) {
        TrieNode *p = root;
        for (char c: s) {
            int u = c - 'a';
            if (!p->tns[u]) p->tns[u] = new TrieNode();
            p = p->tns[u];
        }
        p->s = s;
    }

    void dfs(int &i, int &j, TrieNode *node, vector<vector<char>> &board) {
        if (!node->s.empty()) uniqWords.insert(node->s);
        for (const auto &d: dirs) {
            int dx = i + d[0], dy = j + d[1];
            if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
            if (vis[dx][dy]) continue;
            int u = board[dx][dy] - 'a';
            if (node->tns[u] != nullptr) {
                vis[dx][dy] = true;
                dfs(dx, dy, node->tns[u], board);
                vis[dx][dy] = false;
            }
        }
    }
};