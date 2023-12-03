#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string str, string pattern) {
        auto s = str.c_str();
        auto p = pattern.c_str();
        const char *star = nullptr;
        const char *ss = s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}

            // * found in pattern, track index of *, only advancing pattern pointer
            if (*p=='*'){star=p++; ss=s;continue;}

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;}

            //current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            return false;
        }

        //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;
    }
};