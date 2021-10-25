#include <iostream>

using namespace std;
typedef int ElementType;

class DNode {
public:
    ElementType data;
    int freq;
    DNode *pred, *next;
};

typedef DNode *DNodePointer;

/*-------------------------------------------------------------------------
 20. 设头指针为L的带头结点的非循环双向链表，其每个结点中除有pred(前驱指针)、data(数据)
 和next(后继指针)域外，还有一个访问频度域freq。在链表被启用前，其值均初始化为零。每当在
 链表中进行一次Locate(L, x)运算时，令元素值为x的结点中freq域的值增1，并使此链表中结点
 保持按访问频度访问的结点总是靠近表头。试编写符合上述要求的Locate(L, x)运算的算法，该运
 算为函数过程，返回找到结点的地址，类型为指针。

 算法思想: 首先在双向链表中查找数据值为x的结点，查到后，将结点从链表上摘下，然后顺着结点
 的前趋链查找该结点的插入位置(频度递减，且排在同频度的第一个，即向前找到第一个比它的频度
 大的结点，插入位置为该结点之后)，并插入到该位置。
 ------------------------------------------------------------------------*/
DNodePointer locate(DNodePointer &L, ElementType x) {
    // 先查找数据x，查找成功时结点的访问频度域增1
    // 最后将该结点按频度递减插入链表中适当位置(同频度最近访问的在前面)
    DNodePointer p = L->next, q;        // p为工作指针，q为p的前驱，用于查找插入位置
    while (p && p->data != x)
        p = p->next;                    // 查找值为x的结点
    if (!p) {
        cout << "不存在值为x的结点\n";
        exit(0);
    } else {
        p->freq++;              // 令元素值为x的结点的freq域加1
        if (p->next) p->next->pred = p->pred;
        p->pred->next = p->next;        // 将p结点从链表上摘下
        q = p->pred;            // 以下查找p结点的插入位置
        while (q != L && q->freq <= p->freq)
            q = q->pred;
        p->next = q->next;
        q->next->pred = p;      // 将p结点插入，一定是排在同频率的第一个
        p->pred = q;
        q->next = p;
    }
    return p;                   // 返回值为x的结点的指针
}