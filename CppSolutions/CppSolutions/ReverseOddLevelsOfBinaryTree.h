#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree

class ReverseOddLevelsOfBinaryTree {
public:
    // 0 ms, faster than 100% : 81.94 MB, less than 44.08%
    TreeNode* solution(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;
        while (!empty(q)) {
            int c = size(q);
            lvl++;
            vector<TreeNode*> row;
            while (c--) {
                auto cur = q.front();
                if ((lvl & 1) == 0)
                    row.push_back(cur);
                q.pop();

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (!empty(row)) {
                for (size_t i = 0; i < size(row) / 2; i++) {
                    swap(row[i]->val, row[size(row) - i - 1]->val);
                }
            }
        }

        return root;
    }
    vector<vector<int>> output = {
        { 2, 5, 3, 8, 13, 21, 34 },
        { 7, 11, 13 },
        { 0, 2, 1, 0, 0, 0, 0, 2, 2, 2, 2, 1, 1, 1, 1 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 3, 5, 8, 13, 21, 34 },
        { 7, 13, 11 },
        { 0, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2 }
    };
};