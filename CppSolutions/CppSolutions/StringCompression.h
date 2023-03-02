#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/string-compression/

class StringCompression
{
public:
	// 0 ms, faster than 100% : 9 MB, less than 82.85%
	int solution(vector<char> chars) {
		string ans;
		for (size_t i = 0; i < size(chars); i++) {

			size_t j = i + 1;
			for (; j < size(chars); j++) {
				if (chars[i] != chars[j])
					break;
			}
			ans += chars[i];
			if (j - i > 1) ans += to_string(j - i);
			i = j - 1;
		}
		chars = { begin(ans), end(ans) };
		Printer::print(chars);
		return size(chars);
	}
	vector<int> output = {
		6,
		1,
		4
	};
	static constexpr int const& inputs = 1;
	vector<vector<char>> input1 = {
		{'a','a','b','b','c','c','c'},
		{'a'},
		{'a','b','b','b','b','b','b','b','b','b','b','b','b'}
	};
};