#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> q;
    q.push(3);
    q.push(4);
    q.push(1);

    printf("%d\n", q.top());  // 4
    return 0;
}