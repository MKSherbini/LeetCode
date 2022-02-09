#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/search-a-2d-matrix/

class SearchA2dMatrix
{
public:
	// 0 ms, faster than 100% : 9.3 MB, less than 95.49%
	bool solution(vector<vector<int>> matrix, int target) {
		int  x = matrix[0].size();
		int lo = 0, hi = x * matrix.size() - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;

			if (matrix[mid / x][mid % x] == target)
				return true;
			else if (matrix[mid / x][mid % x] > target)
				hi = mid - 1;
			else
				lo = mid + 1;
		}
		return false;
	}
	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,3,5,7},{10,11,16,20},{23,30,34,60}},
		{{1,3,5,7},{10,11,16,20},{23,30,34,60}},
		{{1}}
	};
	vector<int> input2 = {
		3,
		13,
		1
	};
};