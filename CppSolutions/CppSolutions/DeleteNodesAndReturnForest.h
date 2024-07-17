#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/delete-nodes-and-return-forest/description/

class DeleteNodesAndReturnForest {
public:
    // 16 ms, faster than 56.71% : 27.75 MB, less than 16.35%
    vector<TreeNode*> solution(TreeNode* root, vector<int> to_delete)
    {
        if (!root)
            return {};

        unordered_set<int> s(begin(to_delete), end(to_delete));

        vector<TreeNode*> ans;
        function<void(TreeNode*, bool)> f = [&](TreeNode* node, bool add) -> void {
            if (add && !s.count(node->val))
                ans.push_back(node);
            add = s.count(node->val);
            if (node->left) {
                f(node->left, add);
                if (s.count(node->left->val))
                    node->left = nullptr;
            }
            if (node->right) {
                f(node->right, add);
                if (s.count(node->right->val))
                    node->right = nullptr;
            }
        };
        f(root, 1);

        return ans;
    }
    vector<vector<vector<int>>> output = {
        { { 1, 2, NULL, 4 }, { 6 }, { 7 } },
        { { 1, 2, 4 } }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3, 4, 5, 6, 7 },
        { 1, 2, 4, NULL, 3 }
    };
    vector<vector<int>> input2 = {
        { 3, 5 },
        { 3 }
    };
};