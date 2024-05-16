#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

class EvaluateBooleanBinaryTree {
public:
    // 6 ms, faster than 90.97% : 18.38 MB, less than 24.21%
    uint8_t solution(TreeNode* root)
    {
        function<bool(TreeNode*)> f = [&](TreeNode* node) -> bool {
            if (!node->left && !node->right)
                return node->val;

            return node->val == 2 ? f(node->left) || f(node->right) : f(node->left) && f(node->right);
        };

        return f(root);
    }
    vector<uint8_t> output = {
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 1, 3, NULL, NULL, 0, 1 },
        { 0 }
    };
};