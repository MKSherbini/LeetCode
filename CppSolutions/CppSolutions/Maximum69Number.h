#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-69-number/

class Maximum69Number
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 97.56%
	int solution(int num) {
		string s = to_string(num);

		for (size_t i = 0; i < size(s); i++) {
			if (s[i] == '6') {
				s[i] = '9';
				break;
			}
		}

		return stoi(s);
	}
	vector<int> output = {
		9969,
		9999,
		9999
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		9669,
		9996,
		9999
	};
};