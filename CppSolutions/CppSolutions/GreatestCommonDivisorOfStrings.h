#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/greatest-common-divisor-of-strings/

class GreatestCommonDivisorOfStrings
{
public:
	// 0 ms, faster than 100% : 6.5 MB, less than 99.82%
	string solution(string str1, string str2) {
		int n = size(str1), m = size(str2);

		for (int sz = m; sz >= 1; sz--) {
			if (n % sz || m % sz) continue;
			int j = 0, gd = 1;
			for (size_t i = 0; i < n; i++) {
				if (str1[i] != str2[j++]) {
					gd = 0;
					break;
				}
				if (j == sz) j = 0;
			}
			j = 0;
			for (size_t i = 0; i < m; i++) {
				if (str2[i] != str1[j++]) {
					gd = 0;
					break;
				}
				if (j == sz) j = 0;
			}
			if (gd) return str2.substr(0, sz);
		}
		return "";
	}
	vector<string> output = {
		"ABC",
		"AB",
		""
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"ABCABC",
		"ABABAB",
		"LEET"
	};
	vector<string> input2 = {
		"ABC",
		"ABAB",
		"CODE"
	};
};