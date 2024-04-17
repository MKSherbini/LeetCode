#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/smallest-string-starting-from-leaf/

class SmallestStringStartingFromLeaf
{
public:
	// 3 ms, faster than 98% : 18.4 MB, less than 94.56%
	string solution(TreeNode* root) {
		string row;
		string ans;
		function<bool(TreeNode*)> f = [&](TreeNode* node) -> bool {
			if (!node) return 0;
			row += node->val + 'a';
			auto l = f(node->left), r = f(node->right);
			if (!l && !r) {
				reverse(begin(row), end(row));
				if (empty(ans)) ans = row;
				else ans = min(ans, row);
				reverse(begin(row), end(row));
			}
			row.pop_back();

			return true;
			; };

		f(root);
		return ans;
	}
	vector<string> output = {
		"dba",
		"adz",
		"abc"
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{0,1,2,3,4,3,4},
		{25,1,3,1,3,0,2},
		{2,2,1,NULL,1,0,NULL,0}
	};
};