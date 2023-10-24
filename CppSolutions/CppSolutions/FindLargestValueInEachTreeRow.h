#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-largest-value-in-each-tree-row/

class FindLargestValueInEachTreeRow
{
public:
	// 7 ms, faster than 81.9% : 22.5 MB, less than 50.91%
	vector<int> solution(TreeNode* root) {
		vector<int> ans;
		function<void(TreeNode*, int)> f = [&](TreeNode* node, int lvl) -> void {
			if (!node) return;

			if (size(ans) == lvl) ans.push_back(node->val);
			else ans[lvl] = max(ans[lvl], node->val);

			lvl++;
			f(node->left, lvl), f(node->right, lvl);
		};
		f(root, 0);
		return ans;
	}
	vector<vector<int>> output = {
		{1,3,9},
		{1,3}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,3,2,5,3,NULL,9},
		{1,2,3}
	};
};