#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/arithmetic-subarrays/?envType=daily-question&envId=2023-11-23

class ArithmeticSubarrays
{
public:
	// 32 ms, faster than 93.67% : 26.1 MB, less than 79.55%
	vector<uint8_t> solution(vector<int> nums, vector<int> l, vector<int> r) {
		int n = size(nums), m = size(l);
		vector<uint8_t> ans(m);
		for (size_t i = 0; i < m; i++) {
			int st = l[i], en = r[i];
			ans[i] = true;
			if (st == en) {
				continue;
			}
			vector t(begin(nums) + st, begin(nums) + en + 1);
			sort(begin(t), end(t));
			Printer::print(t);
			int d = t[1] - t[0];
			for (size_t j = 1; j < size(t); j++) {
				if (d != t[j] - t[j - 1]) {
					ans[i] = false;
					break;
				}
			}
		}

		return ans;
	}
	vector<vector<uint8_t>> output = {
		{true,false,true},
		{false,true,false,false,true,true}
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{4,6,5,9,3,7},
		{-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10}
	};
	vector<vector<int>> input2 = {
		{0,0,2},
		{0,1,6,4,8,7}
	};
	vector<vector<int>> input3 = {
		{2,3,5},
		{4,4,9,7,9,10}
	};
};