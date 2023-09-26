#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-duplicate-letters/

class RemoveDuplicateLetters
{
public:
	// 0 ms, faster than 100% : 6.8 MB, less than 50.37%
	string solution(string s) {
		vector<int> f(26);
		for (auto c : s) f[c - 'a']++;

		vector<bool> vis(26);
		string ans;
		for (auto c : s) {
			Printer::print(vis[c - 'a'], ans);
			if (vis[c - 'a']) {
				f[c - 'a']--;
				continue;
			}

			while (!ans.empty() && ans.back() >= c && f[ans.back() - 'a'] > 1) {
				f[ans.back() - 'a']--;
				vis[ans.back() - 'a'] = 0;
				ans.pop_back();
			}

			ans.push_back(c);
			vis[c - 'a'] = 1;
		}

		return ans;
	}
	vector<string> output = {
		"abc",
		"acdb",
		"bac"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"bcabc",
		"cbacdcbc",
		"bbcaac"
	};
};