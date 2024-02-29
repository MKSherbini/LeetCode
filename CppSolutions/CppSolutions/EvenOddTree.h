#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/even-odd-tree/

class EvenOddTree
{
public:
	// 170 ms, faster than 98.71% : 149 MB, less than 99.28%
	uint8_t solution(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);

		bool odd = 0;
		while (!q.empty()) {
			int c = size(q);
			int	last = odd ? INT_MAX : INT_MIN;
			while (c--) {
				auto cur = q.front();
				q.pop();

				if ((odd && (cur->val >= last || cur->val % 2 == 1)) ||
					(!odd && (cur->val <= last || cur->val % 2 == 0)))
					return false;
				last = cur->val;

				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			odd = !odd;
		}

		return true;
	}
	vector<uint8_t> output = {
		true,
		false,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,10,4,3,NULL,7,9,12,8,6,NULL,NULL,2},
		{5,4,2,3,3,7},
		{5,9,1,3,5,7}
	};
};