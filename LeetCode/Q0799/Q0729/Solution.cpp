#include <cstdint>
#include <vector>

using namespace std;

struct Node {
    int32_t ls{0};  // left son
    int32_t rs{0};  // right son
    int32_t add{0}; // lazy tag
    int32_t val{0}; // 当前节点有多少数

    Node() = default;
};

class MyCalendar {
public:
    MyCalendar() {
        tr.resize(M);
    }

    bool book(int startTime, int endTime) {
        if (query(1, 1, N + 1, startTime + 1, endTime) > 0) {
            return false;
        }
        update(1, 1, N + 1, startTime + 1, endTime, 1);
        return true;
    }

    void update(int32_t u, int32_t lc, int32_t rc, int32_t l, int32_t r, int32_t v) {
        if (l <= lc && rc <= r) {
            tr[u]->val += (rc - lc + 1) * v;
            tr[u]->add += v;
            return;
        }
        lazyCreate(u);
        pushDown(u, rc - lc + 1);
        int32_t mid = (lc + rc) >> 1;
        if (l <= mid) update(tr[u]->ls, lc, mid, l, r, v);
        if (r > mid) update(tr[u]->rs, mid + 1, rc, l, r, v);
        pushUp(u);
    }

    int32_t query(int32_t u, int32_t lc, int32_t rc, int32_t l, int32_t r) {
        if (l <= lc && rc <= r) {
            return tr[u]->val;
        }
        lazyCreate(u);
        pushDown(u, rc - lc + 1);
        int32_t mid = (lc + rc) >> 1;
        int32_t ans = 0;
        if (l <= mid) ans = query(tr[u]->ls, lc, mid, l, r);
        if (r > mid) ans += query(tr[u]->rs, mid + 1, rc, l, r);
        return ans;
    }

    void lazyCreate(int32_t u) {
        if (tr[u] == nullptr) {
            tr[u] = new Node;
        }
        if (tr[u]->ls == 0) {
            tr[u]->ls = ++cnt;
            tr[tr[u]->ls] = new Node;
        }
        if (tr[u]->rs == 0) {
            tr[u]->rs = ++cnt;
            tr[tr[u]->rs] = new Node;
        }
    }

    void pushDown(int32_t u, int32_t len) {
        tr[tr[u]->ls]->add += tr[u]->add;
        tr[tr[u]->rs]->add += tr[u]->add;
        tr[tr[u]->ls]->val += tr[u]->add * (len - len / 2);
        tr[tr[u]->rs]->val += tr[u]->add * (len / 2);
        tr[u]->add = 0;
    }

    void pushUp(int32_t u) {
        tr[u]->val = tr[tr[u]->ls]->val + tr[tr[u]->rs]->val;
    }


private:
    const int32_t N = 1e9;
    const int32_t M = 120010;
    int32_t cnt = 1;

    vector<Node *> tr;
};