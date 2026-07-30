#include "leetcode_prelude.hpp"
#include "test_framework.hpp"

// The solution files are plain LeetCode submissions, so they are compiled
// into an anonymous namespace to keep the `Solution` names distinct.
namespace {
#include "../0328-odd-even-linked-list/0328-odd-even-linked-list.cpp"
}  // namespace
TEST(OddEvenLinkedList, odd_length) {
    Solution s;
    ListNode* head = buildList({1, 2, 3, 4, 5});
    ListNode* result = s.oddEvenList(head);
    vector<int> expected{1, 3, 5, 2, 4};
    CHECK_EQ(toVector(result), expected);
    freeList(result);
}

TEST(OddEvenLinkedList, even_length) {
    Solution s;
    ListNode* head = buildList({2, 1, 3, 5, 6, 4, 7});
    ListNode* result = s.oddEvenList(head);
    vector<int> expected{2, 3, 6, 7, 1, 5, 4};
    CHECK_EQ(toVector(result), expected);
    freeList(result);
}

TEST(OddEvenLinkedList, empty_list) {
    Solution s;
    CHECK_TRUE(s.oddEvenList(nullptr) == nullptr);
}

TEST(OddEvenLinkedList, single_node) {
    Solution s;
    ListNode* head = buildList({9});
    ListNode* result = s.oddEvenList(head);
    vector<int> expected{9};
    CHECK_EQ(toVector(result), expected);
    freeList(result);
}

TEST(OddEvenLinkedList, two_nodes) {
    Solution s;
    ListNode* head = buildList({1, 2});
    ListNode* result = s.oddEvenList(head);
    vector<int> expected{1, 2};
    CHECK_EQ(toVector(result), expected);
    freeList(result);
}
