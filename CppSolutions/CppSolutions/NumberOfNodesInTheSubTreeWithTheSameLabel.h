#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class NumberOfNodesInTheSubTreeWithTheSameLabel
{
public:
	// 1635 ms, faster than 13.34% : 166.6 MB, less than 94.07%
	vector<int> solution(int n, vector<vector<int>> edges, string labels) {
		ans.assign(n, 0);
		vector<vector<int>> mat(n);

		for (auto& e : edges)
			mat[e[0]].push_back(e[1]), mat[e[1]].push_back(e[0]);

		f(mat, labels, 0, -1);
		return ans;
	}
	vector<int> ans;
	unordered_map<char, vector<int>> gp;
	void f(vector<vector<int>>& mat, string& labels, int i, int p) {
		gp[labels[i]].push_back(i);
		for (auto c : gp[labels[i]])
			ans[c]++;
		for (auto j : mat[i])
			if (p != j)
				f(mat, labels, j, i);
		gp[labels[i]].pop_back();
	}
	
	// 1635 ms, faster than 13.34% : 166.6 MB, less than 94.07%
	vector<int> solution2(int n, vector<vector<int>> edges, string labels) {
		ans.assign(n, 0);
		vector<vector<int>> mat(n);

		for (auto& e : edges)
			mat[e[0]].push_back(e[1]), mat[e[1]].push_back(e[0]);

		f(mat, labels, 0, -1);
		return ans;
	}
	vector<int> ans;
	unordered_map<char, vector<int>> gp;
	void f(vector<vector<int>>& mat, string& labels, int i, int p) {
		gp[labels[i]].push_back(i);
		for (auto c : gp[labels[i]])
			ans[c]++;
		for (auto j : mat[i])
			if (p != j)
				f(mat, labels, j, i);
		gp[labels[i]].pop_back();
	}

	vector<vector<int>> output = {
		{2,1,1,1,1,1,1},
		{4,2,1,1},
		{3,2,1,1,1}
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		7,
		4,
		5
	};
	vector<vector<vector<int>>> input2 = {
		{{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}},
		{{0,1},{1,2},{0,3}},
		{{0,1},{0,2},{1,3},{0,4}}
	};
	vector<string> input3 = {
		"abaedcd",
		"bbbb",
		"aabab"
	};
};