#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/naming-a-company/

class NamingACompany
{
public:
	// 449 ms, faster than 91.87% : 83.4 MB, less than 43.9%
	long long solution(vector<string> ideas) {
		vector<unordered_set<string>> m(26);

		for (auto& s : ideas)
			m[s[0] - 'a'].insert(s.substr(1));


		long long ans = 0;
		for (size_t i = 0; i < 26; i++) {
			if (m[i].empty()) continue;

			for (size_t j = i + 1; j < 26; j++) {
				if (m[j].empty()) continue;

				int bd = 0;
				for (auto& idea1 : m[i]) {
					if (m[j].count(idea1))
						bd++;
				}

				ans += (size(m[i]) - bd) * (size(m[j]) - bd) * 2;
			}
		}

		return ans;
	}
	vector<int> output = {
		6,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"coffee","donuts","time","toffee"},
		{"lack","back"}
	};
};