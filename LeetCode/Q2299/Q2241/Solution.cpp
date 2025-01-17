#include <vector>
#include <algorithm>

using namespace std;

class ATM {
    static constexpr int DENOMINATIONS[] = {20, 50, 100, 200, 500};
    static constexpr int KINDS = size(DENOMINATIONS);

    int banknotes[KINDS]{};

public:
    void deposit(vector<int> banknotesCount) {
        // 存钱
        for (int i = 0; i < KINDS; i++) {
            banknotes[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> ans(KINDS);

        // 计算每种钞票所需数量
        for (int i = KINDS - 1; i >= 0; i--) {
            ans[i] = min(amount / DENOMINATIONS[i], banknotes[i]);
            amount -= ans[i] * DENOMINATIONS[i];
        }

        // 无法取恰好 amount
        if (amount > 0) {
            return {-1};
        }

        // 取钱
        for (int i = 0; i < KINDS; i++) {
            banknotes[i] -= ans[i];
        }

        return ans;
    }
};
