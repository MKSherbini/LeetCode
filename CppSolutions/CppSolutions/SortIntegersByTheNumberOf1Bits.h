#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class SortIntegersByTheNumberOf1Bits
{
public:
	// 3 ms, faster than 96.5% : 10.3 MB, less than 86.9%
	vector<int> solution(vector<int> arr) {
		sort(begin(arr), end(arr), [](const int& x, const int& y) {
			auto xx = bitset<32>(x), yy = bitset<32>(y);
			return xx.count() == yy.count() ? x < y : xx.count() < yy.count();
			});
		return arr;
	}
	vector<vector<int>> output = {
		{0,1,2,4,8,3,5,6,7},
		{1,2,4,8,16,32,64,128,256,512,1024}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{0,1,2,3,4,5,6,7,8},
		{1024,512,256,128,64,32,16,8,4,2,1}
	};
};