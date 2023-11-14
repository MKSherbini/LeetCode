#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

class UniqueLength3PalindromicSubsequences
{
public:
	// 434 ms, faster than 39.5% : 13.4 MB, less than 65.98%
	int solution(string s) {
		int n = size(s);
		vector<unordered_set<char>> v(26);
		vector<bool> vis(26);
		vector<int> last(26);
		for (size_t i = 0; i < n; i++) {
			last[s[i] - 'a'] = i;
		}
		for (int i = 0; i < n; i++) {
			int ignore = -1;
			if (!vis[s[i] - 'a']) {
				vis[s[i] - 'a'] = 1;
				ignore = s[i] - 'a';
			}
			for (int j = 0; j < 26; j++) {
				if (last[j] <= i || !vis[j] || ignore == j) continue;
				v[j].insert(s[i]);
			}
		}
		int ans = 0;
		for (auto& st : v)
			ans += size(st);
		return ans;
	}
	vector<int> output = {
		3,
		0,
		4
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"aabca",
		"adc",
		"bbcbaba"
	};
};