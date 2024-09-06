#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

class DeleteNodesFromLinkedListPresentInArray {
public:
    // 401 ms, faster than 93.54% : 258.26 MB, less than 94.79%
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> s;
        for (auto x : nums) {
            s.insert(x);
        }

        auto it = head;
        while (it->next) {
            if (s.count(it->next->val)) {
                it->next = it->next->next;
            } else {
                it = it->next;
            }
        }

        return s.count(head->val) ? head->next : head;
    }
};