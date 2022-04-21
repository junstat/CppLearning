// PAT Advance Level 1001
// Ye Qiu
#include <iostream>
#include <string>

using namespace std;

/*
    把a+b的和转为字符串，除了第一位是符号的情况，只要当前位的下标满足(i+1)%3 == len % 3,
    并且i不是最后一位，就在逐位输出的时候在该位输出后加一个逗号
 */
int main(){
#ifdef ONLINE_JUDGE
#else
  freopen("./input/1001.txt", "r", stdin);
#endif
  int a, b;
  cin >> a >> b;
  string s = to_string(a + b);
  int len = s.length();
  for (int i = 0; i < len; i++) {
    cout << s[i];
    if (s[i] == '-' || i == len - 1) continue;
    if ((i + 1) % 3 == len % 3 ) cout << ",";
  }
  return 0;
}