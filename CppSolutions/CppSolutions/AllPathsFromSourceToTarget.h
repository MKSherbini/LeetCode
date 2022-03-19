#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/all-paths-from-source-to-target/

class AllPathsFromSourceToTarget
{
public:
	// 20 ms, faster than 63.23% : 14 MB, less than 45.79%
	vector<vector<int>> solution(vector<vector<int>> graph) {
		vector<vector<int>> ans;
		curse(graph, ans, { 0 }, 0);
		return ans;
	}
	void curse(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> row, int i) {
		//Printer::printAll(i, "->", row);
		if (i == graph.size() - 1) return ans.push_back(row);

		for (int j = 0; j < graph[i].size(); j++)
		{
			row.push_back(graph[i][j]);
			curse(graph, ans, row, graph[i][j]);
			row.pop_back();
		}
	}
	vector<vector<vector<int>>> output = {
		{{0,1,3},{0,2,3}},
		{{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2},{3},{3},{}},
		{{4,3,1},{3,2,4},{3},{4},{}}
	};
};