#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/recover-binary-search-tree

class RecoverBinarySearchTree {
public:
    // 0 ms, faster than 100% : 60.73 MB, less than 83.68%
    vector<int> solution(TreeNode* root)
    {
        TreeNode *prev {}, *first {}, *last {};
        function<void(TreeNode*)> f = [&](TreeNode* node) {
            if (!node)
                return;

            f(node->left);

            if (prev != NULL && prev->val > node->val) {
                if (!first)
                    first = prev;
                last = node;
            }

            prev = node;
            f(node->right);
        };

        f(root);
        swap(first->val, last->val);
    }
    vector<vector<int>> output = {
        { 3, 1, NULL, NULL, 2 },
        { 2, 1, 4, NULL, NULL, 3 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 3, NULL, NULL, 2 },
        { 3, 1, 4, NULL, NULL, 2 }
    };
};