#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

class InsertGreatestCommonDivisorsInLinkedList {
public:
    // 35 ms, faster than 79.23% : 35.45 MB, less than 82.75%
    ListNode* solution(ListNode* head)
    {
        auto it = head;

        while (it->next) {
            it->next = new ListNode(gcd(it->val, it->next->val), it->next);
            it = it->next->next;
        }

        return head;
    }
    int gcd(int a, int b)
    {
        if (b > a)
            return gcd(b, a);
        return b == 0 ? a : gcd(b, a % b);
    }
    vector<vector<int>> output = {
        { 18, 6, 6, 2, 10, 1, 3 },
        { 7 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 18, 6, 10, 3 },
        { 7 }
    };
};