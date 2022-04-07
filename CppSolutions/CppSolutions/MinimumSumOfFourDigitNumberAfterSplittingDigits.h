#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class MinimumSumOfFourDigitNumberAfterSplittingDigits
{
public:
	// 0 ms, faster than 100% : 5.9 MB, less than 94.86%
	int solution(int num) {
		int arr[4];
		for (size_t i = 0; i < 4; i++)
			arr[i] = num % 10, num /= 10;
		sort(arr, arr + 4);
		return arr[0] * 10 + arr[1] * 10 + arr[2] + arr[3];
	}
	vector<int> output = {
		52,
		13
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		2932,
		4009
	};
};