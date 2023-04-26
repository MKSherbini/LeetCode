#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/add-digits/

class AddDigits
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 92.24%
	int solution(int num) {
		if (num <= 9) return num;
		int ret = 0;
		while (num){
			ret += num % 10;
			num /= 10;
		}
		return solution(ret);
	}
	// 0 ms, faster than 100% : 5.9 MB, less than 92.24%
	int solution2(int num) {
		if (num == 0) return 0;
		if (num % 9 == 0) return 9;
		return num % 9;
	}
	vector<int> output = {
		2,
		0
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		38,
		0
	};
};