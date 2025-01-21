class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = get_next(slow);
            fast = get_next(get_next(fast));
        } while (slow != fast);
        return slow == 1;
    }

    int get_next(int n) {
        int ans = 0;
        while (n > 0) {
            int digit = n % 10;
            ans += digit * digit;
            n /= 10;
        }
        return ans;
    }
};