#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-depth-of-binary-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class MaximumDepthOfBinaryTree
{
public:
	// 4 ms, faster than 92.93% : 18.8 MB, less than 89.06%
	int solution(TreeNode* root) {
		if (!root) return 0;
		return 1 + max(solution(root->left), solution(root->right));
	}
};

