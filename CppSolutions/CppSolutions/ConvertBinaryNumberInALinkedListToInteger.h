#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

class ConvertBinaryNumberInALinkedListToInteger {
public:
    // 0 ms, faster than 100% : 10.5 MB, less than 71.97%
    int solution(ListNode* head)
    {
        int ans = 0;
        while (head) {
            ans <<= 1;
            ans += head->val;
            head = head->next;
        }

        return ans;
    }
    vector<int> output = {
        5,
        0
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 0, 1 },
        { 0 }
    };
};