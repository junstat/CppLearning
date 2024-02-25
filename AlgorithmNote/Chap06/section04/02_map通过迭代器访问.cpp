#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> mp;
    mp['m'] = 20;
    mp['r'] = 30;
    mp['a'] = 40;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}