class Solution {
public:
    double myPow(double x, int n) {
        long power = n;
        return power >= 0 ? myPowAux(x, power) : 1.0 / myPowAux(x, -power);
    }

    double myPowAux(double x, long n) {
        if (n == 0) return 1;
        return (n % 2 == 0) ? myPowAux(x * x, n / 2) : x * myPowAux(x * x, n / 2);
    }
};