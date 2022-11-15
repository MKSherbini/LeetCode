#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-complete-tree-nodes/

class CountCompleteTreeNodes
{
public:
	// 22 ms, faster than 99.79% : 30.7 MB, less than 93.85%
	int solution(TreeNode* root) {
		if (!root) return 0;
		return 1 + solution(root->left) + solution(root->right);
	}
	vector<int> output = {
		6,
		0,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4,5,6},
		{},
		{1}
	};
};