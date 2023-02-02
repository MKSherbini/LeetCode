#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/verifying-an-alien-dictionary/

class VerifyingAnAlienDictionary
{
public:
	// 0 ms, faster than 100% : 9.5 MB, less than 63.85%
	bool solution(vector<string> words, string order) {
		unordered_map<char, int> m;
		for (size_t i = 0; i < 26; i++)
			m[order[i]] = i;

		auto cmp = [&m](const auto& x, const auto& y) {
			int i = 0, j = 0;

			while (i < size(x) && j < size(y) && x[i] == y[j])
				i++, j++;

			return i == size(x) || j == size(y) ? i == size(x) : m[x[i]] < m[y[i]];
		};

		for (size_t i = 1; i < size(words); i++) {
			if (!cmp(words[i - 1], words[i])) return false;
		}
		return true;
	}
	vector<int> output = {
		true,
		false,
		false
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"hello","leetcode"},
		{"word","world","row"},
		{"apple","app"}
	};
	vector<string> input2 = {
		"hlabcdefgijkmnopqrstuvwxyz",
		"worldabcefghijkmnpqstuvxyz",
		"abcdefghijklmnopqrstuvwxyz"
	};
};