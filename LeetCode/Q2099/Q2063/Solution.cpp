#include <string>

using namespace std;

class Solution {
public:
    long long countVowels(string word) {
        long ans = 0, n = word.size();
        for (int i = 0; i < n; i++)
            if (vowels.find(word[i]) != string::npos)
                ans += (i + 1) * (n - i);
        return ans;
    }

private:
    const string vowels = "aeiou";
};