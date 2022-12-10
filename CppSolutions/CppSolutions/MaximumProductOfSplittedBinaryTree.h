#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

class MaximumProductOfSplittedBinaryTree
{
public:
	// 125 ms, faster than 99.44% : 77.9 MB, less than 60.67%
	int solution(TreeNode* root) {
		long long ans = INT_MIN;
		int total = s(root);
		f(root, total, ans);
		return ans % MOD;
	}
	int f(TreeNode* node, int total, long long& ans) {
		if (!node) return 0;

		int l = f(node->left, total, ans), r = f(node->right, total, ans);
		ans = max(ans, 1LL * l * (total - l));
		ans = max(ans, 1LL * r * (total - r));

		return node->val + l + r;
	}
	int s(TreeNode* node) {
		if (!node) return 0;
		return node->val + s(node->left) + s(node->right);
	}
	const int MOD = 1e9 + 7;

	vector<int> output = {
		110,
		90
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4,5,6},
		{1,NULL,2,3,4,NULL,NULL,5,6}
	};
};