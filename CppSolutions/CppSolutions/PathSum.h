#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/path-sum/

class PathSum
{
public:
	// 7 ms, faster than 97.92% : 21.1 MB, less than 92.08%
	bool solution(TreeNode* root, int targetSum) {
		return f(root, targetSum);
	}
	bool f(TreeNode* node, int sum) {
		if (!node) return false;
		sum -= node->val;

		if (!node->left && !node->right && sum == 0) return true;
		bool ret = f(node->left, sum);
		if (ret) return ret;
		ret |= f(node->right, sum);
		return ret;
	}
	vector<bool> output = {
		true,
		false,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1},
		{1,2,3},
		{}
	};
	vector<int> input2 = {
		22,
		5,
		0
	};
};