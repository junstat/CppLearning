#include <iostream>

using namespace std;

// 抽象不同零件类
// 抽象CPU
class CPU {
public:
    virtual ~CPU() {}

    // 抽象的计算函数
    virtual void calculate() = 0;
};

// 抽象显卡类
class VideoCard {
public:
    virtual ~VideoCard() {}

    // 抽象的显示函数
    virtual void display() = 0;
};

// 抽象内存条类
class Memory {
public:
    virtual ~Memory() {}

    // 抽象的存储函数
    virtual void storage() = 0;
};

// 电脑类
class Computer {
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem) :
            cpu(cpu), vc(vc), mem(mem) {}

    void work() {
        cpu->calculate();
        vc->display();
        mem->storage();
        cout << "计算机工作正常！" << endl;
    }

    // 提供析构函数 释放3个零件
    ~Computer() {
        if (cpu != nullptr) {
            delete cpu;
            cpu = nullptr;
        }
        if (vc != nullptr) {
            delete vc;
            vc = nullptr;
        }
        if (mem != nullptr) {
            delete mem;
            mem = nullptr;
        }
    }

private:
    CPU *cpu;
    VideoCard *vc;
    Memory *mem;
};


// 具体厂商
// Intel厂商
class IntelCPU : public CPU {
public:
    void calculate() {
        cout << "Intel的CPU开始计算了！" << endl;
    }
};

class IntelVideoCard : public VideoCard {
public:
    void display() {
        cout << "Intel的显卡开始显示了！" << endl;
    }
};

class IntelMemory : public Memory {
public:
    void storage() {
        cout << "Intel的内存开始存储了！" << endl;
    }
};

// Lenovo 厂商
class LenovoCPU : public CPU {
public:
    void calculate() {
        cout << "Lenovo的CPU开始计算了！" << endl;
    }
};

class LenovoVideoCard : public VideoCard {
public:
    void display() {
        cout << "Lenovo的显卡开始显示了！" << endl;
    }
};

class LenovoMemory : public Memory {
public:
    void storage() {
        cout << "Lenovo的内存开始存储了！" << endl;
    }
};

void test1() {
    // 创建Intel厂商的组件
    CPU *intelCPU = new IntelCPU;
    VideoCard *intelVideoCard = new IntelVideoCard;
    Memory *intelMemory = new IntelMemory;

    // 创建计算机对象，使用Intel的组件
    Computer *computer1 = new Computer(intelCPU, intelVideoCard, intelMemory);
    computer1->work();
    delete computer1;

    cout << "----------------------" << endl;
    // 第二台电脑组装
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    computer2->work();
    delete computer2;

}

int main() {
    test1();
    return 0;
}