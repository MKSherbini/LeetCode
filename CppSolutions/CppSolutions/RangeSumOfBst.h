#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/range-sum-of-bst/

class RangeSumOfBst
{
public:
	// 125 ms, faster than 97.98% : 64.6 MB, less than 92.64%
	int solution(TreeNode* root, int low, int high) {
		return f(root, low, high);
	}
	int f(TreeNode* node, int low, int high) {
		if (!node) return 0;

		auto l = node->left, r = node->right;

		int ret = 0;
		if (node->val <= high && node->val >= low)
			ret = node->val + f(node->right, low, high) + f(node->left, low, high);
		else if (node->val < low)
			ret += f(node->right, low, high);
		else if (node->val > high)
			ret += f(node->left, low, high);

		return ret;
	}
	vector<int> output = {
		32,
		23
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{10,5,15,3,7,NULL,18},
		{10,5,15,3,7,13,18,1,NULL,6}
	};
	vector<int> input2 = {
		7,
		6
	};
	vector<int> input3 = {
		15,
		10
	};
};