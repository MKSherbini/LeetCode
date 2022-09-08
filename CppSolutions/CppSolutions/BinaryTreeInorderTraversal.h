#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-inorder-traversal/

class BinaryTreeInorderTraversal
{
public:
	// 0 ms, faster than 100% : 8.2 MB, less than 98.26%
	vector<int> solution(TreeNode* root) {
		vector<int> ans;
		f(ans, root);
		return ans;
	}
	void f(vector<int>& ans, TreeNode* node) {
		if (!node) return;
		f(ans, node->left);
		ans.push_back(node->val);
		f(ans, node->right);
	}
	vector<vector<int>> output = {
		{1,3,2},
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