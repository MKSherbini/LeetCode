#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class FlattenBinaryTreeToLinkedList
{
public:
	// 7 ms, faster than 81.17% : 12.5 MB, less than 96.54%
	void solution(TreeNode* root) {
		f(root);
		//cout << "d" << endl;
		//auto t = root;
		//while (t) {
		//	cout << t->val << endl;
		//	if (t->left) {
		//		cout << "d: " << t->left->val << endl;
		//		t->left = NULL;
		//	}
		//	t = t->right;
		//}
	}
	pair<TreeNode*, TreeNode*> f(TreeNode* node) {
		if (!node) return {};
		pair<TreeNode*, TreeNode*> l = f(node->left), r = f(node->right);
		node->left = NULL;

		if (l.first) {
			//cout << "l: " << l->val << endl;
			l.second->right = r.first;
			node->right = l.first;
			//if (r)
				//cout << "r: " << r->val << endl;
		}
		else {
			node->right = r.first;
		}
		//cout << "node: " << node->val << endl;


		if (r.first) return { node, r.second };
		if (l.first) return { node, l.second };
		return { node, node };
	}
	vector<vector<int>> output = {
		{1,NULL,2,NULL,3,NULL,4,NULL,5,NULL,6},
		{},
		{0}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,5,3,4,NULL,6},
		{},
		{0}
	};
};