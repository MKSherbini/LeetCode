#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

class ConvertSortedArrayToBinarySearchTree
{
public:
	// 10 ms, faster than 96.9% : 21.3 MB, less than 77.25%
	TreeNode* solution(vector<int> nums) {
		return f(nums, 0, size(nums) - 1);
	}
	TreeNode* f(vector<int>& nums, int st, int end) {
		if (st == end)return new TreeNode(nums[st]);
		if (st > end) return NULL;

		int i = st + (end - st) / 2;
		TreeNode* node = new TreeNode(nums[i]);

		node->left = f(nums, st, i - 1);
		node->right = f(nums, i + 1, end);

		return node;
	}

	vector<vector<int>> output = {
		{0,-3,9,-10,NULL,5},
		{3,1}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{-10,-3,0,5,9},
		{1,3}
	};
};