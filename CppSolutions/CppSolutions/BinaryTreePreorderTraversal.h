#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-preorder-traversal/

class BinaryTreePreorderTraversal
{
public:
	// 0 ms, faster than 100% : 8.3 MB, less than 77.87%
	vector<int> solution(TreeNode* root) {
		Printer::print(root);
		vector<int> ans;
		curse(ans, root);
		return ans;
	}
	void curse(vector<int>& v, TreeNode* node) {
		if (!node) return;

		v.push_back(node->val);
		curse(v, node->left);
		curse(v, node->right);
	}

	vector<vector<int>> output = {
		{1,2,3},
		{},
		{1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,NULL,2,NULL,NULL,3},
		{},
		{1}
	};
};