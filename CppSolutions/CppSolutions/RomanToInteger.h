#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/roman-to-integer/

class RomanToInteger
{
public:
	// 28 ms, faster than 19.48% : 16.3 MB, less than 5.03%
	int solution(string s) {
		unordered_map<string, int> romanMap{
			{"I", 1},
			{"IV", 4},
			{"V", 5},
			{"IX", 9},
			{"X", 10},
			{"XL", 40},
			{"L", 50},
			{"XC", 90},
			{"C", 100},
			{"CD", 400},
			{"D", 500},
			{"CM", 900},
			{"M", 1000},
		};
		int ret = 0;
		for (int i = 0; i < s.size(); i++)
			if ((i < s.size() - 1) &&
				romanMap[s.substr(i, 2)])
				ret += romanMap[s.substr(i, 2)], i++;
			else
				ret += romanMap[s.substr(i, 1)];
		return ret;
	}
	vector<int> output = {
		3,
		58,
		1994,
	};
	vector<string> input1 = {
		"III",
		"LVIII",
		"MCMXCIV",
	};
};

