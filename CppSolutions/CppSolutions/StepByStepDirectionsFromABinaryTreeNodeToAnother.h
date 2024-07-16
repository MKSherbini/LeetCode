#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

class StepByStepDirectionsFromABinaryTreeNodeToAnother {
public:
    // 2756 ms, faster than 5.04% : 157.79 MB, less than 14.05%
    string solution(TreeNode* root, int startValue, int destValue)
    {
        vector<char> path;
        vector<char> pathD;
        vector<char> pathS;
        function<void(TreeNode*)> f = [&](TreeNode* node) -> void {
            if (!node)
                return;

            if (node->val == destValue)
                pathD = path;
            if (node->val == startValue)
                pathS = path;

            path.push_back('L');
            f(node->left);
            path.back() = 'R';
            f(node->right);
            path.pop_back();
        };
        f(root);

        reverse(begin(pathS), end(pathS));
        reverse(begin(pathD), end(pathD));
        while (!empty(pathS) && !empty(pathD) && pathS.back() == pathD.back()) {
            pathD.pop_back(), pathS.pop_back();
        }

        return string(size(pathS), 'U') + string(rbegin(pathD), rend(pathD));
    }

    // 2756 ms, faster than 5.04% : 157.79 MB, less than 14.05%
    string solution2(TreeNode* root, int startValue, int destValue)
    {
        vector<pair<int, char>> path;
        vector<pair<int, char>> pathD;
        vector<pair<int, char>> pathS;
        function<void(TreeNode*)> f = [&](TreeNode* node) -> void {
            if (!node)
                return;

            if (node->val == destValue)
                pathD = path;
            if (node->val == startValue)
                pathS = path;

            path.push_back({ node->val, 'L' });
            f(node->left);
            path.back().second = 'R';
            f(node->right);
            path.pop_back();
        };
        f(root);
        pathD.push_back({ destValue, '.' });
        pathS.push_back({ startValue, '.' });

        int lastParent = 0;
        while (lastParent < size(pathS) && lastParent < size(pathD) && pathD[lastParent].first == pathS[lastParent].first) {
            lastParent++;
        }
        if (lastParent != 0)
            lastParent--;

        string ans = string(size(pathS) - lastParent - 1, 'U');
        for (size_t i = lastParent; i < size(pathD) - 1; i++) {
            ans += pathD[i].second;
        }

        return ans;
    }
    vector<string> output = {
        "UURL",
        "L"
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 5, 1, 2, 3, NULL, 6, 4 },
        { 2, 1 }
    };
    vector<int> input2 = {
        3,
        2
    };
    vector<int> input3 = {
        6,
        1
    };
};