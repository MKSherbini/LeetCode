#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/create-binary-tree-from-descriptions/

class CreateBinaryTreeFromDescriptions {
public:
    // 672 ms, faster than 77.08% : 276.08 MB, less than 59.83%
    TreeNode* solution(vector<vector<int>> descriptions)
    {
        unordered_map<int, TreeNode*> m;
        unordered_map<int, bool> p;
        for (auto& d : descriptions) {
            if (!p.count(d[0]))
                p[d[0]] = 1;
            p[d[1]] = 0;
            if (!m.count(d[0]))
                m[d[0]] = new TreeNode(d[0]);
            if (!m.count(d[1]))
                m[d[1]] = new TreeNode(d[1]);
            if (d[2])
                m[d[0]]->left = m[d[1]];
            else
                m[d[0]]->right = m[d[1]];
        }

        for (auto [v, p] : p) {
            if (p)
                return m[v];
        }

        return nullptr;
    }
    vector<vector<int>> output = {
        { 50, 20, 80, 15, 17, 19 },
        { 1, 2, NULL, NULL, 3, 4 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 20, 15, 1 }, { 20, 17, 0 }, { 50, 20, 1 }, { 50, 80, 0 }, { 80, 19, 1 } },
        { { 1, 2, 1 }, { 2, 3, 0 }, { 3, 4, 1 } }
    };
};