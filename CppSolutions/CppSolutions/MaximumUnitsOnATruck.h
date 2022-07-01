#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-units-on-a-truck/

class MaximumUnitsOnATruck
{
public:
	// 48 ms, faster than 86.07% : 15.9 MB, less than 95.14%
	int solution(vector<vector<int>> boxTypes, int truckSize) {
		sort(begin(boxTypes), end(boxTypes), [](auto& x, auto& y) { return x[1] > y[1]; });

		Printer::print(boxTypes);
		int ans = 0;
		for (size_t i = 0; i < size(boxTypes); i++)
		{
			if (truckSize < boxTypes[i][0]) {
				ans += truckSize * boxTypes[i][1];
				break;
			}
			ans += boxTypes[i][0] * boxTypes[i][1];
			truckSize -= boxTypes[i][0];
		}
		return ans;
	}
	vector<int> output = {
		8,
		91
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,3},{2,2},{3,1}},
		{{5,10},{2,5},{4,7},{3,9}}
	};
	vector<int> input2 = {
		4,
		10
	};
};