#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#ifndef DATASTRUCTURE_BINTREE_H
#define DATASTRUCTURE_BINTREE_H

typedef int ElementType;

class BiTNode {
    ElementType data;
    BiTNode *lchild, *rchild;

    BiTNode()
            : lchild(nullptr), rchild(nullptr) {}

    BiTNode(ElementType item)
            : data(item), lchild(nullptr), rchild(nullptr) {}

};

typedef BiTNode *BiTNodePointer;

template<typename DataType>
class BinTree {
public:
    BinTree();

    void preOrder(ostream &out) const;

    void inOrder(ostream &out) const;

    void postOrder(ostream &out) const;

    void preOrderNoRec(ostream &out) const;

    void inOrderNoRec(ostream &out) const;

    void postOrderNoRec(ostream &out) const;

    void levelOrder(ostream &out) const;

private:
    BiTNodePointer root;

    void preOrderAux(ostream &out, BiTNodePointer subTreePtr) const;

    void inOrderAux(ostream &out, BiTNodePointer subTreePtr) const;

    void postOrderAux(ostream &out, BiTNodePointer subTreePtr) const;
};

template<typename DataType>
inline BinTree<DataType>::BinTree()
        :root(nullptr) {}

template<typename DataType>
inline void BinTree<DataType>::preOrder(ostream &out) const {
    preOrderAux(out, root);
}

template<typename DataType>
inline void BinTree<DataType>::inOrder(ostream &out) const {
    inOrderAux(out, root);
}

template<typename DataType>
inline void BinTree<DataType>::postOrder(ostream &out) const {
    postOrderAux(out, root);
}

template<typename DataType>
void BinTree<DataType>::preOrderAux(ostream &out,
                                    BiTNodePointer subTreePtr) const {
    if (subTreePtr) {
        out << subTreePtr->data << " ";
        preOrderAux(out, subTreePtr->lchild);
        preOrderAux(out, subTreePtr->rchild);
    }
}

template<typename DataType>
void BinTree<DataType>::inOrderAux(ostream &out,
                                   BiTNodePointer subTreePtr) const {
    if (subTreePtr) {
        inorderAux(out, subTreePtr->lchild);
        out << subTreePtr->data << " ";
        inorderAux(out, subTreePtr->rchild);
    }
}

template<typename DataType>
void BinTree<DataType>::postOrderAux(ostream &out,
                                     BiTNodePointer subTreePtr) const {
    if (subTreePtr) {
        postOrderAux(out, subTreePtr->lchild);
        postOrderAux(out, subTreePtr->rchild);
        out << subTreePtr->data << " ";
    }
}

template<typename DataType>
void BinTree<DataType>::preOrderNoRec(ostream &out) const {
    BiTNodePointer p = root;
    stack<BiTNodePointer> st;
    while (p || !st.emmpty()) {
        if (p) {
            out << p->data << " ";
            st.push(p);
            p = p->lchild;
        } else {
            p = st.top(), st.pop();
            p = p->rchild;
        }
    }
}

template<typename DataType>
void BinTree<DataType>::inOrderNoRec(ostream &out) const {
    BiTNodePointer p = root;
    stack<BiTNodePointer> st;
    while (p || !st.empty()) {
        if (p) {
            st.push(p);
            p = p->lchild;
        } else {
            p = st.top(), st.pop();
            out << p->data << " ";
            p = p->rchild;
        }
    }
}

template<typename DataType>
void BinTree<DataType>::postOrderNoRec(ostream &out) const {
    BiTNodePointer p = root, r = nullptr;
    stack<BiTNodePointer> st;
    while (p || !st.empty()) {
        if (p) {
            st.push(p);
            p = p->lchild;
        } else {
            p = st.top();
            if (p->rchild && p->rchild != r)
                p = p->rchild;
            else {
                p = st.top(), st.pop();
                out << p->data << " ";
                r = p;
                p = nullptr;
            }
        }
    }
}

template<typename DataType>
void BinTree<DataType>::levelOrder(ostream &out) const {
    queue<BiTNodePointer> q;
    BiTNodePointer p;
    q.push(root)
    while (!q.empty()) {
        p = q.top(), q.pop();
        out << p->data << " ";
        if (p->lchild)
            q.push(p->lchild);
        if (p->rchild)
            q.push(p->rchild);
    }
}

#endif //DATASTRUCTURE_BINTREE_H
