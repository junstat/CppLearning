#include "../Figure3.1/Stack.h"
#include "../Figure3.3/Queue.h"
// ------------------------------- 王道综合应用题 -------------------------------

/*-------------------------------------------------------------------------
 1. 若希望循环队列中的元素都能得到利用，则需设置一个标志域tag，并以tag的值为0或1来区分
 头指针front和队尾指针rear相同时的队列状态是"空"还是"满"。试编写与此结构相应的入队和出
 队算法。

 算法思想:
 在循环队列的类型结构中，增设一个tag的整型变量，进队时置tag为1，出队时置tag为0(因为只有
 入队操作可能导致队满，也只有出队操作可能导致队空)。队列Q初始时，置tag=0、front=rear=0
 这样队列的4要素如下:
 队空条件: Q.front==Q.rear 且 Q.tag == 0。
 队满条件: Q.front==Q.rear 且 Q.tag == 1。
 进队操作: Q.data[Q.rear] = x; Q.rear = (Q.rear + 1) % maxsize; Q.tag = 1;
 出队操作: x = Q.data[Q.front]; Q.front = (Q.front + 1) % maxsize; Q.tag = 0。
 ------------------------------------------------------------------------*/
class SqQueue {
private:
    typedef int QueueElement;
//    const static int MaxSize = 128;
    int front, rear, tag;
    QueueElement data[MaxSize];

public:
    int EnQueue(QueueElement x) {
        if (front == rear && tag == 1) return 0;    // 队满
        data[rear] = x;
        rear = (rear + 1) % MaxSize;
        tag = 1;            // 可能队满
        return 1;
    }

    int DeQueue(QueueElement &x) {
        if (front == rear && tag == 0) return 0;    //队空
        x = data[front];
        front = (front + 1) % MaxSize;
        tag = 0;            // 可能队空
        return 1;
    }
};

/*-------------------------------------------------------------------------
 2. Q是一个队列，S是一个空栈，实现将队列中的元素逆置的算法。

 算法思想:
 逐个出队，全部入栈，逐个出栈，入队。
 ------------------------------------------------------------------------*/
void reverse(Stack S, Queue Q) {
    int x;
    while (Q.empty()) {
        x = Q.getFront();
        Q.dequeue();
        S.push(x);
    }
    while (!S.empty()) {
        x = S.getTop();
        S.pop();
    }
}

/*-------------------------------------------------------------------------
 3. 利用两个栈S1，S2来模拟一个队列，已知栈的4个运算定义如下:
 Push(S, x);        // 元素X入栈S
 Pop(S, x);         // S出栈并将出栈的值赋给x
 StackEmpty(S);     // 判断栈是否为空
 StackOverflow(S);  // 判断栈是否满
 如何利用栈的运算来实现该队列的3个运算?
 Enqueue;       // 将元素x入队
 Dequeue;       // 出队，并将出队元素存储在x中
 QueueEmpty;    // 判断队列是否为空

 算法思想:
 1) 对S2的出栈操作用做出队，若S2为空，则先将S1中的所有元素送入S2。
 2) 对S1的入栈操作用作入队，若S1满，必须先保证S2为空，才能将S1中的元素全部插入S2中。
 LeetCode 232
 ------------------------------------------------------------------------*/
typedef int ElementType;
typedef struct SeqStack {
    ElementType data[50];
    int top;
} SeqStack;

void Push(SeqStack S, ElementType x);

void Pop(SeqStack S, ElementType &x);

bool StackEmpty(SeqStack S);

bool StackOverflow(SeqStack S);

int EnQueue(SeqStack &S1, SeqStack &S2, ElementType e) {
    if (!StackOverflow(S1)) {
        Push(S1, e);
        return 1;
    }

    if (StackOverflow(S1) && !StackEmpty(S2)) {
        printf("队列满");
        return 0;
    }

    if (StackOverflow(S1) && StackEmpty(S2)) {
        ElementType x;
        while (!StackEmpty(S1)) {
            Pop(S1, x);
            Push(S2, x);
        }
    }
    Push(S1, e);
    return 1;
}

void DeQueue(SeqStack &S1, SeqStack &S2, ElementType &x) {
    if (!StackEmpty(S2)) Pop(S2, x);
    else if (StackEmpty(S1)) printf("对列为空");
    else {
        ElementType e;
        while (!StackEmpty(S1)) {
            Pop(S1, e);
            Push(S2, e);
        }
        Pop(S2, x);
    }
}

/*-------------------------------------------------------------------------
 4. 利用两个队列来模拟一个栈。
 LeetCode 225
 ------------------------------------------------------------------------*/
#include <queue>
class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while (!q2.empty())
                q1.push(q2.front()), q2.pop();
        } else {
            q2.push(x);
            while (!q1.empty())
                q2.push(q1.front()), q1.pop();
        }
    }

    int pop() {
        int res;
        if (!q1.empty())
            res = q1.front(), q1.pop();
        else
            res = q2.front(), q2.pop();
        return res;
    }

    int top() {
        return !q1.empty() ? q1.front() : q2.front();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};


/*-------------------------------------------------------------------------
 5. 请设计一个队列，要求满足: ① 初始时队列为空; ② 入队时，允许增加队列占用空间; ③ 出
 队后，出队元素所占用的空间可重复使用，即整个队列所占用的空间只增不减; ④ 入队操作和出队
 操作的时间复杂度始终保持为O(1)。请回答下列问题:
 1) 该队列是应选择链式存储结构，还是应选择顺序存储结构?
 2) 画出队列的初始状态，并给出判断队空和队满的条件。
 3) 画出第一个元素入队后的队列状态。
 4) 给出入队操作和出队操作的基本过程。

 解答:
 1) 顺序存储无法满足要求②的队列占用空间随着入队操作而增加。根据要求来分析: 要求①容易满足；
 链式存储方便开辟新空间，要求②容易满足；对于要求③，出队后的结点并不是真的释放，用队头指针
 指向新的队头结点，新元素入队时，有空余结点则无须开辟新空间，赋值到队尾后的第一个空结点即可
 然后用队尾指向新的队尾结点，这就需要设计成一个首尾相接的循环单链表，类似于循环队列的思想。
 设置队头、队尾指针后，链式存储结构(两段式单向循环链表)，队头指针为front，队尾指针为rear。
 2) 该循环链式队列的实现可以参考循环队列，不同之处在于循环链式队列可以方便地增加空间，出队
 的节点可以循环利用，入队时空间不够也可以动态增加。同样，循环链式队列也要区分队满和队空的情
 况，这里参考循环队列牺牲一个单元来判断。初始时，创建只有一个空闲结点的循环单链表，头指针
 front和尾指针rear均指向空闲结点。
 队空的判定条件: front == rear。
 队满的判定条件: front == rear->next;
 3) 插入第一个元素后的状态:

 4) 操作的基本过程如下
    入队操作：
     若(front == rear -> next)   // 队满
       则在rear后插入一个新的空闲结点
     入队元素保存到 read所指结点中; rear = rear -> next；返回

    出队操作:
       若(front == rear)     // 队空
          则出队失败，返回;
       取front所指结点中的元素e; front = front->next; 返回e。
 ------------------------------------------------------------------------*/