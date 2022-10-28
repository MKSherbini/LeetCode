#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/group-anagrams/

class GroupAnagrams
{
public:
	// 31 ms, faster than 98.31% : 23.6 MB, less than 18.36%
	vector<vector<string>> solution(vector<string> strs) {
		unordered_map<string, vector<string>> m;

		for (int i = 0; i < size(strs); i++) {
			vector<int> v(26, 0);

			for (auto c : strs[i])
				v[c - 'a']++;

			string key = "";
			for (size_t i = 0; i < size(v); i++) 
				if (v[i]) key += 'a' + i, key += v[i];

			m[key].push_back(strs[i]);
		}

		vector<vector<string>> ans;

		for (auto p : m)
			ans.push_back(move(p.second));

		return ans;
	}
	vector<vector<vector<string>>> output = {
		{{"bat"},{"nat","tan"},{"ate","eat","tea"}},
		{{""}},
		{{"a"}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"eat","tea","tan","ate","nat","bat"},
		{""},
		{"a"}
	};
};