#include <cassert>
#include <new>
#include "DSeqList.h"

SeqList::SeqList(int maxSize)
        : length(0), MaxSize(maxSize) {
    data = new(nothrow) ElementType[MaxSize];
    assert(data != nullptr);
}

SeqList::~SeqList() {
    delete[] data;
}

SeqList::SeqList(const SeqList &origList)
        : length(origList.length), MaxSize(origList.MaxSize) {
    data = new(nothrow) ElementType[MaxSize];
    if (data != nullptr)
        for (int i = 0; i < length; i++)
            data[i] = origList.data[i];
    else {
        cerr << "*** Inadequate memory to allocate for list ***\n";
        exit(1);
    }
}

const SeqList &SeqList::operator=(const SeqList &rightHandSide) {
    if (this != &rightHandSide) {
        if (MaxSize != rightHandSide.MaxSize) {
            delete[] data;
            MaxSize = rightHandSide.MaxSize;
            data = new(nothrow) ElementType(MaxSize);
            if (data == nullptr) {
                cerr << "*Inadequate memory to allocate stack ***\n";
                exit(1);
            }
        }

        length = rightHandSide.length;
        for (int i = 0; i < length; i++)
            data[i] = rightHandSide.data[i];
    }
    return *this;
}

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
                "execution ***\n";
        exit(1);
    }
    if (pos < 0 || pos > MaxSize) {
        cerr << "*** Illegal location to insert -- " << pos
             << ". List unchanged. ***\n";
        return;
    }

    for (int i = length; i > pos; i--)
        data[i] = data[i - 1];

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

    for (int i = pos; i < length; i++)
        data[i] = data[i + 1];
    length--;
}