#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-right-side-view/

class BinaryTreeRightSideView
{
public:
	// 0 ms, faster than 100% : 11.7 MB, less than 96.89%
	vector<int> solution(TreeNode* root) {
		vector<int> ans;
		f(ans, root, 0);
		return ans;
	}
	void f(vector<int>& ans, TreeNode* node, int d) {
		if (!node) return;

		if (ans.size() == d) ans.push_back(node->val);

		f(ans, node->right, d + 1);
		f(ans, node->left, d + 1);
	}
	vector<vector<int>> output = {
		{1,3,4},
		{1,3},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,NULL,5,NULL,4},
		{1,NULL,3},
		{}
	};
};