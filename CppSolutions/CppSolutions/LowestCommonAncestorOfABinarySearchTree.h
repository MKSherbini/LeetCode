#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class LowestCommonAncestorOfABinarySearchTree
{
public:
	// 26 ms, faster than 98.43% : 23.2 MB, less than 91.99%
	TreeNode* solution(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> path1;
		vector<TreeNode*> path2;
		f(root, p, path1);
		f(root, q, path2);
		int i = size(path1) - 1, j = size(path2) - 1;

		TreeNode* ans;
		while (i >= 0 && j >= 0 && path1[i] == path2[j]) {
			ans = path1[i], --i, --j;
		}

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
		6,
		2,
		2
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{6,2,8,0,4,7,9,NULL,NULL,3,5},
		{6,2,8,0,4,7,9,NULL,NULL,3,5},
		{2,1}
	};
	vector<int> input2 = {
		2,
		2,
		2
	};
	vector<int> input3 = {
		8,
		4,
		1
	};
};