#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/binary-tree-cameras/

class BinaryTreeCameras
{
public:
	// 9 ms, faster than 85.93% : 21.1 MB, less than 98.6%
	int solution(TreeNode* root) {
		int ans = 0;
		return !curse(root, ans) + ans;
	}

	// 2 camera
	int curse(TreeNode* root, int& ans) {
		if (!root) return 1;
		int l = curse(root->left, ans), r = curse(root->right, ans);
		if (l == 0 || r == 0)
			return ans++, 2;
		return (l == 2 || r == 2) ? 1 : 0;
	}

	//	int solution(TreeNode* root) {
	//	Printer::print(root);
	//	return min(curse(root, 2), curse(root, 1));
	//	//return curse(root, 1);
	//}

	//int curse(TreeNode* root, int c) {
	//	if (!root) return 0;
	//	int put = (c == 2);
	//	int nxt = (c + 1) % 3;
	//	if (c == 1 && !root->left && !root->right) put = 1;
	//	if(root->left && root->right)
	//	//Printer::print(c, nxt, put, root->val);
	//	return put + curse(root->left, nxt) + curse(root->right, nxt);
	//}

	vector<int> output = {
		1,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,NULL,3,4},
		{1,2,NULL,3,NULL,4,NULL,NULL,5}
	};
};