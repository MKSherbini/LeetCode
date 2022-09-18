#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/palindrome-pairs/

class PalindromePairs
{
public:
	// 285 ms, faster than 100% : 106.6 MB, less than 66.32%
	vector<vector<int>> solution(vector<string> words) {
		vector<vector<int>> ans;
		unordered_map<string, int> m;
		set<int> s;
		for (size_t i = 0; i < size(words); i++)
			s.insert(size(words[i])), m[words[i]] = i;

		for (int i = 0; i < size(words); i++)
		{
			auto& w = words[i];
			auto n = size(words[i]);

			reverse(begin(w), end(w));
			auto it = m.find(w);
			if (it != end(m) && it->second != i) ans.push_back({ i, it->second });
			for (auto len : s) {
				if (len >= n) continue;

				if (isPalindrome(w, 0, n - 1 - len) && (it = m.find(w.substr(n - len))) != end(m))
					ans.push_back({ i, it->second });
				if (isPalindrome(w, len, n - 1) && (it = m.find(w.substr(0, len))) != end(m))
					ans.push_back({ it->second, i });
			}
		}
		return ans;
	}
	bool isPalindrome(string& s, int st, int end) {
		while (st < end && s[st] == s[end])
			st++, end--;

		return st >= end;
	}

	vector<vector<vector<int>>> output = {
		{{0,1},{1,0},{3,2},{2,4}},
		{{0,1},{1,0}},
		{{0,1},{1,0}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"abcd","dcba","lls","s","sssll"},
		{"bat","tab","cat"},
		{"a",""}
	};
};