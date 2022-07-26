#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class LowestCommonAncestorOfABinaryTree
{
public:
	// 20 ms, faster than 73.61% : 17.3 MB, less than 11.09%
	TreeNode* solution(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path1;
		vector<TreeNode*> path2;
		f(root, p, path1);
		f(root, q, path2);
		int i = size(path1) - 1, j = size(path2) - 1;

		TreeNode* ans;
		while (i >= 0 && j >= 0 && path1[i--] == path2[j--])
			ans = path1[i], --i, --j;

		return ans;
	}
	bool f(TreeNode* node, TreeNode* target, vector<TreeNode*>& path) {
		if (!node) return false;

		if (node == target) {
			path.push_back(node);
			return true;
		}

		bool ret = false;
		ret |= f(node->left, target, path);
		if (!ret)
			ret |= f(node->right, target, path);

		if (ret)
			path.push_back(node);

		return ret;
	}
	vector<int> output = {
		3,
		5,
		1
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{3,5,1,6,2,0,8,NULL,NULL,7,4},
		{3,5,1,6,2,0,8,NULL,NULL,7,4},
		{1,2}
	};
	vector<int> input2 = {
		5,
		5,
		1
	};
	vector<int> input3 = {
		1,
		4,
		2
	};
};