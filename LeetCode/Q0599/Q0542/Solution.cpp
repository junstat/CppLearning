#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &A) {
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) if (A[i][j] != 0) A[i][j] = 0x3f3f3f3f;

        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = min(A[i][j],
                              min(i - 1 >= 0 ? A[i - 1][j] + 1 : INT_MAX,
                                  j - 1 >= 0 ? A[i][j - 1] + 1 : INT_MAX));
            }
        }
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                A[i][j] = min(A[i][j],
                              min(i + 1 < M ? A[i + 1][j] + 1 : INT_MAX,
                                  j + 1 < N ? A[i][j + 1] + 1 : INT_MAX));
            }
        }
        return A;
    }
};