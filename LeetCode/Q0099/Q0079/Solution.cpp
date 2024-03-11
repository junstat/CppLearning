#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, board, word, visited)) return true;
            }
        }
        return false;
    }

    bool dfs(int i, int j, vector<vector<char>> &board, const string &word, vector<vector<bool>> &visited) {
        if (pathLen == word.length()) return true;
        bool ans = false;
        if (i >= 0 && i < m && j >= 0 && j < n
            && board[i][j] == word[pathLen]
            && !visited[i][j]) {
            ++pathLen;
            visited[i][j] = true;
            ans = dfs(i, j - 1, board, word, visited)
                  || dfs(i - 1, j, board, word, visited)
                  || dfs(i, j + 1, board, word, visited)
                  || dfs(i + 1, j, board, word, visited);
            if (!ans) {
                --pathLen;
                visited[i][j] = false;
            }
        }
        return ans;
    }

    int m, n;
    int pathLen = 0;
};