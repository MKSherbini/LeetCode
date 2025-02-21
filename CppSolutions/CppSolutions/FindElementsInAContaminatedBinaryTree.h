#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree

class FindElementsInAContaminatedBinaryTree {
public:
    // 8 ms, faster than 73.64% : 34.62 MB, less than 44.67%
    FindElementsInAContaminatedBinaryTree(TreeNode* root)
    {
        function<void(TreeNode * root, int)> f = [&](TreeNode* root, int val) {
            if (!root)
                return;
            s.insert(val);

            f(root->left, 2 * val + 1);
            f(root->right, 2 * val + 2);
        };

        f(root, 0);
    }

    bool find(int target)
    {
        return s.count(target);
    }

private:
    unordered_set<int> s;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */