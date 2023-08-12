class Solution {
public:
    bool isPalindrome(int x) {
        // 对于 负数 和 x0、x00、x000 格式的数，直接返回 false
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int t = 0;
        while (x > t) {
            t = t * 10 + x % 10;
            x /= 10;
        }
        // 回文长度的两种情况：直接比较 & 忽略中心点（t 的最后一位）进行比较
        return x == t || x == t / 10;
    }
};