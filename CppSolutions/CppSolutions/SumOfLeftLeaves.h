#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sum-of-left-leaves/

class SumOfLeftLeaves
{
public:
	// 0 ms, faster than 100% : 14.7 MB, less than 81.87%
	int solution(TreeNode* root) {
		function<int(TreeNode*, bool)> f = [&](TreeNode* node, bool left) -> int {
			if (!node) return 0;
			if (left && !node->left && !node->right) return node->val;
			return f(node->left, 1) + f(node->right, 0);
			};

		return f(root, 0);
	}
	vector<int> output = {
		24,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,9,20,NULL,NULL,15,7},
		{1}
	};
};