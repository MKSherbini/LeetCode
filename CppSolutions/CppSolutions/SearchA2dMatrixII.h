#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/search-a-2d-matrix-ii/

class SearchA2dMatrixII
{
public:
	// 169 ms, faster than 52.55% : 14.7 MB, less than 98%
	bool solution(vector<vector<int>> matrix, int target) {
		int i = size(matrix) - 1, j = 0;

		while (i >= 0 && j < size(matrix[0]))
			if (matrix[i][j] == target) return true;
			else if (matrix[i][j] < target) j++;
			else i--;

		return false;
	}

	// 255 ms, faster than 23.67% : 14.7 MB, less than 88.55%
	bool solution2(vector<vector<int>> matrix, int target) {
		for (auto& v : matrix) {
			if (target < v[0] || target > v[size(v) - 1]) continue;
			auto it = lower_bound(begin(v), end(v), target);
			if (it != end(v) && *it == target) return true;
		}
		return false;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}},
		{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}
	};
	vector<int> input2 = {
		5,
		20
	};
};