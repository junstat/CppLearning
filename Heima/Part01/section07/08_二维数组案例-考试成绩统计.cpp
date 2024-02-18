#include <iostream>

using namespace std;

int main() {
    int scores[3][3] = {
            {100, 100, 100},
            {90,  50,  100},
            {60,  70,  80}
    };

    // 统计每个人的总和分数
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) rowSum += scores[i][j];
        cout << i << " -> " << rowSum << endl;
    }
    return 0;
}