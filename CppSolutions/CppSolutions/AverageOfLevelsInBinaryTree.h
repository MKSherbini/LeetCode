#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/average-of-levels-in-binary-tree/

class AverageOfLevelsInBinaryTree
{
public:
	// 11 ms, faster than 98.2% : 22.4 MB, less than 72.83%
	vector<double> solution(TreeNode* root) {
		vector<double> ans;
		vector<int> cnt;
		f(root, ans, cnt, 0);
		for (size_t i = 0; i < size(ans); i++)
			ans[i] /= cnt[i];
		return ans;
	}
	void f(TreeNode* node, vector<double>& ans, vector<int>& cnt, int lvl) {
		if (!node) return;

		if (lvl == size(ans)) ans.push_back(node->val), cnt.push_back(1);
		else ans[lvl] += node->val, ++cnt[lvl];

		f(node->left, ans, cnt, lvl + 1);
		f(node->right, ans, cnt, lvl + 1);
	}
	vector<vector<double>> output = {
		{3.00000,14.50000,11.00000},
		{3.00000,14.50000,11.00000}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,9,20,NULL,NULL,15,7},
		{3,9,20,15,7}
	};
};