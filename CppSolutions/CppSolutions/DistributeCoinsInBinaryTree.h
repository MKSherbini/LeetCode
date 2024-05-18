#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/distribute-coins-in-binary-tree/description/

class DistributeCoinsInBinaryTree {
public:
    // 0 ms, faster than 100% : 15.4 MB, less than 99.33%
    int solution(TreeNode* root)
    {
        int ans = 0;
        function<int(TreeNode*)> f = [&](TreeNode* node) -> int {
            if (!node)
                return 0;

            auto l = f(node->left), r = f(node->right);
            int need = l + r + node->val - 1;
            ans += abs(need);

            return need;
        };

        f(root);
        return ans;
    }
    vector<int> output = {
        2,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 3, 0, 0 },
        { 0, 3, 0 }
    };
};