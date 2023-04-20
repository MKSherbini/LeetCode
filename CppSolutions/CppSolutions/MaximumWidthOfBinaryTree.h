#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-width-of-binary-tree/

class MaximumWidthOfBinaryTree
{
public:
	// 4 ms, faster than 95.06% : 17.8 MB, less than 7.3%
	int solution(TreeNode* root) {
		vector<uint64_t> mn;
		f(root, mn, 0, 1);
		return ans;
	}
	uint64_t ans = 0;
	void f(TreeNode* node, vector<uint64_t>& mn, int lvl, uint64_t index) {
		if (!node) return;

		if (size(mn) == lvl) mn.push_back(index);
		ans = max(ans, index - mn[lvl] + 1);

		f(node->left, mn, lvl + 1, index * 2);
		f(node->right, mn, lvl + 1, index * 2 + 1);
	}
	vector<int> output = {
		4,
		7,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,3,2,5,3,NULL,9},
		{1,3,2,5,NULL,NULL,9,6,NULL,7},
		{1,3,2,5}
	};
};