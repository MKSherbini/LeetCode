#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class BinaryTreeZigzagLevelOrderTraversal
{
public:
	// 0 ms, faster than 100% : 11.9 MB, less than 93.95%
	vector<vector<int>> solution(TreeNode* root) {
		if (!root) return {};
		queue<TreeNode*> q;
		vector<vector<int>> ans;
		bool lvl = 0;
		q.push(root);
		while (!q.empty()) {
			ans.push_back({});
			int cnt = size(q);
			while (cnt--) {
				auto c = q.front();
				q.pop();

				ans.back().push_back(c->val);
				if (c->right)
					q.push(c->right);
				if (c->left)
					q.push(c->left);
			}
			lvl = !lvl;
			if (lvl)
				reverse(ans.back().begin(), ans.back().end());
		}

		return ans;
	}
	// WA
	vector<vector<int>> solution2(TreeNode* root) {
		if (!root) return {};
		deque<TreeNode*> c1, c2;
		vector<vector<int>> ans;
		bool lvl = 0;
		c1.push_back(root);
		while (!c1.empty() || !c2.empty()) {
			auto& cur = lvl ? c2 : c1;
			auto& other = lvl ? c1 : c2;
			ans.push_back({});
			int cnt = size(cur);
			while (cnt--) {
				TreeNode* c;
				if (lvl) {
					c = cur.front();
					cur.pop_front();
				}
				else {
					c = cur.back();
					cur.pop_back();
				}
				ans.back().push_back(c->val);
				if (c->right)
					other.push_back(c->right);
				if (c->left)
					other.push_back(c->left);
			}

			lvl = !lvl;
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{3},{20,9},{15,7}},
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