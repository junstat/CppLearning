#include <iostream>
#include "../../lib/Sales_item.h"

using namespace std;

int main() {
    freopen("D:\\Documents\\Learn\\CLionProjects\\CppLearning\\CppPrimer\\Chap01\\section05\\add_inputfile.txt", "r",
            stdin);
    Sales_item item1, item2;
    cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) {
        cout << item1 + item2 << endl;
        return 0;
    } else {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }
}