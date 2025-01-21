#include <cstdio>
#include <functional>
#include "gtest/gtest.h"
#include "fmt/format.h"

class defer_holder {
public:
    explicit defer_holder(std::function<void()> f) : f_(f) {}

    ~defer_holder() { f_(); }

private:
    std::function<void()> f_;
};

#define DEFER_CONN_INNER(text1, text2) text1##text2
#define DEFER_CONN(text1, text2) DEFER_CONN_INNER(text1, text2)
#define defer(x) defer_holder DEFER_CONN(defer_, __LINE__)(x)

TEST(FileTest, test) {
    std::string filePath = "D:\\Documents\\CLionProjects\\CppLearning\\LeetCode\\Tricks\\data.txt";
    FILE *dataFile = fopen(filePath.c_str(), "w+");
    if (dataFile == nullptr) {
        fmt::println("Error: Create file failed, file name: {}!", filePath);
        return;
    }
    defer([&]() { fclose(dataFile); });
    fmt::print(dataFile, "First Line.\n");
    fmt::print(dataFile, "Second Line.\n");
}
