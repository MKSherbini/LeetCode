#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

class BinarySearchTreeToGreaterSumTree {
public:
    // 0 ms, faster than 100% : 10.22 MB, less than 12.64%
    TreeNode* solution(TreeNode* root)
    {
        int sum = 0;
        function<void(TreeNode*)> f = [&](TreeNode* node) -> void {
            if (!node)
                return;
            f(node->right);
            sum += node->val;
            node->val += sum - node->val;
            f(node->left);
        };
        f(root);
        return root;
    }
    vector<vector<int>> output = {
        { 30, 36, 21, 36, 35, 26, 15, NULL, NULL, NULL, 33, NULL, NULL, NULL, 8 },
        { 1, NULL, 1 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 4, 1, 6, 0, 2, 5, 7, NULL, NULL, NULL, 3, NULL, NULL, NULL, 8 },
        { 0, NULL, 1 }
    };
};