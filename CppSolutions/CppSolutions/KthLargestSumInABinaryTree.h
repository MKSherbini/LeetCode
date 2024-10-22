#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree

class KthLargestSumInABinaryTree {
public:
    // best memory solution has almost this exact code :)
    // 17 ms, faster than 98.24% : 155.87 MB, less than 5.08%
    long long solution(TreeNode* root, int k)
    {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        while (!empty(q)) {
            int lvl = size(q);
            long long sum = 0;
            while (lvl--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            pq.push(sum);
            if (size(pq) > k)
                pq.pop();
        }

        return size(pq) < k ? -1 : pq.top();
    }
    vector<int> output = {
        13,
        3
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 5, 8, 9, 2, 1, 3, 7, 4, 6 },
        { 1, 2, NULL, 3 }
    };
    vector<int> input2 = {
        2,
        1
    };
};