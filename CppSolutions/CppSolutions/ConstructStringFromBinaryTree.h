#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/construct-string-from-binary-tree/

class ConstructStringFromBinaryTree
{
public:
	// 10 ms, faster than 99.11% : 23.3 MB, less than 96.64%
	string solution(TreeNode* root) {
		string ans;
		f(root, ans);
		return ans;
	}
	void f(TreeNode* node, string& ans) {
		if (!node) return;

		ans += to_string(node->val);

		if (node->left || node->right) {
			ans += "(";
			f(node->left, ans);
			ans += ")";
		}

		if (node->right) {
			ans += "(";
			f(node->right, ans);
			ans += ")";
		}
	}
	// 32 ms, faster than 61.61% : 25.4 MB, less than 60.72%
	string solution2(TreeNode* root) {
		return f(root);
	}
	string f(TreeNode* node) {
		if (!node) return {};

		return to_string(node->val)
			+ (node->left || node->right ? "(" + f(node->left) + ")" : "")
			+ (node->right ? "(" + f(node->right) + ")" : "");
	}
	vector<string> output = {
		"1(2(4))(3)",
		"1(2()(4))(3)"
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{1,2,3,NULL,4}
	};
};