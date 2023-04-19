#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

class LongestZigzagPathInABinaryTree
{
public:
	// 151 ms, faster than 97.21% : 94.1 MB, less than 85.89%
	int solution(TreeNode* root) {
		ff(root, 0, 0);
		return ans;
	}
	int ans = 0;
	void ff(TreeNode* node, bool dir, int c) {
		if (!node) return;

		ans = max(ans, c);
		if (dir)  ff(node->left, 0, c + 1), ff(node->right, 1, 1);
		if (!dir)  ff(node->right, 1, c + 1), ff(node->left, 0, 1);
	}
	// 460 ms, faster than 8.19% : 169.5 MB, less than 11.5%
	int solution2(TreeNode* root) {
		return f(root);
	}
	unordered_map<TreeNode*, vector<int>> mem;
	int f(TreeNode* node) {
		if (!node) return 0;

		int ret = f2(node, 0);
		ret = max(ret, f(node->left));
		ret = max(ret, f(node->right));

		return ret;
	}
	int f2(TreeNode* node, int dir) {
		if (!node) return 0;
		if (mem.count(node) && mem[node][dir + 1] != -1) return mem[node][dir + 1];

		int ret = 0;
		if (dir != -1 && node->left) ret = max(ret, f2(node->left, -1) + 1);
		if (dir != 1 && node->right) ret = max(ret, f2(node->right, 1) + 1);

		if (!mem.count(node)) mem[node] = vector<int>(3, -1);
		return mem[node][dir + 1] = ret;
	}
	vector<int> output = {
		3,
		4,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,NULL,1,1,1,NULL,NULL,1,1,NULL,1,NULL,NULL,NULL,1,NULL,1},
		{1,1,1,NULL,1,NULL,NULL,1,1,NULL,1},
		{1}
	};
};