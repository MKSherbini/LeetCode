#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/add-binary/

class AddBinary
{
public:
	// 0 ms, faster than 100% : 6.1 MB, less than 96.98%
	string solution(string a, string b) {
		int i = size(a) - 1, j = size(b) - 1;
		bool c = 0;
		string res;
		while (i >= 0 && j >= 0) {
			if (a[i] == '1' && b[j] == '1')
				res += '0' + c, c = 1;
			else if (a[i] == '1' || b[j] == '1')
				res += '0' + !c;
			else
				res += '0' + c, c = 0;
			--i, --j;
		}
		while (i >= 0) {
			if (a[i] == '1')
				res += '0' + !c;
			else
				res += '0' + c, c = 0;
			--i;
		}
		while (j >= 0) {
			if (b[j] == '1')
				res += '0' + !c;
			else
				res += '0' + c, c = 0;
			--j;
		}
		if (c) res += '0' + c;
		reverse(begin(res), end(res));
		return res;
	}
	vector<string> output = {
		"100",
		"10101"
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"11",
		"1010"
	};
	vector<string> input2 = {
		"1",
		"1011"
	};
};