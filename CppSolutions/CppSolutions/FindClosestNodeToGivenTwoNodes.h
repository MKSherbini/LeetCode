#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

class FindClosestNodeToGivenTwoNodes
{
public:
	// 132 ms, faster than 100% : 89.6 MB, less than 100%
	int solution(vector<int> edges, int node1, int node2) {
		while (edges[node1] >= 0 || edges[node2] >= 0) {
			if (edges[node1] >= 0) {
				auto t = node1;
				node1 = edges[node1];
				edges[t] = -11;
			}
			if (edges[node2] >= 0) {
				auto t = node2;
				node2 = edges[node2];
				edges[t] = -22;
			}
			if (edges[node1] == -22 && edges[node2] == -11) return min(node1, node2);
			if (edges[node1] == -22) return node1;
			if (edges[node2] == -11) return node2;
		}
		return node1 == node2 ? node1 : -1;
	}
	vector<int> output = {
		2,
		2
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{2,2,3,-1},
		{1,2,-1}
	};
	vector<int> input2 = {
		0,
		0
	};
	vector<int> input3 = {
		1,
		2
	};
};