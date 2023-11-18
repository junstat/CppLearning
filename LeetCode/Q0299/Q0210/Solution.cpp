#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>()) ;

        for (const auto &item : prerequisites){
            graph[item[1]].push_back(item[0]);
            inDegree[item[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < inDegree.size(); ++i) {
            if (!inDegree[i]) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (const auto &v: graph[u]){
               inDegree[v] --;
               if (!inDegree[v]) q.push(v);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};