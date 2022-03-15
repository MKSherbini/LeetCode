#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/subtree-of-another-tree/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SubtreeOfAnotherTree
{
public:
	// 16 ms, faster than 97.84% : 28.7 MB, less than 96.37%
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (!root || !subRoot) return 0;

		int equal = 0;
		if (root->val == subRoot->val)
			equal |= compare(root, subRoot);
		if (equal) return 1;
		equal |= isSubtree(root->left, subRoot);
		if (equal) return 1;
		equal |= isSubtree(root->right, subRoot);
		return equal;
	}

	bool compare(TreeNode* root, TreeNode* subRoot) {
		if (root == NULL && subRoot == NULL) return 1;
		if (root == NULL || subRoot == NULL) return 0;

		bool equal = root->val == subRoot->val;
		if (!equal) return 0;
		equal &= compare(root->left, subRoot->left);
		if (!equal) return 0;
		equal &= compare(root->right, subRoot->right);
		return equal;
	}
};