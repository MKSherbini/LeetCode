#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/invert-binary-tree/

class InvertBinaryTree
{
public:
	// 0 ms, faster than 100% : 9.5 MB, less than 97.8%
	TreeNode* solution(TreeNode* root) {
		f(root);
		return root;
	}
	void f(TreeNode* node) {
		if (!node) return;
		auto temp = node->left;
		node->left = node->right;
		node->right = temp;
		f(node->left);
		f(node->right);
	}
	vector<vector<int>> output = {
		{4,7,2,9,6,3,1},
		{2,3,1},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{4,2,7,1,3,6,9},
		{2,1,3},
		{}
	};
};