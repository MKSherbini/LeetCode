#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/validate-binary-tree-nodes/

class ValidateBinaryTreeNodes
{
public:
	// 51 ms, faster than 46.5% : 42.9 MB, less than 28.27%
	bool solution(int n, vector<int> leftChild, vector<int> rightChild) {
		unordered_set<int> all;
		all.insert(begin(leftChild), end(leftChild));
		all.insert(begin(rightChild), end(rightChild));

		int root = -1;
		for (size_t i = 0; i < n; i++) {
			if (all.find(i) == end(all)) {
				root = i;
				break;
			}
		}
		if (root == -1) return false;

		vector<bool> vis(n);
		function<bool(int)> f = [&](int i) -> bool {
			if (i == -1) return true;
			if (i == n) return true;
			if (vis[i]) return false;
			vis[i] = 1;

			return f(leftChild[i]) && f(rightChild[i]);
		};
		if (!f(root)) return false;

		for (size_t i = 0; i < n; i++) {
			if (!vis[i] && (leftChild[i] != -1 || rightChild[i] != -1)) return false;
		}

		return true;
	}
	vector<bool> output = {
		true,
		false,
		false
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		4,
		4,
		2
	};
	vector<vector<int>> input2 = {
		{1,-1,3,-1},
		{1,-1,3,-1},
		{1,0}
	};
	vector<vector<int>> input3 = {
		{2,-1,-1,-1},
		{2,3,-1,-1},
		{-1,-1}
	};
};