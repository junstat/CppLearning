#include <iostream>
#include "../../lib/Sales_item.h"

using namespace std;

int main() {
    freopen("D:\\Documents\\Learn\\CLionProjects\\CppLearning\\CppPrimer\\Chap01\\data\\book_sales", "r", stdin);
    Sales_item total;
    if (cin >> total) {
        Sales_item trans;
        while (cin >> trans) {
            if (total.isbn() == trans.isbn())
                total += trans;
            else {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}