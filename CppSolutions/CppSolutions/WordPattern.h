#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/word-pattern/

class WordPattern
{
public:
	// 0 ms, faster than 100% : 6.2 MB, less than 95.72%
	bool solution(string pattern, string s) {
		int i = 0, js = 0, je = 0;
		int n = size(pattern), m = size(s);
		unordered_map<int, pair<int, int>> mp;
		auto equalRange = [&](int c, int js, int je) {return (je - js == mp[c].second - mp[c].first)
			&& equal(begin(s) + js, begin(s) + je, begin(s) + mp[c].first); };

		while (i < n && (je = s.find(" ", js)) != -1) {
			Printer::print(s.substr(js, je - js));
			if (mp.count(pattern[i])) {
				if (!equalRange(pattern[i], js, je))
					return false;
			}
			else {
				for (auto& w : mp) {
					if (equalRange(w.first, js, je))
						return false;
				}
				mp[pattern[i]] = { js, je };
			}
			i++;
			js = je + 1;
		}
		Printer::print(s.substr(js, m - js));
		if (i + 1 != n) return false;
		if (mp.count(pattern[i])) {
			if (!equalRange(pattern[i], js, m))
				return false;
		}
		else {
			for (auto& w : mp) {
				if (equalRange(w.first, js, m))
					return false;
			}
		}
		return true;
	}
	vector<int> output = {
		true,
		false,
		false,
		true
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"abba",
		"abba",
		"aaaa",
		"abc"
	};
	vector<string> input2 = {
		"dog cat cat dog",
		"dog cat cat fish",
		"dog cat cat dog",
		"b c a",
	};
};