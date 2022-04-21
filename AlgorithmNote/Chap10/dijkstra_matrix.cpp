// Dijkstra算法邻接矩阵版
// Ye Qiu
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV = 1000;  // 最大顶点数
const int INF = 1e9;    // 设INF为一个很大的数

int n, G[MAXV][MAXV];   // n为顶点数，MAXV为最大顶点数
int d[MAXV];            // 起点到达各点的最短路径
bool vis[MAXV] = {false};   // 标记数组，vis[i] == true表示已访问。初值为false

void Dijkstra(int s) {  // s为起点
    fill(d, d + MAXV, INF);   // fill函数将整个d数组赋为INF(慎用memset)
    d[s] = 0;   // 起点s到达自身的距离为0
    for (int i = 0; i < n; i++) { // 循环n次
        int u = -1, MIN = INF;    // u使d[u]最小，MIN存放该最小的d[u]
        for (int j = 0; j < n; j++) { // 找到未访问的顶点中d[]中最小的
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        // 找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if (u == -1) return;
        vis[u] = true;  // 标记u为已访问
        for (int v = 0; v < n; v++) {
            // 如果v未访问 && u能到达v && 以u为中介可以使d[v]更优
            if (!vis[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

