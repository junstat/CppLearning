#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * string& operator+=(const char* str)
 * string& operator+=(const char c)
 * string& operator+=(const string& str)
 * string& append(const char* s)
 * string& append(const char* s, int n)
 * string& append(const string& s)
 * string& append(const string& s, int start, int n)
 */

void test1() {
    string s1 = "我";
    s1 += "爱玩游戏";
    cout << "s1= " << s1 << endl;

    s1 += ':';
    cout << "s1= " << s1 << endl;

    string s2 = "LOL DNF";
    s1 += s2;
    cout << "s1= " << s1 << endl;

    string s3 = "I";
    s3.append(" love ");
    cout << "s3= " << s3 << endl;

    s3.append("game sadlfkj", 4);
    cout << "s3= " << s3 << endl;

    // s3.append(s2);
    // s3.append(s2, 0, 3);
    s3.append(s2, 4, 3);
    cout << "s3= " << s3 << endl;

}

vector<string> split(const string &str, char delim) {
    vector<string> ans;
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, delim)) {
        ans.push_back(buffer);
    }
    return ans;
}

void test2() {
    string s = "apple,banana,orange";
    auto parts = split(s, ',');
    for (const auto &part: parts)
        cout << part << " ";
    cout << endl;
}

string join(vector<string> &parts, char delim) {
    ostringstream oss;
    for (size_t i = 0; i < parts.size(); ++i) {
        oss << parts[i];
        if (i != parts.size() - 1) oss << delim;
    }
    return oss.str();
}

void test3() {
    vector<string> parts = {"apple", "banana", "orange"};
    cout << join(parts, ',') << endl;
    cout << join(parts, '|') << endl;
}

int main() {
    test3();
    return 0;
}