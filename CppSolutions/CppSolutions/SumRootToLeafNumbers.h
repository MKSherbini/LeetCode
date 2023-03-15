#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sum-root-to-leaf-numbers/

class SumRootToLeafNumbers
{
public:
	// 0 ms, faster than 100% : 9 MB, less than 98.84%
	int solution(TreeNode* root) {
		return f(root, 0);
	}
	int f(TreeNode* node, int path) {
		if (!node) return 0;
		path = path * 10 + node->val;
		if (!node->left && !node->right) return path;

		return f(node->left, path) + f(node->right, path);
	}
	vector<int> output = {
		25,
		1026
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3},
		{4,9,0,5,1}
	};
};