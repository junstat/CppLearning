#include "SeqList.h"

int main() {
    int *q = (int *) malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        q[i] = i + 1;
        cout << q[i] << "  ";
    }
    return 0;
}

