#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class AllNodesDistanceKInBinaryTree
{
public:
	// 0 ms, faster than 100% : 9.4 MB, less than 99.86%
	vector<int> solution(TreeNode* root, TreeNode* target, int k) {
		vector<TreeNode*> lvl;

		function<bool(TreeNode*, int)> f = [&](TreeNode* node, int d) -> bool {
			if (!node) return false;

			if (target == node) {
				lvl.resize(d + 1);
				lvl[d] = node;
				return true;
			}

			int l = f(node->left, d + 1), r = f(node->right, d + 1);
			if (l || r) {
				lvl[d] = node;
				if (l) node->left = NULL;
				else node->right = NULL;
			}

			return l || r;
		};
		f(root, 0);

		vector<int> ans;
		function<void(TreeNode*, int)> ff = [&](TreeNode* node, int d) -> void {
			if (!node) return;

			Printer::print(node->val, d);
			if (k == d) {
				ans.push_back(node->val);
				return;
			}

			ff(node->left, d + 1), ff(node->right, d + 1);
		};

		reverse(begin(lvl), end(lvl));
		int limit = min((int)size(lvl), k + 1);

		for (size_t i = 0; i < limit; i++) {
			ff(lvl[i], i);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{7,4,1},
		{}
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{3,5,1,6,2,0,8,NULL,NULL,7,4},
		{1}
	};
	vector<int> input2 = {
		5,
		1
	};
	vector<int> input3 = {
		2,
		3
	};
};