#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/linked-list-in-binary-tree/description/

class LinkedListInBinaryTree {
public:
    // 19 ms, faster than 90.39% : 31.88 MB, less than 13.39%
    uint8_t solution(ListNode* head, TreeNode* root)
    {
        function<bool(TreeNode*, ListNode*)> m = [&](TreeNode* node, ListNode* list) -> bool {
            if (!list)
                return true;

            if (!node)
                return false;

            if (list->val != node->val)
                return false;

            return m(node->left, list->next) || m(node->right, list->next);
        };

        function<bool(TreeNode*)> f = [&](TreeNode* node) -> bool {
            if (!node)
                return false;

            return m(node, head) || f(node->left) || f(node->right);
        };

        return f(root);
    }
    vector<uint8_t> output = {
        true,
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, 2, 8 },
        { 1, 4, 2, 6 },
        { 1, 4, 2, 6, 8 }
    };
    vector<vector<int>> input2 = {
        { 1, 4, 4, NULL, 2, 2, NULL, 1, NULL, 6, 8, NULL, NULL, NULL, NULL, 1, 3 },
        { 1, 4, 4, NULL, 2, 2, NULL, 1, NULL, 6, 8, NULL, NULL, NULL, NULL, 1, 3 },
        { 1, 4, 4, NULL, 2, 2, NULL, 1, NULL, 6, 8, NULL, NULL, NULL, NULL, 1, 3 }
    };
};