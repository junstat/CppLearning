#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

vector<char> g_v;
once_flag g_once;

void PushA() {
    call_once(g_once, []() { g_v.push_back('A'); });
}

void PushB() {
    call_once(g_once, []() { g_v.push_back('B'); });
}


void PushC() {
    call_once(g_once, []() { g_v.push_back('C'); });
}

int main() {
    thread st1(PushA);
    thread st2(PushB);
    thread st3(PushC);
    st1.join();
    st2.join();
    st3.join();
    for (auto x: g_v) {
        cout << x;
    }
    return 0;
}