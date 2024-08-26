#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/

class NAryTreePostorderTraversal {
public:
    // 3 ms, faster than 99.94% : 15.1 MB, less than 70.21%
    vector<int> solution(Node* root)
    {
        vector<int> ans;
        function<void(Node*)> f = [&](Node* node) {
            if (!node)
                return;

            for (auto c : node->children)
                f(c);

            ans.push_back(node->val);
        };
        f(root);

        return ans;
    }
    vector<vector<int>> output = {
        { 5, 6, 3, 2, 4, 1 },
        { 2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, NULL, 3, 2, 4, NULL, 5, 6 },
        { 1, NULL, 2, 3, 4, 5, NULL, NULL, 6, 7, NULL, 8, NULL, 9, 10, NULL, NULL, 11, NULL, 12, NULL, 13, NULL, NULL, 14 }
    };
};