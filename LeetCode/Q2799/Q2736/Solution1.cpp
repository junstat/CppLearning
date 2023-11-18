#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <unordered_map>


using namespace std;

struct SegmentTree {
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size - 1, INT_MIN);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) tree[x] = a[lx];
            return;
        }
        int m = lx + (rx - lx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<int> &a) {
        build(a, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return INT_MIN;
        if (lx >= l && rx <= r) return tree[x];
        int m = lx + (rx - lx) / 2;
        int leftMax = query(l, r, 2 * x + 1, lx, m);
        int rightMax = query(l, r, 2 * x + 2, m, rx);
        return max(leftMax, rightMax);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = max(tree[x], v);
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i < m) {
            update(i, v, 2 * x + 1, lx, m);
        } else {
            update(i, v, 2 * x + 2, m, rx);
        }
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
        vector<vector<int>> envelopes;

        set<int> rv;
        // insert both data and query into envelopes array
        // remember to store their heights in an ordered set for mapping
        for (int i = 0; i < nums1.size(); ++i) {
            envelopes.push_back({nums1[i], nums2[i], -1});
            rv.insert(nums2[i]);
        }
        for (int i = 0; i < queries.size(); ++i) {
            envelopes.push_back({queries[i][0], queries[i][1], i});
            rv.insert(queries[i][1]);
        }
        sort(envelopes.begin(), envelopes.end(), cmp);
        reverse(envelopes.begin(), envelopes.end());

        // generate the mapping for height to index
        unordered_map<int, int> mapping;
        int counter = 0;
        for (auto e: rv) {
            mapping[e] = counter;
            counter++;
        }

        // create a segment tree with the size of set of heights
        SegmentTree st(counter);
        vector<int> ans(queries.size());
        for (auto envelope: envelopes) {
            if (envelope[2] != -1) {
                // if it is a query, check the segment tree
                int val = st.query(mapping[envelope[1]], counter);
                ans[envelope[2]] = val == INT_MIN ? -1 : val;
            } else {
                // if it is data, insert into the segment tree
                st.update(mapping[envelope[1]], envelope[0] + envelope[1]);
            }
        }

        return ans;
    }

    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                return a[2] > b[2];
            }
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};