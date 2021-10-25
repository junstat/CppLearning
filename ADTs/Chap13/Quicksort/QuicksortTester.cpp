#include "Quicksort.h"

template<typename ElementType>
void display(ElementType x[], int n) {
    for (int i = 0; i < n; i++)
        cout << x[i] << "  ";
    cout << endl;
}

int main() {
    int x[] = {8, 2, 13, 5, 14, 3, 7};
    int len = sizeof(x) / sizeof(x[0]);
    cout << "Before sort:\n";
    display(x, len);
    quicksort(x, len);
    cout << "After sort:\n";
    display(x, len);
}