#pragma once
#include "stdc++.h"
using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class TreeSupport
{
public:
	static TreeNode* create(vector<int> v) {
		TreeNode* root = NULL;
		fillTree(v, &root, 0);
		return root;
	}
private:
	static void fillTree(vector<int>& v, TreeNode** node, int i) {
		if (i >= v.size() || !v[i]) return;

		*node = new TreeNode(v[i]);
		fillTree(v, &((*node)->left), i * 2 + 1);
		fillTree(v, &((*node)->right), i * 2 + 2);
	}

};

