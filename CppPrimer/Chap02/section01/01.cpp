#include <iostream>

using namespace std;


// 含有无符号类型的表达式
void test1() {
    unsigned u = 10;
    int i = -42;
    cout << i + i << endl; // 输出-84
    /**
     * 在C++中，当有一个无符号整数（unsigned）和一个有符号整数（int）进行运算时，
     * 发生了整数提升（Integer Promotion）。
     * 整数提升会将较小的类型（如int）提升为较大的类型（如unsigned），以便它们能够进行有意义的运算。
     * 在你提到的表达式 u + i 中，i 会被提升为无符号整数，因为与 u 进行相加的时候，
     * i 的符号位被解释为无符号整数的位。
     * 具体来说，i 的值在无符号整数的表示范围内被看作是 2^32 - 42。然后，这两个无符号整数相加，得到 4294967264。
     * 以下是更详细的解释：
     * u 的值是 10，其二进制表示为 00000000000000000000000000001010。
     * i 被提升为无符号整数，其值是 4294967254（即 2^32 - 42），
     * 其二进制表示为 11111111111111111111111111010110。
     * 将这两个无符号整数相加，得到 4294967264（即 2^32 - 32）。
     */
    cout << u + i << endl; // 如果int占32位，输出4294967264
}

void test2() {
    unsigned u1 = 42, u2 = 10;
    cout << u1 - u2 << endl; // 正确: 输出32
    cout << u2 - u1 << endl; // 正确: 不过，结果是取模后的值 4294967264
}

int main() {
    test2();
    return 0;
}