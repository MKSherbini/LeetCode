#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/check-completeness-of-a-binary-tree/

class CheckCompletenessOfABinaryTree
{
public:
	// 0 ms, faster than 100% : 10.2 MB, less than 94.24%
	bool solution(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int c = size(q);

			bool noLeft = 0, lastLevel = !q.front()->left || !q.front()->left->left;
			while (c--) {
				auto cur = q.front();
				q.pop();

				if (!lastLevel && (!cur->left || !cur->right))
					return false;

				if (cur->left)
					if (noLeft)
						return false;
					else
						q.push(cur->left);
				noLeft = !cur->left;
				if (cur->right)
					if (noLeft)
						return false;
					else
						q.push(cur->right);
				noLeft = !cur->right;
			}
		}
		return true;
	}
	vector<bool> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4,5,6},
		{1,2,3,4,5,NULL,7}
	};
};