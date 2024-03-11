
// 第一种解决方式: 直接include Person.cpp
#include "Person.cpp"

// 第二种解决方式: 将.h和.cpp中的内容写到一起，将后缀名改成.hpp


int main() {
    Person<string, int> p("John", 30);
    p.show();
    return 0;
}