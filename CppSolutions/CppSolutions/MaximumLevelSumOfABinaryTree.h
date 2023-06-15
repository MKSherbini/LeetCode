#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

class MaximumLevelSumOfABinaryTree
{
public:
	// 191 ms, faster than 89.04% : 107.1 MB, less than 84.3%
	int solution(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		int lvl = 1;
		int ans = 1;
		int mx = -1e8;
		while (!q.empty()) {
			int c = size(q);
			int sum = 0;
			while (c--) {
				sum += q.front()->val;

				if (q.front()->left)
					q.push(q.front()->left);
				if (q.front()->right)
					q.push(q.front()->right);
				q.pop();
			}
			if (sum > mx) mx = sum, ans = lvl;
			lvl++;
		}

		return ans;
	}

	vector<int> output = {
		2,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,7,0,7,-8,NULL,NULL},
		{989,NULL,10250,98693,-89388,NULL,NULL,NULL,-32127}
	};
};