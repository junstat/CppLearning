#include <iostream>

using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template<typename DataType>
class BST {
public:

    BST();

    bool empty() const;

    bool search(const DataType &item) const;

    void insert(const DataType &item);

    void remove(const DataType &item);

    void inorder(ostream &out) const;

    void graph(ostream &out) const;

private:
    class BinNode {
    public:
        DataType data;
        BinNode *left, *right;

        BinNode()
                : left(nullptr), right(nullptr) {}

        BinNode(DataType item)
                : data(item), left(nullptr), right(nullptr) {}
    };

    typedef BinNode *BinNodePointer;

    void search2(const DataType &item, bool &found, BinNodePointer &locptr, BinNodePointer &parent) const;

    void inorderAux(ostream &out, BST<DataType>::BinNodePointer subtreePtr) const;

    void graphAux(ostream &out, int indent, BST<DataType>::BinNodePointer subtreeRoot) const;

    BinNodePointer myRoot;
};

template<typename DataType>
inline BST<DataType>::BST()
        : myRoot(nullptr) {}

template<typename DataType>
inline bool BST<DataType>::empty() const {
    return myRoot == 0;
}

template<typename DataType>
bool BST<DataType>::search(const DataType &item) const {
    BST<DataType>::BinNodePointer locptr = myRoot;
    bool found = false;
    while (!found && locptr != nullptr) {
        if (item < locptr->data)        // descend left
            locptr = locptr->left;
        else if (locptr->data < item)
            locptr = locptr->right;
        else
            found = true;
    }
    return found;
}

template<typename DataType>
inline void BST<DataType>::insert(const DataType &item) {
    BST<DataType>::BinNodePointer locptr = myRoot, parent = nullptr;
    bool found = false;
    while (!found && locptr != nullptr) {
        parent = locptr;
        if (item < locptr->data)
            locptr = locptr->left;
        else if (locptr->data < item)
            locptr = locptr->right;
        else
            found = true;
    }
    if (!found) {
        locptr = new BST<DataType>::BinNode(item);
        if (parent == nullptr)
            myRoot = locptr;
        else if (item < parent->data)
            parent->left = locptr;
        else
            parent->right = locptr;
    } else
        cout << "Item already in the tree.\n";
}

template<typename DataType>
void BST<DataType>::remove(const DataType &item) {
    bool found;
    BST<DataType>::BinNodePointer x, parent;
    search2(item, found, x, parent);

    if (!found) {
        cout << "Item not in the BST.\n";
        return;
    }
    // else
    if (x->left != nullptr && x->right != nullptr) {
        BST<DataType>::BinNodePointer xSucc = x->right;
        parent = x;
        while (xSucc->left != nullptr) {
            parent = xSucc;
            xSucc = xSucc->left;
        }

        x->data = xSucc->data;
        x = xSucc;
    } // end if node has 2 children

    // Now proceed with case where node has 0 or 2 child
    BST<DataType>::BinNodePointer subtree = x->left;
    if (subtree == nullptr)
        subtree = x->right;
    if (parent == nullptr)
        myRoot = subtree;
    else if (parent->left == x)
        parent->left = subtree;
    else
        parent->right = subtree;
    delete x;
}

template<typename DataType>
inline void BST<DataType>::inorder(ostream &out) const {
    inorderAux(out, myRoot);
}

template<typename DataType>
void BST<DataType>::graph(ostream &out) const {
    graphAux(out, 0, myRoot);
}

template<typename DataType>
void BST<DataType>::search2(const DataType &item, bool &found,
                            BST<DataType>::BinNodePointer &locptr,
                            BST<DataType>::BinNodePointer &parent) const {
    locptr = myRoot;
    parent = nullptr;
    found = false;
    while (!found && locptr != nullptr) {           // descend left
        if (item < locptr->data) {
            parent = locptr;
            locptr = locptr->left;
        } else if (locptr->data < item) {           // descend right
            parent = locptr;
            locptr = locptr->right;
        } else found = true;                        // item found
    }
}

template<typename DataType>
void BST<DataType>::inorderAux(ostream &out,
                               BST<DataType>::BinNodePointer subtreeRoot) const {
    if (subtreeRoot != nullptr) {
        inorderAux(out, subtreeRoot->left);
        out << subtreeRoot->data << "  ";
        inorderAux(out, subtreeRoot->right);
    }
}

#include <iomanip>

template<typename DataType>
void BST<DataType>::graphAux(ostream &out, int indent,
                             BST<DataType>::BinNodePointer subtreeRoot) const {
    if (subtreeRoot != nullptr) {
        graphAux(out, indent + 8, subtreeRoot->right);
        out << setw(indent) << " " << subtreeRoot->data << endl;
        graphAux(out, indent + 8, subtreeRoot->left);
    }
}

#endif
