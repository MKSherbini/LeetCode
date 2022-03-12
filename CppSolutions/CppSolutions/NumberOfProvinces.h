#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-provinces/

class NumberOfProvinces
{
public:
	// 12 ms, faster than 99.9% : 14 MB, less than 34.37%
	int solution(vector<vector<int>> isConnected) {
		int mx = 0;
		for (int i = 0; i < isConnected.size(); i++)
			for (int j = 0; j < isConnected[0].size(); j++)
				if (isConnected[i][j] == 1)
					mx++, sink(isConnected, i);


		return mx;
	}
	void sink(vector<vector<int>>& arr, int i) {
		for (int j = 0; j < arr.size(); j++) {
			if (arr[i][j]) {
				arr[i][j] = arr[j][i] = arr[j][j] = 0;
				if (i != j) sink(arr, j);
			}
		}
	}
	vector<int> output = {
		2,
		3,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,1,0},{1,1,0},{0,0,1}},
		{{1,0,0},{0,1,0},{0,0,1}},
		{{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}}
	};
};