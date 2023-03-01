#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-duplicate-subtrees/

class FindDuplicateSubtrees
{
public:
	// 19 ms, faster than 95.64% : 32.7 MB, less than 87.5%
	vector<TreeNode*> solution(TreeNode* root) {
		map<string, vector<TreeNode*>> m;

		f(root, m);
		vector<TreeNode*> ans;
		for (auto& [_, v] : m)
			if (size(v) > 1) ans.push_back(v[0]);

		return ans;
	}
	string f(TreeNode* node, map<string, vector<TreeNode*>>& m) {
		if (!node) return {};

		string ret = "(" + f(node->left, m) + to_string(node->val) + f(node->right, m) + ")";
		m[ret].push_back(node);
		Printer::print(ret);

		return ret;
	}
	vector<vector<vector<int>>> output = {
		{{2,4},{4}},
		{{1}},
		{{2,3},{3}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4,NULL,2,4,NULL,NULL,4},
		{2,1,1},
		{2,2,2,3,NULL,3,NULL}
	};
};