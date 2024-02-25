#include <iostream>

using namespace std;

class Animal {
public:
    int age = 0;
};

// 利用虚继承 解决菱形继承问题
// Animal类称为 虚基类
class Sheep : virtual public Animal {

};

class Tuo : virtual public Animal {

};


class SheepTuo : public Sheep, public Tuo {

};

void test1() {
    SheepTuo st;
    st.Sheep::age = 18;
    st.Tuo::age = 28;

    // 当菱形继承，两个父类拥有相同数据，需要加以作用域区分
    cout << "st.Sheep::age= " << st.Sheep::age << endl;
    cout << "st.Tuo::age= " << st.Tuo::age << endl;
}

int main() {
    test1();
    return 0;
}