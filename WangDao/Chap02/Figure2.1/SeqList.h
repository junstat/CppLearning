#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H

const int MaxSize = 50;
typedef int ElementType;

class SeqList {
public:
    SeqList();

    bool empty() const;

    void insert(ElementType item, int pos);

    void erase(int pos);

    void display(ostream &out) const;

    // ------------------------------- 王道综合应用题 -------------------------------
    bool deleteMin(ElementType &value);

    void reverse();

    void reverse2();

    void deleteX(ElementType x);
private:
    ElementType data[MaxSize]{};
    int length;
};

ostream &operator<<(ostream &out, const SeqList &list);

#endif //DATASTRUCTURE_SEQLIST_H
