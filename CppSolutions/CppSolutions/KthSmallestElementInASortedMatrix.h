#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class KthSmallestElementInASortedMatrix
{
public:
	// 49 ms, faster than 61% : 13.1 MB, less than 92.86%
	int solution(vector<vector<int>> matrix, int k) {
		int n = size(matrix);
		priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> p; // lowest per level
		for (size_t i = 0; i < n; i++)
			p.push({ matrix[i][0], i, 0 });

		int ans = get<0>(p.top());
		while (--k >= 0)
		{
			Printer::print(p);
			int lvl = get<1>(p.top());
			int idx = get<2>(p.top()) + 1;
			ans = get<0>(p.top());
			p.pop();
			if (idx < n)
				p.push({ matrix[lvl][idx], lvl, idx });
		}

		return ans;
	}
	vector<int> output = {
		1,
		-5
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,2,9},{1,11,13},{12,13,15}},
		{{-5}}
	};
	vector<int> input2 = {
		2,
		1
	};
};