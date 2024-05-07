#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

class DoubleANumberRepresentedAsALinkedList {
public:
    // 257 ms, faster than 82.82% : 166.96 MB, less than 46.76%
    ListNode* solution(ListNode* head)
    {
        auto reverse = [](ListNode* head) {
            ListNode *cur = head, *next = NULL;
            while (cur) {
                auto t = cur->next;
                cur->next = next;
                next = cur;
                cur = t;
            }
            return next;
        };

        head = reverse(head);

        auto it = head, last = it;
        int c = 0;
        while (it) {
            it->val += it->val + c;
            c = it->val / 10;
            it->val %= 10;
            last = it;
            it = it->next;
        }
        if (c)
            last->next = new ListNode(c);

        return reverse(head);
    }

    vector<vector<int>> output = {
        { 3, 7, 8 },
        { 1, 9, 9, 8 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 8, 9 },
        { 9, 9, 9 }
    };
};