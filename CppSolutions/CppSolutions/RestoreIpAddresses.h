#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/restore-ip-addresses/

class RestoreIpAddresses
{
public:
	// 0 ms, faster than 100% : 6.9 MB, less than 27.93%
	vector<string> solution(string s) {
		vector<string> ans;
		vector<string> groups;
		f(s, ans, groups, 0);
		return ans;
	}
	void f(string& s, vector<string>& ans, vector<string>& groups, int i) {
		if (i == size(s)) {
			if (size(groups) == 4) ans.push_back(groups[0] + "." + groups[1] + "." + groups[2] + "." + groups[3]);
			return;
		}
		if (15 - size(groups) * 3 < size(s) - i + 1) return;

		Printer::print(groups);
		if (!groups.empty() && groups.back()[0] != '0') {
			auto oldVal = groups.back();
			auto newVal = oldVal + s[i];
			if (stoi(newVal) <= 255) {
				groups.back() = newVal;
				f(s, ans, groups, i + 1);
				groups.back() = oldVal;
			}
		}

		if (size(groups) < 4) {
			groups.push_back(s.substr(i, 1));
			f(s, ans, groups, i + 1);
			groups.pop_back();
		}
	}
	vector<vector<string>> output = {
		{"255.255.11.135","255.255.111.35"},
		{"0.0.0.0"},
		{"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"}
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"25525511135",
		"0000",
		"101023"
	};
};