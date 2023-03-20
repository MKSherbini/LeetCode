#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/can-place-flowers/

class CanPlaceFlowers
{
public:
	// 12 ms, faster than 93.73% : 20.1 MB, less than 92.39%
	bool solution(vector<int> flowerbed, int n) {
		int sz = size(flowerbed);
		for (int i = 0; i < sz; i++) {
			if (!flowerbed[i] && (i == 0 || !flowerbed[i - 1]) && (i == sz - 1 || !flowerbed[i + 1]))
				n--, flowerbed[i] = 1;
			if (n <= 0) return 1;
		}

		return n <= 0;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,0,0,0,1},
		{1,0,0,0,1}
	};
	vector<int> input2 = {
		1,
		2
	};
};