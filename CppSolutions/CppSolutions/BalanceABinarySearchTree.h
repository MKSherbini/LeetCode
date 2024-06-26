#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/balance-a-binary-search-tree/description/

class BalanceABinarySearchTree {
public:
    // 91 ms, faster than 57.31% : 62.58 MB, less than 60.81%
    TreeNode* solution(TreeNode* root)
    {
        vector<int> v;
        function<void(TreeNode*)> f = [&](TreeNode* node) -> void {
            if (!node)
                return;
            f(node->left);
            v.push_back(node->val);
            f(node->right);
        };
        f(root);

        function<TreeNode*(int, int)> ff = [&](int start, int end) -> TreeNode* {
            if (start > end)
                return NULL;

            int md = start + (end - start) / 2;
            return new TreeNode(v[md], ff(start, md - 1), ff(md + 1, end));
        };

        return ff(0, size(v) - 1);
    }
    vector<vector<int>> output = {
        { 2, 1, 3, NULL, NULL, NULL, 4 },
        { 2, 1, 3 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, NULL, 2, NULL, 3, NULL, 4, NULL, NULL },
        { 2, 1, 3 }
    };
};