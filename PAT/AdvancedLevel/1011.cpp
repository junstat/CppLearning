// PAT Advance Level 1011
// Ye Qiu
#include <cstdio>

using namespace std;

int main() {
    char c[4] = {"WTL"};
    double ans = 1.0;
    for (int i = 0; i < 3; i++) {
        double max_value = 0.0;
        int max_char = 0;
        for (int j = 0; j < 3; j++) {
            double cur_result = 0.0;
            scanf("%lf", &cur_result);
            if (max_value <= cur_result) {
                max_value = cur_result;
                max_char = j;
            }
        }
        ans *= max_value;
        printf("%c ", c[max_char]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}