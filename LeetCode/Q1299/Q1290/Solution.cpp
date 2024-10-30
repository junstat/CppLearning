#include "ListNode.h"

/*-------------------------------------------------------------------------
 1) 多项式 a_n*x^n + ... + a_1*x + a_0
         = ((a_n*x+a_{n-1})*x + ... + a_1)*x + a_0)
    如，取 n = 2
          a_2*x^2+a_1*x+a0 = (a_2*x+a_1)*x + a_0
 2) 对于编程实现来说，给定 a_2 -> a_1 -> a_0
    初始时，设定 res = 0
    通过 res = res * x + a_i  可以累加求得结果
 3) 当 x =2 时，通过位运算可以改造 res = res * x + a_i
    为  res = res << 1 | a_i
 ------------------------------------------------------------------------*/
class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int ans = 0;
        while (head) {
            ans = (ans << 1) | head->val;
            head = head->next;
        }
        return ans;
    }
};