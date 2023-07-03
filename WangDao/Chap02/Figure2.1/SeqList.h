#include <iostream>

using namespace std;

#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H

#define MaxSize 50
#define InitSize 100
typedef int ElementType;

typedef struct {
    ElementType data[MaxSize];
    int length;
} SqList;

typedef struct {
    ElementType *data;
    int capacity, length;
} SeqList;

bool ListInsert(SqList &L, int i, ElementType e);

bool ListDelete(SeqList &L, int i, ElementType &e);

int LocateElem(SqList L, ElementType e);

/* --------  应用题 ------------- */
bool Del_Min(SqList &L, ElementType &value);

void Reverse(SqList &L);

void Reverse2(SqList &L);


#endif //DATASTRUCTURE_SEQLIST_H
