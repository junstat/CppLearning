#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_DSEQLIST_H
#define DATASTRUCTURE_DSEQLIST_H

typedef int ElementType;

class SeqList {
public:
    SeqList(int maxsize = 1024);

    ~SeqList();

    SeqList(const SeqList &origList);

    const SeqList &operator=(const SeqList &rightHandSide);

    bool empty() const;

    void insert(ElementType item, int pos);

    void erase(int pos);

    void display(ostream &out) const;

private:
    int length;
    int MaxSize;
    ElementType *data;
};

ostream &operator<<(ostream &out, const SeqList &list);

#endif //DATASTRUCTURE_DSEQLIST_H
