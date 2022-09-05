#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class NAryTreeLevelOrderTraversal
{
public:
	// 23 ms, faster than 92.65% : 11.4 MB, less than 99.18%
	vector<vector<int>> solution(Node* root) {
		if (!root) return {};

		vector<vector<int>> ans;
		queue<Node*> q;

		q.push(root);

		while (!q.empty())
		{
			int lvl = size(q);
			ans.push_back({});

			while (lvl--) {
				auto cur = q.front();
				q.pop();

				ans.back().push_back(cur->val);
				for (auto child : cur->children)
					q.push(child);
			}
		}

		return ans;
	}

	// 23 ms, faster than 92.65% : 11.6 MB, less than 86.69%
	vector<vector<int>> solution2(Node* root) {
		vector<vector<int>> ans;
		f(root, ans, 0);
		return ans;
	}
	void f(Node* node, vector<vector<int>>& ans, int lvl) {
		if (!node) return;

		if (lvl == size(ans)) ans.push_back({ node->val });
		else ans[lvl].push_back(node->val);

		for (auto child : node->children)
			f(child, ans, lvl + 1);
	}
	vector<vector<vector<int>>> output = {
		{{1},{3,2,4},{5,6}},
		{{1},{2,3,4,5},{6,7,8,9,10},{11,12,13},{14}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,NULL,3,2,4,NULL,5,6},
		{1,NULL,2,3,4,5,NULL,NULL,6,7,NULL,8,NULL,9,10,NULL,NULL,11,NULL,12,NULL,13,NULL,NULL,14}
	};
};