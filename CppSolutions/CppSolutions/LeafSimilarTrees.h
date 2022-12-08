#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/leaf-similar-trees/

class LeafSimilarTrees
{
public:
	// 0 ms, faster than 100% : 12.6 MB, less than 96.71%
	bool solution(TreeNode* root1, TreeNode* root2) {
		vector<int> v;
		f(root1, v);
		reverse(begin(v), end(v));
		return match(root2, v) && v.empty();
	}
	void f(TreeNode* node, vector<int>& v) {
		if (!node) return;

		if (!node->left && !node->right)
			v.push_back(node->val);
		else f(node->left, v), f(node->right, v);
	}
	bool match(TreeNode* node, vector<int>& v) {
		if (!node) return 1;

		if (!node->left && !node->right) {
			if (v.empty() || v.back() != node->val) return false;
			v.pop_back();
			return true;
		}

		return match(node->left, v) && match(node->right, v);
	}
	vector<bool> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{3,5,1,6,2,9,8,NULL,NULL,7,4},
		{1,2,3}
	};
	vector<vector<int>> input2 = {
		{3,5,1,6,7,4,2,NULL,NULL,NULL,NULL,NULL,NULL,9,8},
		{1,3,2}
	};
};