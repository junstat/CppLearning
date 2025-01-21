#include <fmt/format.h>
#include <gtest/gtest.h>
#include <deque>

/*
 * deque常用API
 * push_back: 尾插
 * push_front: 头插
 * pop_back: 尾删
 * pop_front: 头删
 * front: 访问队头元素
 * back: 访问队尾元素
 * size: 获取队列中元素数量
 * empty: 判断队列是否为空
 */

TEST(DequeTest, example1) {
    std::deque<int> dp{1, 2, 3};

    dp.push_back(10);
    dp.push_front(20);
    dp.push_back(30);

    dp.push_front(5);
    dp.push_front(6);

    fmt::print("Deque elements: ");
    for (auto &e: dp) {
        fmt::print("{} ", e);
    }
    fmt::print("\n");

    fmt::println("Front element: {}", dp.front());
    fmt::println("Back element: {}", dp.back());

    dp.pop_front();
    dp.pop_back();

    fmt::print("Deque after popping elements: ");
    for (auto &e: dp) {
        fmt::print("{} ", e);
    }
    fmt::print("\n");

    fmt::println("Deque size: {}", dp.size());

    if (dp.empty()) {
        fmt::println("Deque is empty!");
    } else {
        fmt::println("Deque is not empty!");
    }
}