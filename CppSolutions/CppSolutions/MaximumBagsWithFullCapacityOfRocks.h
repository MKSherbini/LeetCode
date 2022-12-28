#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

class MaximumBagsWithFullCapacityOfRocks
{
public:
	// 179 ms, faster than 98.68% : 84.6 MB, less than 98.46%
	int solution(vector<int> capacity, vector<int> rocks, int additionalRocks) {
		int n = size(capacity);
		for (size_t i = 0; i < n; i++)
			capacity[i] -= rocks[i];

		sort(begin(capacity), end(capacity));

		int ans = 0;
		for (size_t i = 0; i < n; i++)
			if (capacity[i] == 0 || capacity[i] <= additionalRocks) ++ans, additionalRocks -= capacity[i];

		return ans;
	}
	vector<int> output = {
		3,
		3
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{2,3,4,5},
		{10,2,2}
	};
	vector<vector<int>> input2 = {
		{1,2,4,4},
		{2,2,0}
	};
	vector<int> input3 = {
		2,
		100
	};
};