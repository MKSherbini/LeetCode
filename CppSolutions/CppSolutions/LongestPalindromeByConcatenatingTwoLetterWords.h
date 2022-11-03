#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class LongestPalindromeByConcatenatingTwoLetterWords
{
public:
	// 278 ms, faster than 98.89% : 167.5 MB, less than 95.08%
	int solution(vector<string> words) {
		unordered_map<string, int> m;

		for (auto& w : words)
			m[w]++;
		Printer::print(m);
		int ans = 0, sames = 0;
		for (auto& p : m) {
			string o = p.first;
			reverse(begin(o), end(o));
			if (o == p.first) {
				sames = max(p.second & 1, sames);
				ans += p.second / 2;
				continue;
			}
			
			auto it = m.find(o);
			if (it == end(m)) continue;
			ans += min(it->second, p.second);
			it->second = 0;
		}
		Printer::print(ans, sames);
		return (ans << 2) + (sames << 1);
	}
	vector<int> output = {
		6,
		8,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"lc","cl","gg"},
		{"ab","ty","yt","lc","cl","ab"},
		{"cc","ll","xx"}
	};
};