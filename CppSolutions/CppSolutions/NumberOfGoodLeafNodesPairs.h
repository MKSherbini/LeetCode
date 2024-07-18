#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

class NumberOfGoodLeafNodesPairs {
public:
    // 45 ms, faster than 67.04% : 47.08 MB, less than 17.59%
    int solution(TreeNode* root, int distance)
    {
        int ans = 0;
        function<unordered_map<int, int>(TreeNode*)> f = [&](TreeNode* node) -> unordered_map<int, int> {
            if (!node)
                return {};

            auto l = f(node->left), r = f(node->right);

            for (auto [d, c] : r) {
                for (auto [d2, c2] : l) {
                    if (d + d2 <= distance) {
                        ans += c * c2;
                        Printer::print("added: ", node->val);
                    }
                }
            }

            unordered_map<int, int> ret;
            if (!node->left && !node->right)
                ret[1] = 1;
            for (auto [d, c] : r) {
                if (d + 1 < distance) {
                    ret[d + 1] += c;
                }
            }
            for (auto [d, c] : l) {
                if (d + 1 < distance) {
                    ret[d + 1] += c;
                }
            }

            Printer::print(node->val, l, r);

            return ret;
        };
        f(root);

        return ans;
    }
    vector<int>
        output = {
            1,
            2,
            1
        };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 2, 3, NULL, 4 },
        { 1, 2, 3, 4, 5, 6, 7 },
        { 7, 1, 4, 6, NULL, 5, 3, NULL, NULL, NULL, NULL, NULL, 2 }
    };
    vector<int> input2 = {
        3,
        3,
        3
    };
};