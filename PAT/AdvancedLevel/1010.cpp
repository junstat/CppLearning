// PAT Advance Level 1010
// Ye Qiu
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long convert2decimal(const string &n, long long radix) {
    long long res = 0, cur;
    int index = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++){
        cur = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        res += cur * pow(radix, index++);
    }
    return res;
}

long long find_radix(const string &n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long lo = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
    long long hi = max(num, lo);
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long t = convert2decimal(n, mid);
        if (t == num) return mid;
        else if (t < 0 || t > num) hi = mid - 1;
        else lo = mid + 1;
    }
    return -1;
}


int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert2decimal(n1, radix)) :
                   find_radix(n1, convert2decimal(n2, radix));
    if (result_radix == -1) {
        printf("Impossible");
    } else {
        printf("%lld", result_radix);
    }
    return 0;
}