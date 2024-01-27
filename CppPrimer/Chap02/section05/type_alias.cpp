#include <iostream>
#include "../../lib/Sales_item.h"

using namespace std;

// 类型别名(type alias)
typedef double wages;
typedef wages base, *p;

// 新标准规定了一种新的方法，使用别名声明
using SI = Sales_item;

wages hourly, weekly;
SI item;

// 指针、常量和类型别名
typedef char *pstring;
const pstring cstr = 0; // cstr 是指向char的常量指针
const pstring *ps; // ps是一个指针，它的对象是指向char的常量指针
