#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/clone-graph/

class CloneGraph
{
public:
	// 3 ms, faster than 95.03% : 8.8 MB, less than 65.38%
	Node* solution(Node* node) {
		map<int, Node*> m;
		return f(node, NULL, m);
	}
	Node* f(Node* node, Node* p, map<int, Node*>& m) {
		if (!node) return NULL;

		if (m[node->val]) return m[node->val];
		Node* ret = m[node->val] = new Node(node->val);

		for (auto child : node->children) {
			ret->children.push_back(f(child, ret, m));
		}

		return ret;
	}
	vector<vector<vector<int>>> output = {
		{{2,4},{1,3},{2,4},{1,3}},
		{{}},
		{}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{2,4},{1,3},{2,4},{1,3}},
		{{}},
		{}
	};
};