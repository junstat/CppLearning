#include "../../../DataStructure/ListNode.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        // 先将链表成环，并记录链表的长度
        // tmp会记录链表的最后一个节点
        int tot = 1;
        auto tmp = head;
        while (tmp->next != nullptr) {
            tot++;
            tmp = tmp->next;
        }
        // 正式成环
        tmp->next = head;
        // 找到破坏的位置的前一个节点
        k = tot - (k % tot) - 1;
        tmp = head;
        while (k--) tmp = tmp->next;
        // 破坏，并记录新的头节点
        auto newHead = tmp->next;
        tmp->next = nullptr;
        return newHead;
    }
};