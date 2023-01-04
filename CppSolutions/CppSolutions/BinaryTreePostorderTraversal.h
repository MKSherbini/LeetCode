#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-postorder-traversal

class BinaryTreePostorderTraversal
{
public:
	// 0 ms, faster than 100% : 8.4 MB, less than 88.57%
	vector<int> solution(TreeNode* root) {
		vector<int> ans;
		f(root, ans);
		return ans;
	}
	void f(TreeNode* node, vector<int>& ans) {
		if (!node) return;
		f(node->left, ans);
		f(node->right, ans);
		ans.push_back(node->val);
	}

	vector<vector<int>> output = {
		{3,2,1},
		{},
		{1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,NULL,2,3},
		{},
		{1}
	};
};