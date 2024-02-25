#include <iostream>

using namespace std;

// 继承的好处: 减少重复代码
// 语法: class 子类: 继承方式 父类
// 子类 也称为 派生类
// 父类 也称为 基类

class BasePage {
public:
    BasePage(string sub) : subject(sub) {}

    void header() {
        cout << "首页、公开课、登录、注册....(公共头部)" << endl;
    }

    void footer() {
        cout << "帮助中心、交流合作、站内地图....(公共底部)" << endl;
    }

    void left() {
        cout << "Java、Python、C++....(公共左侧)" << endl;
    }

    void content() {
        header();
        footer();
        left();
        cout << subject << "学科视频" << endl;
    }

    string subject;
};

class Java : public BasePage {
public:
    Java(string sub) : BasePage(sub) {}
};

class Python : public BasePage {
public:
    Python(string sub) : BasePage(sub) {}
};

class Cpp : public BasePage {
public:
    Cpp(string sub) : BasePage(sub) {}
};

void test1() {
    cout << "Java下载视频页面如下: " << endl;
    Java java("Java");
    java.content();

    cout << "------------------------" << endl;
    cout << "Python下载视频页面如下: " << endl;
    Python python("Python");
    python.content();

    cout << "------------------------" << endl;
    cout << "Cpp下载视频页面如下: " << endl;
    Cpp cpp("Cpp");
    cpp.content();
}

int main() {
    test1();
    return 0;
}