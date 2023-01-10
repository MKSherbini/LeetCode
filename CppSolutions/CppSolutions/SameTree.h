#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/same-tree/

class SameTree
{
public:
	// 0 ms, faster than 100% : 9.9 MB, less than 95.24%
	bool solution(TreeNode* p, TreeNode* q) {
		return f(p, q);
	}
	bool f(TreeNode* p, TreeNode* q) {
		if (!p ^ !q) return false;
		if (!p) return true;

		return p->val == q->val && f(p->left, q->left) && f(p->right, q->right);
	}
	vector<bool> output = {
		true,
		false,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3},
		{1,2},
		{1,2,1}
	};
	vector<vector<int>> input2 = {
		{1,2,3},
		{1,NULL,2},
		{1,1,2}
	};
};