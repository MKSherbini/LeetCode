#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-level-order-traversal/

class BinaryTreeLevelOrderTraversal
{
public:
	// 0 ms, faster than 100% : 12.2 MB, less than 99.96%
	vector<vector<int>> solution(TreeNode* root) {
		if (!root) return {};
		vector<vector<int>> ans;
		ans.push_back({ root->val });

		vector<TreeNode*> v;
		vector<TreeNode*> v2;

		int f = 0;
		v.push_back(root);

		int done = false;
		while (!done) {
			auto& cur = f == 0 ? v : v2;
			auto& other = f == 0 ? v2 : v;
			f = !f;
			other.clear();
			int ansI = size(ans);
			ans.push_back({});
			done = true;

			for (int i = 0; i < cur.size(); i++) {
				if (cur[i]->left)
					other.push_back(cur[i]->left), ans[ansI].push_back(cur[i]->left->val), done = false;
				if (cur[i]->right)
					other.push_back(cur[i]->right), ans[ansI].push_back(cur[i]->right->val), done = false;
			}

			if (done) {
				ans.pop_back();
				break;
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{3},{9,20},{15,7}},
		{{1}},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,9,20,NULL,NULL,15,7},
		{1},
		{}
	};
};