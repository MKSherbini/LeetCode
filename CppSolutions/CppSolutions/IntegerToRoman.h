#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/integer-to-roman/

class IntegerToRoman
{
public:
	// 19 ms, faster than 41.37% : 12.7 MB, less than 11.25%
	string solution(int num) {
		string ans = "";
		for (int one = 1; num; one *= 10)
		{
			int d = num % 10 * one;
			num /= 10;

			auto closest = romanMap.lower_bound(-d);
			if (closest == end(romanMap)) continue;

			Printer::print(num, d, closest->second, ans, one, romanMap[-one]);
			string n = closest->second;
			for (int i = -closest->first; i < d; i += one)
				n += romanMap[-one];

			ans = n + ans;
		}

		return ans;
	}
	map< int, string> romanMap{
		{-1, "I"},
		{-4, "IV"},
		{-5, "V"},
		{-9, "IX"},
		{-10, "X"},
		{-40, "XL"},
		{-50, "L"},
		{-90, "XC"},
		{-100, "C"},
		{-400, "CD"},
		{-500, "D"},
		{-900, "CM"},
		{-1000, "M"},
	};

	vector<string> output = {
		"III",
		"LVIII",
		"MCMXCIV"
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		3,
		58,
		1994
	};
};