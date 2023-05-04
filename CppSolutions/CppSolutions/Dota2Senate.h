#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/dota2-senate/

class Dota2Senate
{
public:
	// 7 ms, faster than 74.43% : 7.9 MB, less than 52.67%
	string solution(string senate) {
		int n = size(senate);
		queue<int> d, r;
		for (size_t i = 0; i < n; i++)
			if (senate[i] == 'D') d.push(i);
			else r.push(i);

		while (!d.empty() && !r.empty()) {
			if (r.front() < d.front()) {
				d.pop();
				r.push(r.front() + n);
				r.pop();
			}
			else {
				r.pop();
				d.push(d.front() + n);
				d.pop();
			}
		}

		return d.empty() ? "Radiant" : "Dire";
	}

	vector<string> output = {
		"Radiant",
		"Dire",
		"Radiant",
		"Radiant"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"RD",
		"RDD",
		"RRDDD",
		"DRRDRDRDRDDRDRDR"
	};
};