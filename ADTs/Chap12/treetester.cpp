#include "BST.h"

int main() {
    // Testing Constructor and empty()
    BST<int> intBST;
    cout << "Constructing empty BST.\n";
    cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty.\n";

    // Testing inorder
    cout << "Inorder Traversal of BST: \n";
    intBST.inorder(cout);

    // Testing insert()
    cout << "\nNow insert a bunch of integers into the BST."
            "\nTry items not in the BST and some that are in it:\n";
    int number;
    for (;;) {
        cout << "Item to insert (-999 to stop): ";
        cin >> number;
        if (number == -999) break;
        intBST.insert(number);
    }
    intBST.graph(cout);

    cout << "BST" << (intBST.empty() ? "is" : "is not") << "empty\n";
    cout << "Inorder Traversal of BST: \n";
    intBST.inorder(cout);

    cout << endl;

    // Testing search()
    cout << "\n\nNow testing the search() operation."
            "\nTry both items in the BST and some not in it:\n";

    for (;;) {
        cout << "Item to find(-999 to stop):";
        cin >> number;
        if (number == -999) break;
        cout << (intBST.search(number) ? "Found" : "Not found") << endl;
    }

    // Testing remove()
    cout << "\nNow testing the remove() operation."
            "\nTry both items in the BST and some not in it:\n";
    for (;;) {
        cout << "Item to remove (-999 to stop):";
        cin >> number;
        if (number == -999) break;
        intBST.remove(number);
        intBST.graph(cout);
    }
    cout << "\nInorder Traversal of BST:\n";
    intBST.inorder(cout);
    cout << endl;
}
/*
Constructing empty BST.
BST is empty.
Inorder Traversal of BST:

Now insert a bunch of integers into the BST.
Try items not in the BST and some that are in it:
Item to insert (-999 to stop): 55
Item to insert (-999 to stop): 66
Item to insert (-999 to stop): 88
Item to insert (-999 to stop): 77
Item to insert (-999 to stop): 20
Item to insert (-999 to stop): 10
Item to insert (-999 to stop): 30
Item to insert (-999 to stop): -999
                88
                        77
        66
 55
                30
        20
                10
BST is not empty
Inorder Traversal of BST:
10  20  30  55  66  77  88


Now testing the search() operation.
Try both items in the BST and some not in it:
Item to find(-999 to stop):66
Found
Item to find(-999 to stop):44
Not found
Item to find(-999 to stop):10
Found
Item to find(-999 to stop):11
Not found
Item to find(-999 to stop):-999

Now testing the remove() operation.
Try both items in the BST and some not in it:
Item to remove (-999 to stop):10
                88
                        77
        66
 55
                30
        20
Item to remove (-999 to stop):66
        88
                77
 55
                30
        20
Item to remove (-999 to stop):55
        88
 77
                30
        20
Item to remove (-999 to stop):-999

Inorder Traversal of BST:
20  30  77  88
 */