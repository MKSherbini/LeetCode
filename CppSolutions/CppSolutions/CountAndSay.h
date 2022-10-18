#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-and-say/

class CountAndSay
{
public:
	// 0 ms, faster than 100% : 6.3 MB, less than 98.97%
	string solution(int n) {
		string ans = "1";
		for (size_t i = 1; i < n; i++) {
			Printer::print("conv: ", i);
			ans = conv(ans);
		}

		return ans;
	}
	string conv(string& s) {
		string t = "";
		int n = size(s);

		for (size_t i = 0; i < n; i++) {
			Printer::print("i: ", i);
			if (i + 1 == n) {
				t += "1", t += s[i];
				Printer::print("t: ", t);
				break;
			}
			size_t j = i + 1;
			for (; j < n && s[i] == s[j]; j++);
			Printer::print("j: ", j);

			t += ((j - i) + '0'), t += s[i];
			i = j - 1;
			Printer::print("t: ", t);
		}

		return t;
	}
	vector<string> output = {
		"1",
		"1211"
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		1,
		4
	};
};