#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/path-sum-iii/

class PathSumIII
{
public:
	// 71 ms, faster than 6.42% : 16.1 MB, less than 57.95%
	int solution(TreeNode* root, int targetSum) {
		function<int(TreeNode*, long long)> f = [&](TreeNode* node, long long sum) -> int {
			if (!node) return 0;

			sum -= node->val;
			return (sum == 0) + f(node->left, sum) + f(node->right, sum);
		};
		function<int(TreeNode*)> f2 = [&](TreeNode* node) -> int {
			if (!node) return 0;

			return f(node, targetSum) + f2(node->left) + f2(node->right);
		};


		return f2(root);
	}
	vector<int> output = {
		3,
		3
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{10,5,-3,3,2,NULL,11,3,-2,NULL,1},
		{5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1}
	};
	vector<int> input2 = {
		8,
		22
	};
};