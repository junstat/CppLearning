#include <vector>
#include <algorithm>

using namespace std;

class Bank {
public:
    Bank(vector<long long> &balance) {
        nums_ = std::move(balance);
        n_ = static_cast<int>(nums_.size());
    }

    bool transfer(int account1, int account2, long long money) {
        if (!checkAccount(account1) ||
            !checkAccount(account2) ||
            nums_[account1 - 1] < money) {
            return false;
        }
        nums_[account1 - 1] -= money;
        nums_[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!checkAccount(account)) {
            return false;
        }
        nums_[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!checkAccount(account) || nums_[account - 1] < money) {
            return false;
        }
        nums_[account - 1] -= money;
        return true;
    }


private:
    bool checkAccount(int account) const {
        return 1 <= account && account <= n_;
    }

private:
    int n_{0};
    vector<long long> nums_;
};
