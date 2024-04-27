#include "print.h"

using namespace std;

//list容器插入和删除

/*
- push_back(elem);//在容器尾部加入一个元素
- pop_back();//删除容器中最后一个元素
- push_front(elem);//在容器开头插入一个元素
- pop_front();//从容器开头移除第一个元素
- insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
- insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
- insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
- clear();//移除容器的所有数据
- erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
- erase(pos);//删除pos位置的数据，返回下一个数据的位置。
- remove(elem);//删除容器中所有与elem值匹配的元素。
*/

void test1() {
    list<int> l1;
    // 尾插
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    // 头插
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);

    printList(l1);

    // 尾删
    l1.pop_back();
    printList(l1);

    // 头删
    l1.pop_front();
    printList(l1);

    // insert插入
    auto it = l1.begin();
    l1.insert(++it, 1000);
    printList(l1);

    // 删除
    it = l1.begin();
    l1.erase(++it);
    printList(l1);

    // 移除
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    l1.push_back(10000);
    printList(l1);

    l1.remove(10000);
    printList(l1);

    // 清空
    l1.clear();

}

int main() {
    int arr[] = {2, 34, 12, 212, 15};
    printf("len(arr) = %llu\n", sizeof(arr) / sizeof(arr[0]));
    return 0;
}