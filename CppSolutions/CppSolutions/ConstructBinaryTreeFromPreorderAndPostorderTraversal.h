#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal

class ConstructBinaryTreeFromPreorderAndPostorderTraversal {
public:
    // 0 ms, faster than 100% : 28.82 MB, less than 10.59%
    TreeNode* solution(vector<int> preorder, vector<int> postorder)
    {
        function<TreeNode*(int, int, int, int)> f = [&](int i, int j, int i2, int j2) -> TreeNode* {
            if (i > j)
                return nullptr;
            TreeNode* node = new TreeNode(preorder[i]);
            if (i == j)
                return node;
            int d = 0;
            while (postorder[i2 + d] != preorder[i + 1])
                d++;
            node->left = f(i + 1, i + 1 + d, i2, i2 + d);
            node->right = f(i + 2 + d, j, i2 + d + 1, j2 - 1);
            return node;
        };
        return f(0, preorder.size() - 1, 0, postorder.size() - 1);
    }
    vector<vector<int>> output = {
        { 1, 2, 3, 4, 5, 6, 7 },
        { 1 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 4, 5, 3, 6, 7 },
        { 1 }
    };
    vector<vector<int>> input2 = {
        { 4, 5, 2, 6, 7, 3, 1 },
        { 1 }
    };
};