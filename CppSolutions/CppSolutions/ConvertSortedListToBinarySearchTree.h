#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

class ConvertSortedListToBinarySearchTree
{
public:
	// leetcode???
	TreeNode* solution(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return new TreeNode(head->val);
		auto it = head, it2 = head->next;

		auto root = new TreeNode(head->val);
		auto rit = root;

		while (it2) {
			it2 = it2->next;
			if (it2)
				it2 = it2->next;
			it = it->next;
			if (it2) {
				rit->right = new TreeNode(it->val);
				rit = rit->right;
			}

		}

		auto root2 = new TreeNode(it->val);
		rit = root2;

		while (it) {
			it = it->next;
			if (it) {
				rit->right = new TreeNode(it->val);
				rit = rit->right;
			}
		}

		root2->left = root;
		return root2;
	}
	vector<vector<int>> output = {
		{0,-3,9,-10,NULL,5},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{-10,-3,0,5,9},
		{}
	};
};