#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/optimal-partition-of-string/

class OptimalPartitionOfString
{
public:
	// 15 ms, faster than 98.68% : 10.1 MB, less than 98.68%
	int solution(string s) {
		bitset<26> vis;
		int ans = 1;
		for (auto c : s) {
			if (vis.test(c - 'a')) {
				ans++;
				vis.reset();
			}
			vis.set(c - 'a');
			Printer::print(vis, ans);
		}
		return ans;
	}
	vector<int> output = {
		4,
		6
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"abacaba",
		"ssssss"
	};
};