#include "LinkedList.h"
// ------------------------------- 王道综合应用题 -------------------------------

/*-------------------------------------------------------------------------
 1. 设计一个递归算法，删除不带头结点的单链表中所有值为x的结点。

 终止条件: f(L, x) = 不作任何事情;                 若L为空表
 递归主体: f(L, x) = 删除*L结点; f(L->next, x);   若L->data = x;
          f(L, x) = f(L->next, x);              其他情况
------------------------------------------------------------------------*/
void deleteXRecursion(NodePointer &L, ElementType x) {
    // 递归实现在单链表L中删除值为x的结点
    NodePointer p;          // p指向待删除结点
    if (L == nullptr)       // 递归出口
        return;
    if (L->data == x) {     // 若L所指结点的值x
        p = L;              // 删除*L，并让L指向下一结点
        L = L->next;
        delete p;
        deleteXRecursion(L, x);     // 递归调用
    } else                  // 若L所指结点的值不为x
        deleteXRecursion(L->next, x);   // 递归调用
}

/*-------------------------------------------------------------------------
 2. 在带头结点的单链表中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，
 试编写算法以实现上述操作。

 解法1: 用p从头至尾扫描单链表，pre指向*p结点的前驱。若p所指结点的值为x，则删除，并让
 p移向下一个结点，否则让pre、p指针同步后移一个结点。
 ------------------------------------------------------------------------*/
void deleteX1(NodePointer &L, ElementType x) {
    NodePointer p = L->next, pre = L, q;
    while (p) {
        if (p->data == x) {
            q = p;             // q指向该结点
            p = p->next;
            pre->next = p;     // 删除q结点
            delete q;          // 释放q结点的空间
        } else {               // 否则，pre和p同步后移
            pre = p;
            p = p->next;
        }
    }
}

/*-------------------------------------------------------------------------
 解法2: 采用尾插法建立单链表。用p指针扫描L的所有结点，当其值不为x时，将其链接到L之后，
 否则将其释放。
 ------------------------------------------------------------------------*/
void deleteX2(NodePointer &L, ElementType x) {
    NodePointer p = L->next, r = L, q;    // r指向尾结点，其初值为头结点
    while (p) {
        if (p->data != x) {     // p结点值不为x时将其链接到L尾部
            r->next = p;
            r = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            delete q;
        }
    }
    r->next = nullptr;          // 插入结束后置尾结点指针为nullptr
}

/*-------------------------------------------------------------------------
 3. 设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。

 思路: 递归输出。
 ------------------------------------------------------------------------*/
void recursionPrint(NodePointer L) {
    if (L->next != nullptr)
        recursionPrint(L->next);
    if (L != nullptr) cout << L->data << "  ";      // 输出函数
}

/*-------------------------------------------------------------------------
 4. 试编写在带头结点的单链表L中删除一个最小值结点的高效算法(假设最小值结点是唯一的)。

 算法思想: 用p从头至尾扫描单链表，pre指向p结点的前驱，用minP保存值最小的结点指针(初值为
 p)，minPre指向minP结点的前驱(初值为pre)。一边扫描一边比较，若p->data小于minP->data
 ，则将p、pre分别赋值给minP、minPre。当p扫描完毕时，minP指向最小值结点，minPre指向
 最小值结点的前驱结点，再将minP所指结点删除即可。
 ------------------------------------------------------------------------*/
void deleteMin(NodePointer &L) {
    NodePointer pre = L, p = pre->next;
    NodePointer minPre = pre, minP = p;
    while (p) {
        if (p->data < minP->data) {
            minP = p;               // 找到比之前找到的最小值结点更小的结点
            minPre = pre;
        }
        pre = p;
        p = p->next;
    }
    minPre->next = minP->next;      // 删除最小值结点
    delete minP;
}

/*-------------------------------------------------------------------------
 5. 试编写算法将带头结点的单链表就地逆置，所谓"就地"是指辅助空间复杂度为O(1)。

 解法1: 将头结点摘下，然后从第一结点开始，依次插入到头结点的后面(头插法建立单链表表)，直
 到最后一个结点为止。
 ------------------------------------------------------------------------*/
NodePointer reverse1(NodePointer &L) {
    NodePointer p, r;       // p为工作指针，r为p的后继，以防断链
    p = L->next;         // 从第一个元素结点开始
    L->next = nullptr;   // 先将头结点的next域置为nullptr
    while (p) {
        r = p->next;            // 暂存p的后继
        p->next = L->next;   // 将p结点插入到头结点之后
        L->next = p;
        p = r;
    }
    return L;
}

/*-------------------------------------------------------------------------
 解法2: 假设pre、p和r指向3个相邻的结点。假设经过若干操作后，pre之前的结点的指针都已
 调整完毕，它们的next都指向其原前驱结点。现在令p结点的next域指向pre结点，注意到一旦
 调整指针的指向，p的后继结点的链就会断开，为此需要用r来指向原p的后继结点。处理时需要
 注意两点：一是在处理第一个结点时，应将其next域置为nullptr，而不是指向头结点(因为它将
 作为新表的尾结点)；二是在处理完最后一个结点后，需要将头结点的指针指向它。
                    pre        p        r               a_n
 [ ]    ->   ...   [  ]  ->   [  ]    [   ] -> ... -> [  ]
  head
 ------------------------------------------------------------------------*/
NodePointer reverse2(NodePointer &L) {
    NodePointer pre, p = L->next, r = p->next;
    p->next = nullptr;      // 处理第一个结点
    while (r) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;      // 指针反转
    }
    L->next = p;         // 处理最后一个结点
    return L;
}

/*-------------------------------------------------------------------------
 6. 有一个带头结点的单链表L，设计一个算法使其元素递增有序。

 算法思想: 采用直接插入排序算法的思想，先构成只含一个数据结点的有序单链表，然后依次扫描
 单链表中剩下的结点p(直至p==nullptr为止)，在有序表中通过比较查找插入p的前驱结点pre，
 然后将p插入到pre之后。
 ------------------------------------------------------------------------*/
void sort(NodePointer L) {
    // 将单链表L的结点重排，使其递增有序
    NodePointer p = L->next, pre;
    NodePointer r = p->next;        // r保持p后继结点指针，以保证不断链
    p->next = nullptr;
    p = r;
    while (p) {
        r = p->next;                // 保存p的后继结点指针
        pre = L;
        while (pre->next && pre->data < p->data)
            pre = pre->next;        // 在有序表中查找插入p的前驱结点pre
        p->next = pre->next;        // 将p插入到pre之后
        pre->next = p;
        p = r;                      // 扫描原单链表中剩下的结点
    }
}


/*-------------------------------------------------------------------------
 7. 设在一个带头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除表中所有介于
 给定的两个值(作为函数参数给出)之间的元素。

 算法思想: 因为链表是无序的，所以只能逐个结点进行检查，执行删除
 ------------------------------------------------------------------------*/
void rangeDelete(NodePointer &L, int min, int max) {
    NodePointer pre = L, p = L->next;     // p是检测指针，pre是前驱
    while (p) {
        if (p->data > min && p->data < max) {   // 寻找到被删结点，删除
            pre->next = p->next;
            delete p;
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/*-------------------------------------------------------------------------
 8. 给定两个单链表，编写算法查找两个链表的公共结点。

 算法思想: 先分别遍历两个链表得到它们的长度，并求出两个长度之差。在长的链表上先遍历长度
 之差个结点之后，再同步遍历两个链表，直到找到相同的结点，或者一直到链表结束。
 ------------------------------------------------------------------------*/
NodePointer searchFirstCommonNode(LinkedList &L1, LinkedList &L2) {
    int len1 = L1.getLength(), len2 = L2.getLength(), dist;
    NodePointer longList, shortList;
    if (len1 >= len2) {
        longList = L1.head->next;
        shortList = L2.head->next;
        dist = len1 - len2;             // 表长之差
    } else
        return searchFirstCommonNode(L2, L1);

    while (dist--)
        longList = longList->next;

    while (longList) {
        if (longList == shortList)
            return longList;
        else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return nullptr;
}

/*-------------------------------------------------------------------------
 9. 给定一个带头结点的单链表，试写出算法: 按递增次序输出单链表中各结点的数据元素，
 并释放结点所占的存储空间(要求: 不允许使用数组作为辅助空间)。

 算法思想: 对链表进行遍历，在每次遍历中找出整个链表的最小值元素，输出并释放结点所占空间；
 再查找次小值元素，输出并释放空间，如此下去，直至链表为空，最后释放头结点所占存储空间。
 ------------------------------------------------------------------------*/
void minDelete(NodePointer &head) {
    NodePointer u;
    while (head->next) {
        NodePointer pre = head;
        NodePointer p = pre->next;
        while (p->next)
            if (p->next->data < pre->next->data) {
                pre = p;
                p = p->next;
            }
        cout << pre->next->data << " ";
        u = pre->next;
        pre->next = u->next;
        delete u;
    }
    delete head;
}

/*-------------------------------------------------------------------------
 10. 将一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表中序号为
 奇数的元素，而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。

 算法思想: 设置一个访问序号变量(初值为0)，每访问一个结点需要自动加1，然后根据序号的奇
 偶性将结点插入到A表或B表中。
 ------------------------------------------------------------------------*/
NodePointer separateTwoList(NodePointer &A) {
    int i = 0;          // i记录表A中结点的序号
    auto B = new Node(0);
    NodePointer ra = A, rb = B;    // ra和rb将分别指向将创建的A表和B表的尾结点

    NodePointer p = A->next;       // p为链表工作指针，指向待分解的结点
    A->next = nullptr;             // 置空新的A表
    while (p) {
        i++;
        if (i % 2 == 0) {
            rb->next = p;
            rb = p;
        } else {
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = nullptr;
    rb->next = nullptr;
    return B;
}

/*-------------------------------------------------------------------------
 11. 设C={a1, b1, a2, b2, ..., an, bn}为线性表，采用带头结点的单链表存放，设计一个
 就地算法，将其拆分为两个线性表，使得A={a1, a2, ..., an}，B={bn, ..., b2, b1}

 算法思想: 采用上题思路，不设序号变量。二者的差别仅在于对B表的建立不采用尾插法而是头插法。
 ------------------------------------------------------------------------*/
NodePointer separateTwoList2(NodePointer &A) {
    auto B = new Node(0);
    NodePointer p = A->next, q;     // p为工作指针
    NodePointer ra = A;             // ra始终指向A的尾结点
    while (p != nullptr) {
        ra->next = p;               // 将p链到A的表尾
        ra = p;
        p = p->next;
        if (p != nullptr) q = p->next;      // 头插后，p将断链，因此用q记忆p的后继
        p->next = B->next;          // 将p插入到B的前端
        B->next = p;
        p = q;
    }
    ra->next = nullptr;             // A尾结点的next域置空
    return B;
}

/*-------------------------------------------------------------------------
 12. 在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，设计算法去掉
 数值相同的元素，使表中不再有重复的元素。

 算法思想: 由于是有序表，所有相同值域的结点都是相邻的。用p扫描递增单链表L，若p结点的值
 域等于其后继结点的值域，则删除后者，否则p移向下一结点。
 ------------------------------------------------------------------------*/
void deleteSameNode(NodePointer &L) {
    NodePointer p = L->next, q;     // p为扫描工作指针
    if (p == nullptr)
        return;
    while (p->next != nullptr) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            delete q;
        } else
            p = p->next;
    }
}

/*-------------------------------------------------------------------------
 13. 假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。请编写算法将这两个单链表
 归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点存放归并后的单链表。

 算法思想: 两个链表已经按元素值递增次序排序，将其合并时，均从第一个结点起进行比较，将小的
 结点链入链表中，同时后移工作指针。该问题要求结果链表按元素值递减次序排列，故新链表的建立
 应该采用头插法。比较结束后，可能会有一个链表非空，此时用头插法将剩下的结点依次插入新链表
 中即可。
 ------------------------------------------------------------------------*/
void mergeLists(NodePointer &La, NodePointer &Lb) {
    NodePointer r, pa = La->next, pb = Lb->next;
    La->next = nullptr;

    while (pa && pb) {
        if (pa->data <= pb->data) {
            r = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = r;
        } else {
            r = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = r;
        }
    }

    if (pa)
        pb = pa;
    while (pb) {
        r = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = r;
    }
    delete Lb;
}

/*-------------------------------------------------------------------------
 14. 设A和B是两个单链表(带头结点)，其中元素递增有序。设计一个算法从A和B中的公共元素产生
 单链表C，要求不破坏A、B的结点。

 算法思想: 表A、B都有序，可从第一个元素起依次比较A、B两表的元素，若元素值不等，则值小的
 指针往后移，若元素值相等，则创建一个值等于两结点的元素值的新结点，使用尾插法插入到新的链
 表中，并将两个原表指针后移一位，直到其中一个链表遍历到表尾。
 ------------------------------------------------------------------------*/
void getCommon(NodePointer A, NodePointer B) {
    NodePointer p = A->next, q = B->next;
    auto C = new Node(0);
    NodePointer r = C;
    while (p != nullptr && q != nullptr) {
        if (p->data < q->data)
            p = p->next;
        else if (p->data > q->data)
            q = q->next;
        else {
            auto s = new Node(p->data);
            r->next = s;                // 将s链接到C上(尾插法)
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = nullptr;          // 置C尾结点指针为空
}

/*-------------------------------------------------------------------------
 15. 已知两个链表A和B分别表示两个集合，其元素递增排列。编制函数，求A与B的交集，并存放于
 A链表中。

 算法思想: 采用归并的思想，设置两个工作指针pa和pb，对两个链表进行归并扫描，只有同时出现
 在两集合中的元素才链接到结果表中且仅保留一个，其他的结点全部释放。当一个链表遍历完毕后，
 释放另一个表中剩下的全部结点。
 ------------------------------------------------------------------------*/
NodePointer unionTwoList(NodePointer &la, NodePointer &lb) {
    NodePointer pa = la->next;
    NodePointer pb = lb->next;
    NodePointer pc = la;
    NodePointer u;
    while (pa && pb) {
        if (pa->data == pb->data) {  // 交集并入结果表中
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;     // B中结点释放
            pb = pb->next;
            delete u;
        } else if (pa->data < pb->data) {       // 若A中当前结点值小于B中当前结点值
            u = pa;
            pa = pa->next;
            delete u;
        } else {
            u = pb;
            pb = pb->next;
            delete u;
        }
    }

    // 退出上的循环时，还有残留结点
    if (pb)
        pa = pb;
    while (pa) {
        u = pa;
        pa = pa->next;
        delete u;
    }
    pc->next = nullptr;
    delete lb;
    return la;
}

/*-------------------------------------------------------------------------
 16. 两个整数序列A=a1, a2, ..., am和B=b1, b2, ..., bn已经存入两个单链表中，设计一
 个算法，判断序列B是否是序列A的连续子序列。

 算法思想: 因为两个整数序列已经存入两个链表中，操作从两个链表的第一个结点开始，若对应数据
 相等，则后移指针；若对应数据不相等，则A链表从上次开始比较的后继开始，B链表仍从第一个结点
 开始比较，直到B链表到尾表示匹配成功。A链表到尾而B链表未到尾表示失败。操作中应记A链表每次
 的开始结点，以便下次匹配时好从其后继开始。
 ------------------------------------------------------------------------*/
bool pattern(NodePointer A, NodePointer B) {
    NodePointer p = A;          // p为A链表的工作指针，假定A和B均无头结点
    NodePointer pre = p;        // pre记住每趟比较A链表的开始结点
    NodePointer q = B;          // q是B链表的工作指针
    while (p && q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;            // A链表新的开始比较结点
            q = B;              // q从B链表第一个结点开始
        }
    }
    return q == nullptr;        // B链表到尾，匹配成功
}

/*-------------------------------------------------------------------------
 21. 给定带头结点的单链表L，在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表
 中倒数第k个位置上的节点(k为正整数)。若查找成功，算法输出该结点的data域的值，并返回1；
 否则只返回0。

 算法思想:
 1) 算法的基本设计思想如下:
    问题的关键是设计一个尽可能高效的算法，通过链表的一次遍历，找到倒数第k个结点的位置。
 算法的基本设计思想是: 定义两个指针变量p和q，初始时均指向头结点的下一个结点(链表的第一
 个结点)，p指针沿链表移动; 当p指针移动到第k个结点时，q指针开始与p指针同步移动; 当p指针
 移动到最后一个结点时，q指针所指示结点为倒数第k个结点。
 2) 算法的详细实现步骤如下:
 ① count=0，p和q指向链表表头结点的下一个结点。
 ② 若p为空，转⑤。
 ③ 若count等于k，则q指向下一个结点；否则，count=count+1。
 ④ p指向下一个结点，转②
 ⑤ 若count等于k，则查找成功，输出该结点的data域的值，返回1；否则，说明k值超过了线性表
 的长度，查找失败，返回0。
 ⑥ 算法结束。
 3) 实现
 ------------------------------------------------------------------------*/
int searchKthNodeFromRear(NodePointer list, int k) {
    NodePointer p = list->next, q = list->next;
    int count = 0;
    while (p) {
        if (count < k) count++;
        else q = q->next;
        p = p->next;
    }
    if (count < k)
        return 0;
    else {
        cout << q->data << " ";
        return 1;
    }
}

/*-------------------------------------------------------------------------
 22. 假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，可共享相同的后缀存储空
 间，例如，"loading"和"being"的存储映像如下图所示
 str1 -> l -> o -> a -> d
                           \
                             i -> n -> g -> nullptr
 str2 -> b -> e            /
 设str1和str2分别指向两个单词所在单链表的头结点，请设计一个时间上尽可能高效的算法，找出
 由str1和str2所指向两个链表共同后缀的起始位置(如同中字符i所在结点的位置p)。

 算法思想: 用指针p、q分别扫描str1和str2，当p、q指向同一个地址时，即找到共同后缀的起始
 位置。
 1) 算法的基本设计思想如下:
 ① 分别求出str1和str2所指的两个链表的长度m和n。
 ② 将两个链表以表尾对齐: 令指针p、q分别指向str1和str2的头结点，若m>=n，则指针p先走，
 使p指向链表中的第m-n+1个结点；若m<n，则使q指向链表中的第n-m+1个结点，即使指针p和q所
 指的结点到表尾的长度相等。
 ③ 反复将指针p和q同步向后移动，当p、q指向同一位置时停止，即为共同后缀的起始位置，算法结束。
 ------------------------------------------------------------------------*/
int listLen(NodePointer head) {
    int len = 0;
    while (head->next) {
        len++;
        head = head->next;
    }
    return len;
}

NodePointer findAddress(NodePointer str1, NodePointer str2) {
    int m, n;
    NodePointer p, q;
    m = listLen(str1);
    n = listLen(str2);
    for (p = str1; m > n; m--)
        p = p->next;
    for (q = str2; m < n; n--)
        q = q->next;
    while (p->next && p->next != q->next) {     // 将指针p和q同步后移
        p = p->next;
        q = q->next;
    }
    return p->next;     // 返回共同后缀的起始地址
}

/*-------------------------------------------------------------------------
 23. 用单链表保存m个整数，且|data|<=n(n为正整数)。现要求设计一个时间复杂度尽可能高效的
 算法，对于链表中data的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。

 算法思想:
 1) 算法的基本设计思想
    算法的核心思想是用空间换时间。使用辅助数组记录链表中已出现的数值，从而只需对链表进行
 一趟扫描。
    因为|data|<=n，故辅助数组q的大小为n+1，各元素的初值均为0。依次扫描链表中的各结点，
 同时检查q[|data|]的值，若为0则保留该结点，并令q[|data|]=1；否则将该点从链表中删除。
 ------------------------------------------------------------------------*/
void func(NodePointer h, int n) {
    NodePointer p = h, r;
    int q[n + 1], m;
    for (int i = 0; i < n + 1; i++)
        q[i] = 0;
    while (p->next) {
        m = p->next->data > 0 ? p->next->data : -p->next->data;
        if (q[m] == 0) {
            q[m] = 1;       // 首次出现
            p = p->next;    // 保留
        } else {
            r = p->next;
            p->next = r->next;
            delete r;
        }
    }
}

/*-------------------------------------------------------------------------
 24. 设计一个算法完成以下功能: 判断一个链表是否有环，如果有，找出环的入口点并返回，否则
 返回nullptr。

 算法思想:
 1) 算法的基本思想
    设置快慢两个指针为别为fast和slow，初始时都指向链表头head。slow每次都走一步，fast
 每次走两步。由于fast比slow走得快，如果有环，那么fast一定会先进入环，而slow后进入环。当
 两个指针都进入环后，经过若干操作后两个指针定能在环上相遇。
    设头结点到环入口点的距离为a，环的入口点沿着环的方向到相遇点的距离为x，环长为r，相遇
 时fast绕过了n圈。则，慢针走过的距离为a+x，因为快针的速度是慢针的2倍，所以，快针走过了
 2(a+x)，又从环内的角度看，快针走过了非环部分距离为a，n圈距离n*r，相遇点x
 => 快针走了 a + n*r + x
 故 2(a+x) = a + n*r + x => a = n*r - x
 显然从头节点到环入口点的距离等于n倍的环长减去环的入口点到相遇点的距离。因此可设置两个指针，
 一个指向head，一个指向相遇点，两个指针同步移动，相遇点即为环的入口点。
 ------------------------------------------------------------------------*/
NodePointer findLoopStart(NodePointer head) {
    NodePointer fast = head, slow = head;   // 设置快慢针
    while (slow && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;    // 相遇
    }
    if (slow == nullptr || fast->next == nullptr) return nullptr;   // 没有环
    NodePointer p1 = head, p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;      // 找到了入口点
}

/*-------------------------------------------------------------------------
 25. 设线性表L=(a1, a2, ..., an)采用带头结点的单链表保存，请设计一个空间复杂度为O(1)
 且时间上尽可能高效的算法，重新排列L中的各结点，得到线性表L'=(a1, an, a2, a_n-1, ...)。

 算法思想:
 1) 算法的基本设计思想
 ① 先找出链表L的中间结点，为此设置两个指针p和q，指针p每次走一步，指针q每次走两步，当指针
 q到达链尾，指针p正好链尾，指针p正好在链表的中间结点；
 ② 然后将L的后半段结点原地逆置。
 ③ 从单链表前后两段中依次各取一个结点，按要求重排。
 2) 算法实现:
 ------------------------------------------------------------------------*/
void changeList(NodePointer h) {
    NodePointer p, q, r, s;
    p = q = h;
    while (q->next != nullptr && q->next->next != nullptr) {    // 寻找中间结点
        p = p->next;
        q = q->next->next;
    }
    q = p->next;        // p所指结点为中间结点，q为后半段链表的首结点
    p->next = nullptr;
    while (q != nullptr) {      // 将链表后半段逆置，把q头插到 p与 p->next 之间
        r = q->next;            // 防断链
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = h;            // s指向前半段的第一个数据结点，即插入点
    q = p->next;            // q指向后半段的第一个数据点
    p->next = nullptr;
    while (q != nullptr) {   // 将链表后半段的结点插入到指定位置
        r = q->next;         // r指向后半段的下一个结点
        q->next = s->next;   // 将q所指结点插入到s所指结点之后
        s->next = q;
        s = q->next;         // s指向前半段的下一个插入结点
        q = r;
    }
}
/*-------------------------------------------------------------------------
 3) 第1步找中间结点的时间复杂度为O(n)，第2步逆置的时间复杂度为O(n)，第3步合并链表的时间
 复杂度为O(n)，所以该算法的时间复杂度为O(n)。
 ------------------------------------------------------------------------*/