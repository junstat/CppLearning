#include <cassert>
#include "SeqList.h"

SeqList::SeqList() : length(0) {}

bool SeqList::empty() const {
    return length == 0;
}

void SeqList::display(ostream &out) const {
    for (int i = 0; i < length; i++)
        out << data[i] << "  ";
}

ostream &operator<<(ostream &out, const SeqList &list) {
    list.display(out);
    return out;
}

void SeqList::insert(ElementType item, int pos) {
    if (length == MaxSize) {
        cerr << "*** No space for list element -- terminating "
                " execution ***" << endl;
        exit(1);
    }
    if (pos < 0 || pos > MaxSize) {
        cerr << "*** Illegal location to insert -- " << pos
             << ". List unchanged. ***\n";
        return;
    }
    // First shift array elements right to make room for item
    for (int i = length; i > pos; i--)
        data[i] = data[i - 1];

    // Now insert item at position pos and increase list size
    data[pos] = item;
    length++;
}

void SeqList::erase(int pos) {
    if (length == 0) {
        cerr << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= length) {
        cerr << "Illegal location to delete -- " << pos
             << ". List unchanged. ***\n";
        return;
    }

    // Shift array elements left to close the gap
    for (int i = pos; i < length; i++)
        data[i] = data[i + 1];

    // Decrease list size
    length--;
}

// ------------------------------- 王道综合应用题 -------------------------------

/*-------------------------------------------------------------------------
1. 从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位置
 由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。

算法思想: 搜索整个顺序表，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的
原最小值元素的位置。
 ------------------------------------------------------------------------*/
bool SeqList::deleteMin(ElementType &value) {
    // 删除顺序表中最小值元素结点，并通过引用型参数value返回其值
    // 若删除成功，则返回true；否则返回false
    if (length == 0)
        return false;
    value = data[0];
    int pos = 0;
    for (int i = 1; i < length; i++)
        if (data[i] < value) {
            value = data[i];
            pos = i;
        }
    data[pos] = data[length - 1];
    length--;
    return true;
}

/*-------------------------------------------------------------------------
2. 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)。

算法思想: 扫描顺序表的前半部分元素，对于元素data[i] (0 <= i <= length / 2)，将其与
后半部分的对应元素data[length - i - 1]进行交换。
------------------------------------------------------------------------*/
void SeqList::reverse() {
    ElementType temp;
    for (int i = 0; i < length / 2; i++) {
        temp = data[i];
        data[i] = data[length - i - 1];
        data[length - i - 1] = temp;
    }
}

void SeqList::reverse2() {
    ElementType temp;
    for (int start = 0, end = length - 1; start < end; start++, end--) {
        temp = data[start];
        data[start] = data[end];
        data[end] = temp;
    }
}

/*-------------------------------------------------------------------------
3. 对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除
线性表中所有值为x的数据元素。

算法思想: 用k记录顺序表L中不等于x的元素的个数(即需要保存的元素个数)，边扫描L边统计k,
并将不等于x的元素向前移动k个位置，最后修改L的长度。
------------------------------------------------------------------------*/
void SeqList::deleteX(ElementType x) {
    // 删除顺序表中所有值为x的元素
    int k = 0;          // 记录值不等于x的元素个数
    for (int i = 0; i < length; i++)
        if (data[i] != x)
            data[k++] = data[i];
    length = k;
}






