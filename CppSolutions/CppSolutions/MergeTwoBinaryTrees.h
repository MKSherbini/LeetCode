#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/merge-two-binary-trees/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

static void print(TreeNode* root) {
	cout << "[ ";
	dfsPrint(root);
	cout << " ]" << endl;
}

void dfsPrint(TreeNode* root) {
	if (root) cout << " " << root->val << " ,";
	else return;
	dfsPrint(root->left);
	dfsPrint(root->right);
}


class MergeTwoBinaryTrees
{
public:
	// 24 ms, faster than 98.83% : 32.2 MB, less than 98.87%
	TreeNode* solution(TreeNode* root1, TreeNode* root2) {
		if (!root1)return root2;
		if (!root2)return root1;
		dfsMerge(NULL, root1, root2, -1);
		return root1;
	}

private:
	void dfsMerge(TreeNode* parent1, TreeNode* root1, TreeNode* root2, char dir) {
		if (!root1 && !root2)return;
		if (root1 && root2) {
			root1->val += root2->val;
			dfsMerge(root1, root1->left, root2->left, 'L');
			dfsMerge(root1, root1->right, root2->right, 'R');
		}
		else if (!root1 && root2) {
			if (dir == 'L') {
				parent1->left = root2;
			}
			else {
				parent1->right = root2;
			}
		}
	}
};

