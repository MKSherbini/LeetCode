#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-depth-of-binary-tree/

class MinimumDepthOfBinaryTree
{
public:
	// 255 ms, faster than 98.11% : 144.4 MB, less than 96.64%
	int solution(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> q;
		q.push(root);

		int ans = 0;
		while (!q.empty()) {
			int c = size(q);
			ans++;
			while (c--) {
				auto& t = q.front();
				if (!t->left && !t->right) return ans;
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
				q.pop();
			}
		}

		return ans;
	}
	vector<int> output = {
		2,
		5
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,9,20,NULL,NULL,15,7},
		{2,NULL,3,NULL,4,NULL,5,NULL,6}
	};
};