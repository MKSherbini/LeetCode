#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/cousins-in-binary-tree-ii

class CousinsInBinaryTreeII {
public:
    // 15 ms, faster than 97.55% : 321.82 MB, less than 25.39%
    TreeNode* solution(TreeNode* root)
    {
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 0 });
        root->val = 0;
        vector<int> lvlsCnt(2);
        while (!empty(q)) {
            int lvl = size(q);
            while (lvl--) {
                auto [node, nodeSiblings] = q.front();
                Printer::print(node->val, nodeSiblings, lvlsCnt[0]);
                node->val = lvlsCnt[0] - nodeSiblings;
                q.pop();
                int siblings = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node->left)
                    q.push({ node->left, siblings }), lvlsCnt[1] += node->left->val;
                if (node->right)
                    q.push({ node->right, siblings }), lvlsCnt[1] += node->right->val;
            }
            lvlsCnt[0] = lvlsCnt[1];
            lvlsCnt[1] = 0;
        }

        return root;
    }
    vector<vector<int>> output = {
        { 0, 0, 0, 7, 7, NULL, 11 },
        { 0, 0, 0 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 5, 4, 9, 1, 10, NULL, 7 },
        { 3, 1, 2 }
    };
};