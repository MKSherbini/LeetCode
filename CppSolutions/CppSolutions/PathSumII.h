#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/path-sum-ii/

class PathSumII
{
public:
	// 4 ms, faster than 97.91% : 19.7 MB, less than 98.57%
	vector<vector<int>> solution(TreeNode* root, int targetSum) {
		vector<vector<int>> ans;
		vector<int> row;
		f(ans, root, row, targetSum);
		return ans;
	}
	void f(vector<vector<int>>& ans, TreeNode* node, vector<int>& row, int sum) {
		if (!node) return;
		sum -= node->val;
		row.push_back(node->val);

		if (!node->left && !node->right && sum == 0) ans.push_back(row);
		f(ans, node->left, row, sum);
		f(ans, node->right, row, sum);
		row.pop_back();
	}

	vector<vector<vector<int>>> output = {
		{{5,4,11,2},{5,8,4,5}},
		{},
		{}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1},
		{1,2,3},
		{1,2}
	};
	vector<int> input2 = {
		22,
		5,
		0
	};
};