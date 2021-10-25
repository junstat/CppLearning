#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

template<typename DataType>
void displayTree(DataType x[], int n);

template<typename DataType>
void displayOneLevel(DataType x[], int numRows,
                     int row, int row_begin, int row_end);

int main() {
    int x[11] = {87, 35, 74, 67, 79, 84, 76, 73, 81, 32};
    make_heap(x, x + 10);
    displayTree(x, 10);

    x[10] = 83;
    push_heap(x, x + 11);
    cout << "\nAfter push_heap(83):\n\n";
    displayTree(x, 11);

    pop_heap(x, x + 11);
    cout << "\nAfter pop_heap( ):\n\n";
    displayTree(x, 10);

    sort_heap(x, x + 10);
    cout << "\nAfter sort_heap( ), array contains:\n\n";
    for (int i = 1; i < 10; i++)
        cout << x[i] << "  ";
    cout << endl;
}

template<typename DataType>
void displayTree(DataType x[], int n) {
    int beginIndex = 0, endIndex = 0, rowLength, numLevels = int(ceil(log(double(n)) / log(2.0)));

    for (int level = 0; level < numLevels; level++) {
        displayOneLevel(x, numLevels, level, beginIndex, endIndex);
        rowLength = endIndex - beginIndex + 1;
        beginIndex = endIndex + 1;
        endIndex = min(endIndex + 2 * rowLength, n - 1);
    }
}

template<typename DataType>
void displayOneLevel(DataType x[], int numRows,
                     int level, int beginIndex, int endIndex) {
    int skip = int(pow(2.0, numRows - level) - 1);

    for (int i = beginIndex; i <= endIndex; i++) {
        cout << setw(skip) << " ";
        cout << setw(2) << x[i];
        cout << setw(skip) << " ";
    }
    cout << "\n\n";
}