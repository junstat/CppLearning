#include <cassert>
#include "SeqList.h"

bool ListInsert(SqList &L, int i, ElementType e) {
    if (i < 1 || i > L.length + 1) // 判断i的范围是否有效
        return false;
    if (L.length >= MaxSize) // 当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;  // 在位置i处放入e
    L.length++;  // 线性表长度加1
    return true;
}

bool ListDelete(SeqList &L, int i, ElementType &e) {
    if (i < 1 || i > L.length)  // 判断i的范围是否有效
        return false;
    e = L.data[i - 1];  // 将删除的元素赋值给e
    for (int j = i; j < L.length; j++)  // 将第i个位置后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--;  // 线性表长度减1
    return true;
}

int LocateElem(SqList L, ElementType e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;  // 下标为i的元素值等于e，返回其位序i+1
    return 0; // 退出循环，说明查找失败
}

// ------------------------------- 王道综合应用题 -------------------------------

/*-------------------------------------------------------------------------
1. 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置
 由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。

算法思想: 搜索整个顺序表，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的
原最小值元素的位置。
 ------------------------------------------------------------------------*/
bool Del_Min(SqList &L, ElementType &value) {
    // 删除顺序表中最小值元素结点，并通过引用型参数value返回其值
    // 若删除成功，则返回true；否则返回false
    if (L.length == 0)
        return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++)
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

/*-------------------------------------------------------------------------
2. 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)。

算法思想: 扫描顺序表的前半部分元素，对于元素data[i] (0 <= i <= length / 2)，将其与
后半部分的对应元素data[length - i - 1]进行交换。
------------------------------------------------------------------------*/
void Reverse(SqList &L) {
    ElementType temp;
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

void Reverse2(SqList &L) {
    ElementType temp;
    for (int start = 0, end = L.length - 1; start < end; start++, end--) {
        temp = L.data[start];
        L.data[start] = L.data[end];
        L.data[end] = temp;
    }
}

/*-------------------------------------------------------------------------
3. 对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除
线性表中所有值为x的数据元素。

算法思想:
解法一: 用k记录顺序表L中不等于x的元素的个数(即需要保存的元素个数)，边扫描L边统计k,
并将不等于x的元素向前移动k个位置，最后修改L的长度。
------------------------------------------------------------------------*/
void del_x_1(SqList &L, ElementType x) {
    // 删除顺序表中所有值为x的元素
    int k = 0;          // 记录值不等于x的元素个数
    for (int i = 0; i < L.length; i++)
        if (L.data[i] != x)
            L.data[k++] = L.data[i];
    L.length = k;
}

/*-------------------------------------------------------------------------
解法二: 用k记录顺序表L中等于x的元素个数，边扫描L边统计k，

------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
4. 从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素，若s或t不合理或顺序表为空，
 则显示出错信息并退出运行。

算法思想:
------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
5. 从顺序表中删除其值在给定值s与t之间(包含s和t，要求s<t)的所有元素，若s或t不合理或
 顺序表为空，则显示出错信息并退出运行。

算法思想:
------------------------------------------------------------------------*/


