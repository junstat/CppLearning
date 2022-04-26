// PAT Advance Level 1009
// Ye Qiu
#include <cstdio>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("input/1009.txt", "r", stdin);
#endif
    int lenA, lenB, exponent, cnt = 0;
    scanf("%d", &lenA);
    double coefficient, A[1001] = {0.0}, res[2001] = {0.0};
    for (int i = 0; i < lenA; i++) {
        scanf("%d %lf", &exponent, &coefficient);
        A[exponent] = coefficient;
    }
    scanf("%d", &lenB);
    for (int i = 0; i < lenB; i++) {
        scanf("%d %lf", &exponent, &coefficient);
        for (int j = 0; j < 1001; j++) {
            res[j + exponent] += A[j] * coefficient;
        }
    }

    for (int i = 2000; i >= 0; i--)
        if (res[i] != 0.0) cnt++;
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--)
        if (res[i] != 0.0) printf(" %d %.1f", i, res[i]);
    return 0;
}

