#include "../../DataStructure/ListNode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        // Find the middle of the list
        auto p = head;
        auto q = head;
        while (q->next != nullptr && q->next->next != nullptr) {    // 寻找中间结点
            p = p->next;
            q = q->next->next;
        }

        // Reverse the half after middle
        q = p->next;    // slow所指结点为中间结点，q为后半段链表的首结点
        p->next = nullptr;
        while (q != nullptr) {       // 把q逐个取下
            auto r = q->next;        // 防断链
            q->next = p->next;       // 把q插入到p与p->next之间
            p->next = q;
            q = r;
        }

        // Start reorder node by node
        auto s = head;        // s指向前半段的第一个数据点，即插入点
        q = p->next;                // q指向后半段的第一个数据点
        p->next = nullptr;
        while (q != nullptr) {
            auto r = q->next;       // 防断链
            q->next = s->next;      // q插入到 s与s->next之间
            s->next = q;
            s = q->next;            // s指向下一个插入位置
            q = r;
        }
    }
};