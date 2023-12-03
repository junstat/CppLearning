#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        set<string> seen;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num == '.')
                    continue;
                if (!seen.insert(to_string(num) + " in row " + to_string(i)).second ||
                    !seen.insert(to_string(num) + " in col " + to_string(j)).second ||
                    !seen.insert(to_string(num) + " in block " + to_string(i / 3) + "_" + to_string(j / 3)).second)
                    return false;
            }
        }
        return true;
    }
};