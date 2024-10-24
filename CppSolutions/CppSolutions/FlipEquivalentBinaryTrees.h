#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/flip-equivalent-binary-trees

class FlipEquivalentBinaryTrees {
public:
    // 0 ms, faster than 100% : 15.47 MB, less than 6.32%
    uint8_t solution(TreeNode* root1, TreeNode* root2)
    {
        function<bool(TreeNode*, TreeNode*)> f = [&](TreeNode* node, TreeNode* node2) -> bool {
            if ((!node ^ !node2) || (node && node->val != node2->val))
                return false;

            if (!node)
                return true;

            return (f(node->left, node2->left) && f(node->right, node2->right)) || 
                (f(node->left, node2->right) && f(node->right, node2->left));
        };

        return f(root1, root2);
    }
    vector<uint8_t> output = {
        true,
        true,
        false
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4, 5, 6, NULL, NULL, NULL, 7, 8 },
        {},
        {}
    };
    vector<vector<int>> input2 = {
        { 1, 3, 2, NULL, 6, 4, 5, NULL, NULL, NULL, NULL, 8, 7 },
        {},
        { 1 }
    };
};