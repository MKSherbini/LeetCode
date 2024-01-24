#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/?envType=daily-question&envId=2024-01-24

class PseudoPalindromicPathsInABinaryTree
{
public:
	// 1692 ms, faster than 5.09% : 187.6 MB, less than 42.09%
	int solution(TreeNode* root) {
		int cnt = 0;
		function<int(TreeNode*)> f = [&](TreeNode* node) -> int {
			if (!node) return 0;

			int offset = 1 << node->val;
			cnt ^= offset;
			int ret = f(node->left) + f(node->right);
			if (!node->left && !node->right) {
				ret = (cnt & (cnt - 1)) == 0;
			}
			cnt ^= offset;

			return ret;
		};

		return f(root);
	}

	// 1717 ms, faster than 5.09% : 189.3 MB, less than 41.29%
	int solution2(TreeNode* root) {
		vector<int> cnt(9);
		function<int(TreeNode*)> f = [&](TreeNode* node) -> int {
			if (!node) return 0;

			cnt[node->val - 1]++;
			int ret = f(node->left) + f(node->right);
			if (!node->left && !node->right) {
				Printer::print(cnt);
				ret = count_if(begin(cnt), end(cnt), [](int c) {return c % 2; }) <= 1;
			}
			cnt[node->val - 1]--;

			return ret;
		};

		return f(root);
	}
	vector<int> output = {
		2,
		1,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,3,1,3,1,NULL,1},
		{2,1,1,1,3,NULL,NULL,NULL,NULL,NULL,1},
		{9}
	};
};