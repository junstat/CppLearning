#include <iostream>

using namespace std;

#define ALPHA(x) if(x) { \
    cout << #x;              \
} else {                 \
    cout << "?";                         \
}

int main() {
    int i = 1;
    ALPHA(i < 3);
    return 0;
}