#include <string>
#include <vector>

using namespace std;

class MagicDictionary {
public:
    MagicDictionary() {
        tr.resize(N, vector<int>(M, 0));
        isEnd.resize(N * M, false);
    }

    void add(string s) {
        int p = 0;
        for (auto c: s) {
            int u = c - 'a';
            if (!tr[p][u]) tr[p][u] = ++idx;
            p = tr[p][u];
        }
        isEnd[p] = true;
    }

    bool query(string s, int curI, int p, int limit) {
        if (limit < 0) return false;
        if (curI == s.size()) return isEnd[p] && limit == 0;
        int u = s[curI] - 'a';
        for (int i = 0; i < M; i++) {
            if (tr[p][i] == 0) continue;
            if (query(s, curI + 1, tr[p][i], limit - (i != u))) return true;
        }
        return false;
    }

    void buildDict(vector<string> ss) {
        for (auto s: ss) add(s);
    }

    bool search(string s) {
        return query(s, 0, 0, 1);
    }

private:
    int N = 100 * 100, M = 26, idx = 0;
    vector<vector<int>> tr;
    vector<bool> isEnd;
};