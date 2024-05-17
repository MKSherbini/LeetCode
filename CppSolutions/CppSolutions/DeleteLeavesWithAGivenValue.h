#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

class DeleteLeavesWithAGivenValue {
public:
    // 8 ms, faster than 82.4% : 21.69 MB, less than 9.62%
    TreeNode* solution(TreeNode* root, int target)
    {
        function<bool(TreeNode*)> f = [&](TreeNode* node) -> bool {
            if (!node)
                return false;

            auto l = f(node->left), r = f(node->right);
            if (!l) {
                delete node->left;
                node->left = NULL;
            }
            if (!r) {
                delete node->right;
                node->right = NULL;
            }
            if (!l && !r && node->val == target) {
                return false;
            }
            
            return true;
        };

        return f(root) ? root : NULL;
    }
    vector<vector<int>> output = {
        { 1, NULL, 3, NULL, 4 },
        { 1, 3, NULL, NULL, 2 },
        { 1 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 2, NULL, 2, 4 },
        { 1, 3, 3, 3, 2 },
        { 1, 2, NULL, 2, NULL, 2 }
    };
    vector<int> input2 = {
        2,
        3,
        2
    };
};