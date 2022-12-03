#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sort-characters-by-frequency/

class SortCharactersByFrequency
{
public:
	// 4 ms, faster than 99.75% : 8.8 MB, less than 19.08%
	string solution(string s) {
		string ans;
		vector<int> f(75, 0);

		for (auto c : s)
			++f[c - '0'];

		set < pair<int, char>, greater<pair<int, char>>> m;
		for (size_t i = 0; i < 75; i++)
			m.insert({ f[i], '0' + i });

		for (auto p : m)
			ans += string(p.first, p.second);

		return ans;
	}
	vector<string> output = {
		"eetr",
		"cccaaa",
		"bbaA1"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"tree",
		"cccaaa",
		"Aabb1"
	};
};