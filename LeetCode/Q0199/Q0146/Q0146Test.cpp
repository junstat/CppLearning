#include <gtest/gtest.h>
#include "solution2/Solution.cpp"

TEST(Q0146Test, example1) {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    auto val1 = lRUCache.get(1);    // 返回 1
    EXPECT_EQ(val1, 1);
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    auto val2 = lRUCache.get(2);    // 返回 -1 (未找到)
    EXPECT_EQ(val2, -1);
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    auto val3 = lRUCache.get(1);    // 返回 -1 (未找到)
    EXPECT_EQ(val3, -1);
    auto val4 = lRUCache.get(3);    // 返回 3
    EXPECT_EQ(val4, 3);
    auto val5 = lRUCache.get(4);    // 返回 4
    EXPECT_EQ(val5, 4);
}

TEST(Q0146Test, example2) {
    LRUCache lRUCache(2);
    auto val1 = lRUCache.get(2);
    EXPECT_EQ(val1, -1);
    lRUCache.put(2, 6);
    auto val2 =lRUCache.get(1);
    EXPECT_EQ(val2, -1);
    lRUCache.put(1, 5);
    lRUCache.put(1, 2);
    auto val3 = lRUCache.get(1);
    EXPECT_EQ(val3, 2);
    auto val4 = lRUCache.get(2);
    EXPECT_EQ(val4, 6);
}
