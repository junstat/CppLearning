#include <iostream>
#include <queue>

using namespace std;

// 1> 对于基本类型而言，优先队列对它们的优先级设置一般是数字越大优先级越高
// 因此队首元素就是优先队列内元素最大的那个
// 对于基本数据类型来说，下面两种有限队列的定义是等价的
// priority_queue<int> q;
// priority_queue<int, vector<int>, less<int> > q;
// less<int> 表示数字大的优先级越大，而greater<int> 表示数字小的优先级越大

// 2> 结构体的优先级设置
// 水果结构体
struct Fruit {
    string name;
    int price;

    // 现在希望按水果价格高的为优先级高，需要重载 <
    bool operator<(const Fruit &other) const {
        return price < other.price;
    }
};

// 优先队列重载<函数与sort函数的效果是相反的

int main() {
    priority_queue<Fruit> q;
    Fruit apple{"apple", 1},
            banana{"banana", 3},
            peach{"peach", 2};

    q.push(apple);
    q.push(banana);
    q.push(peach);

    while (!q.empty()) {
        cout << q.top().name << " " << q.top().price << endl;
        q.pop();
    }

    return 0;
}