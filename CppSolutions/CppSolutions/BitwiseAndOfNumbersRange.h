#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/bitwise-and-of-numbers-range/

class BitwiseAndOfNumbersRange
{
public:
	// 0 ms, faster than 100% : 8.7 MB, less than 55.9%
	int solution(int left, int right) {
		int cnt = 0;

		//find the common prefix
		while (left != right) {
			cnt++;
			left = left >> 1;
			right = right >> 1;
		}

		return right << cnt;
	}

	// 4 ms, faster than 94.92% : 5.7 MB, less than 96.09%
	int solution2(int left, int right) {
		int diff = right - left;
		int ret = right & left;

		int i = 1;
		while (diff) {
			ret &= ~i;
			diff &= ~i;
			i <<= 1;
		}
		return ret;
	}
	vector<int> output = {
		4,
		0,
		0
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		5,
		0,
		1
	};
	vector<int> input2 = {
		7,
		0,
		2147483647
	};
};