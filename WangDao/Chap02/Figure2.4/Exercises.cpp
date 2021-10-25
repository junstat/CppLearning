#include "CircularLinkedList.h"
#include "DoubleCircularLinkedList.h"

/*-------------------------------------------------------------------------
 17. 设计一个算法用于判断带头结点的循环双链表是否对称。

 算法思想: 让p从左向右扫描，q从右向左扫描，直到它们指向同一结点(p == q，当循环双链表
 中结点个数为奇数时)或相邻(p->next=q或q->prior=p，当循环双链表中结点个数为偶数时)为
 止，若它们所指结点值相同，则继续进行下去，否则返回false。若比较全部相等，则返回true。
 ------------------------------------------------------------------------*/
bool symmetry(DNodePointer L) {
    DNodePointer p = L->next, q = L->prior;     // 两头工作指针
    while (p != q && q->next != p) {
        if (p->data == q->data) {           // 所指结点值相同则继续比较
            p = p->next;
            q = q->next;
        } else return false;
    }
    return true;
}

/*-------------------------------------------------------------------------
 18. 有两个循环单链表，链表头指针分别为h1和h2，编写一个函数将链表h2链接到链表h1之后，要
 求链接后的链表仍保持循环链表形式。

 算法思想: 先找到两个链表的尾指针，将第一个链表的尾指针与第二个链表的头指针链接起来，再使
 之成为循环的。
 ------------------------------------------------------------------------*/
NodePointer linkTwoCircularList(NodePointer &h1, NodePointer &h2) {
    NodePointer p, q;       // 分别指向两个链表的尾结点
    p = h1;
    while (p->next != h1)   // 寻找h1的尾结点
        p = p->next;
    q = h2;
    while (q->next != h2)   // 寻找h2的尾结点
        q = q->next;
    p->next = h2;           // 将h2链接到h1之后
    q->next = h1;           // 令h2的尾结点指向h1
    return h1;
}

/*-------------------------------------------------------------------------
 19. 设有一个带头结点的循环单链表，其结点值均为正整数。设计一个算法，反复找出单链表中结点
 值最小的结点并输出，然后将该结点从中删除，直到单链表空为止，再删除表头结点。

 算法思想: 对于循环单链表L，在不空时循环: 每循环一次查找一个最小结点(由minP指向最小值结点，
 minPre指向其前驱结点)并删除它。最后释放头结点。
 ------------------------------------------------------------------------*/
void deleteMin(NodePointer &L) {
    NodePointer p, pre, minP, minPre;
    while (L->next != L) {
        p = L->next;
        pre = L;
        minP = p;
        minPre = pre;
        while (p != L) {
            if (p->data < minP->data) {
                minP = p;             // 找到值更小的结点
                minPre = pre;
            }
            pre = p;
            p = p->next;
        }
        cout << minP->data << " ";
        minPre->next = minP->next;
        delete minP;
        minP = nullptr;
    }
    delete L;
}