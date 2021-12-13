#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/flood-fill/

class FloodFill
{
public:
	// 4 ms, faster than 97.64% : 13.8 MB, less than 99.23%
	vector<vector<int>> solution(vector<vector<int>>& arr, int i, int j, int c) {
		if (arr[i][j] != c)
			ffill(arr, i, j, c, arr[i][j]);
		return  arr;
	}

private:
	void ffill(vector<vector<int>>& arr, int i, int j, int c, int t) {
		if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] != t)
			return;

		arr[i][j] = c;

		ffill(arr, i + 1, j, c, t);
		ffill(arr, i - 1, j, c, t);
		ffill(arr, i, j + 1, c, t);
		ffill(arr, i, j - 1, c, t);
	}
};

