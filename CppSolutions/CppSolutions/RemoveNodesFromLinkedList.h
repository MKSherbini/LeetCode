#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/remove-nodes-from-linked-list/

class RemoveNodesFromLinkedList {
public:
    // 269 ms, faster than 64.51% : 166.9 MB, less than 46.81%
    ListNode* solution(ListNode* head)
    {
        stack<ListNode*> st;
        while (head) {
            while (!empty(st) && st.top()->val < head->val) {
                st.pop();
            }
            st.push(head);
            head = head->next;
        }

        auto ans = st.top(), it = ans;
        st.pop();

        while (!empty(st)) {
            it->next = st.top();
            st.pop();
            it = it->next;
        }
        it->next = NULL;

        ListNode *cur = ans, *next = NULL;
        while (cur) {
            auto t = cur->next;
            cur->next = next;
            next = cur;
            cur = t;
        }

        return next;
    }
    vector<vector<int>> output = {
        { 13, 8 },
        { 1, 1, 1, 1 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 5, 2, 13, 3, 8 },
        { 1, 1, 1, 1 }
    };
};