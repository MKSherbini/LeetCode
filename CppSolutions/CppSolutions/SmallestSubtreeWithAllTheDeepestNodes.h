#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

class SmallestSubtreeWithAllTheDeepestNodes {
public:
    // 0 ms, faster than 100% : 16.08 MB, less than 95.87%
    TreeNode* solution(TreeNode* root)
    {
        int maxDepth = -1, dCnt = 0;
        TreeNode* ans = nullptr;
        function<pair<int, int>(TreeNode*, int)> dfs = [&](TreeNode* node, int depth) -> pair<int, int> {
            if (!node)
                return {};

            if (depth > maxDepth) {
                maxDepth = depth;
                dCnt = 1;
                ans = nullptr;
            } else if (depth == maxDepth) {
                dCnt++;
                ans = nullptr;
            }
            auto [lc, ld] = dfs(node->left, depth + 1);
            auto [rc, rd] = dfs(node->right, depth + 1);
            int dCur = (depth == maxDepth);
            if (ld == maxDepth)
                dCur += lc;
            if (rd == maxDepth)
                dCur += rc;
            if (dCur == dCnt && ans == nullptr) {
                ans = node;
            }
            return { dCur, maxDepth };
        };

        dfs(root, 0);
        return ans;
    }
    vector<vector<int>> output = {
        { 2, 7, 4 },
        { 1 },
        { 2 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 5, 1, 6, 2, 0, 8, NULL, NULL, 7, 4 },
        { 1 },
        { 0, 1, 3, NULL, 2 }
    };
};