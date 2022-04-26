#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100];
int leaf_count[100], max_depth = -1;

void dfs(int index, int depth) {
    if (v[index].empty()) {
        leaf_count[depth]++;
        max_depth = max(max_depth, depth);
        return;
    }
    for (int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("./input/1004.txt", "r", stdin);
#endif
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 0);
    printf("%d", leaf_count[0]);
    for (int i = 1; i <= max_depth; i++)
        printf(" %d", leaf_count[i]);
    return 0;
}

