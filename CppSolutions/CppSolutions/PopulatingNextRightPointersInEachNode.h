#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

// Definition for a Node.
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

class PopulatingNextRightPointersInEachNode
{
public:
	// 16 ms, faster than 89.53% : 17.1 MB, less than 37.00% 
	Node* solution(Node* root) {
		if (!root) return root;
		vector<Node*> v;
		vector<Node*> v2;
		int f = 0;
		v.push_back(root);

		while (true) {
			auto& cur = f == 0 ? v : v2;
			auto& other = f == 0 ? v2 : v;
			f = !f;
			other.clear();

			for (int i = 0; i < cur.size(); i++) {
				if (cur[0]->left) {
					other.push_back(cur[i]->left);
					other.push_back(cur[i]->right);
				}
				cur[i]->next = i == cur.size() - 1 ? NULL : cur[i + 1];
			}

			if (!cur[0]->left)break;
		}

		return root;
	}
};

