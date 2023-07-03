#include "../../DataStructure/ListNode.h"

class Solution {
public:
    /*-------------------------------------------------------------------------
     递归实现
     设f(l1, l2)为递归功能函数
     递归终止条件:
            f(l1, l2) = l2; 若 l1 == nullptr
            f(l1, l2) = l1; 若 l2 == nullptr
     递归主体:
            f(l1, l2) = l1 + f(l1->next, l2);   若l1的值 < l2
            f(l1, l2) = l2 + f(l1, l2->next);   else
     ------------------------------------------------------------------------*/
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr || l2 == nullptr) return l1 != nullptr ? l1 : l2;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};