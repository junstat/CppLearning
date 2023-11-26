#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string entityParser(string text) {
        if (text.empty()) return "";
        unordered_map<string, string> repMap = {
                {"&quot;",  "\""},
                {"&apos;",  "'"},
                {"&gt;",    ">"},
                {"&lt;",    "<"},
                {"&frasl;", "/"}
        };
        for (auto &[key, val]: repMap) {
            replace(text, key, val);
        }
        replace(text, "&amp;", "&");
        return text;
    }

    void replace(string &text, const string &p, const string &r) {
        auto pos = text.find(p);
        while (pos != string::npos) {
            text.replace(pos, p.length(), r);
            pos = text.find(p, pos + r.length());
        }
    }
};