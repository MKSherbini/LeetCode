#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sequential-digits/

class SequentialDigits
{
public:
	// 0 ms, faster than 100% : 7.2 MB, less than 13.81%
	vector<int> solution(int low, int high) {
		int mn = size(to_string(low)), mx = size(to_string(high));
		string s = "123456789";
		vector<int> ans;
		for (size_t len = mn; len <= mx; len++) {
			for (size_t i = 0; 9 - i >= len; i++) {
				int x = stoi(s.substr(i, len));
				if (x > high) goto end;
				if (x >= low) ans.push_back(x);
			}
		}
	end:
		return ans;
	}
	vector<vector<int>> output = {
		{123,234},
		{1234,2345,3456,4567,5678,6789,12345}
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		100,
		1000
	};
	vector<int> input2 = {
		300,
		13000
	};
};