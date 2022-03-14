#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class PopulatingNextRightPointersInEachNodeIi
{
public:
	// 8 ms, faster than 98.08% : 17.4 MB, less than 81.79%
	Node* solution(Node* root) {
		if (!root) return root;
		vector<Node*> v;
		vector<Node*> v2;
		int f = 0;
		v.push_back(root);
		int done = 0;
		while (!done) {
			done = 1;
			auto& cur = f == 0 ? v : v2;
			auto& other = f == 0 ? v2 : v;
			f = !f;
			other.clear();

			for (int i = 0; i < cur.size(); i++) {
				if (cur[i]->left)
					other.push_back(cur[i]->left), done = 0;
				if (cur[i]->right)
					other.push_back(cur[i]->right), done = 0;
				cur[i]->next = i == cur.size() - 1 ? NULL : cur[i + 1];
			}
		}

		return root;
	}
};