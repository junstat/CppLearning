#include <iostream>
#include <string>

using namespace std;

int main() {
    string alpha = "AB";
    alpha.insert(1, "C");
    alpha.push_back('D');
    cout << alpha << endl;
    return 0;
}