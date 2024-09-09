/**
 * Definition for singly-linked list.
 */
#pragma once

#include <vector>
#include <fmt/format.h>

struct ListNode {
    int val{};
    ListNode *next{};

    ListNode() : val(0), next(nullptr) {
    }

    explicit ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

inline ListNode *createList(std::vector<int> &source) {
    ListNode *dummy = new ListNode(0, nullptr), *p = dummy;
    for (const auto &n: source) {
        p->next = new ListNode(n);
        p = p->next;
    }
    return dummy->next;
}

inline void printList(ListNode *head) {
    bool firstElem = true;
    for (auto p = head; p != nullptr; p = p->next) {
        if (!firstElem) fmt::print(" -> ");
        firstElem = false;
        fmt::print("{}", p->val);
    }
    fmt::println("");
}
