#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class ConstructBinaryTreeFromPreorderAndInorderTraversal
{
public:
	// 26 ms, faster than 72.15% : 26.1 MB, less than 60.75%
	TreeNode* solution(vector<int> preorder, vector<int> inorder) {
		return f(preorder, 0, begin(inorder), end(inorder));
	}

	TreeNode* f(vector<int>& preorder, int i, vector<int>::iterator st, vector<int>::iterator end) {
		if (st == end || i == size(preorder)) return NULL;
		auto it = find(st, end, preorder[i]);
		if (it == end) return f(preorder, i + 1, st, end);

		return new TreeNode(*it, f(preorder, i + 1, st, it), f(preorder, i + 1, it + 1, end));
	}

	vector<vector<int>> output = {
		{3,9,20,NULL,NULL,15,7},
		{-1}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{3,9,20,15,7},
		{-1}
	};
	vector<vector<int>> input2 = {
		{9,3,15,20,7},
		{-1}
	};
};