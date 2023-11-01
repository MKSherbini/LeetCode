#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-mode-in-binary-search-tree/

class FindModeInBinarySearchTree
{
public:
	// 11 ms, faster than 90.7% : 29.9 MB, less than 5.42%
	vector<int> solution(TreeNode* root) {
		int mx = 0;
		unordered_map<int, int> freq;
		function<void(TreeNode*)> f = [&](TreeNode* node) -> void {
			if (!node) return;

			mx = max(mx, ++freq[node->val]);
			f(node->left), f(node->right);
		};
		f(root);

		vector<int> ans;
		for (auto& [x, cnt] : freq) {
			if (cnt == mx) {
				ans.push_back(x);
			}
		}

		return ans;
	}
	vector<vector<int>> output = {
		{2},
		{0}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,NULL,2,2},
		{0}
	};
};