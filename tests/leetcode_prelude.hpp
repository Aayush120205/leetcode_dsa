// Provides the implicit LeetCode environment (headers, `using namespace std`
// and the shared data structures) that the solution files assume.
#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Builds a singly linked list from `values`; the caller owns the nodes and
// should release them with freeList().
inline ListNode* buildList(const vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

inline vector<int> toVector(ListNode* head) {
    vector<int> out;
    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
        out.push_back(cur->val);
    }
    return out;
}

inline void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}
