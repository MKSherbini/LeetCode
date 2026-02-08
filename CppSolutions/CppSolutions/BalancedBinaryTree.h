#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/balanced-binary-tree

class BalancedBinaryTree {
public:
    // 0 ms, faster than 100% : 23.2 MB, less than 20.59%
    uint8_t solution(TreeNode* root)
    {
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) {
                return 0;
            }
            int left = dfs(node->left);
            if (left == -1) {
                return -1;
            }
            int right = dfs(node->right);
            if (right == -1) {
                return -1;
            }
            if (abs(left - right) > 1) {
                return -1;
            }
            return max(left, right) + 1;
        };

        return dfs(root) != -1;
    }
    vector<uint8_t> output = {
        true,
        false,
        true
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 9, 20, NULL, NULL, 15, 7 },
        { 1, 2, 2, 3, 3, NULL, NULL, 4, 4 },
        {}
    };
};