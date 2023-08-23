#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reorganize-string/

class ReorganizeString
{
public:
	// 0 ms, faster than 100% : 6.2 MB, less than 76.79%
	string solution(string s) {
		int n = size(s);
		vector<int> f(26);
		for (auto c : s)
			f[c - 'a']++;

		priority_queue<pair<int, char>> pq;
		for (size_t i = 0; i < 26; i++) {
			if (f[i]) pq.push({ f[i], i + 'a' });
		}

		if (pq.top().first * 2 - 1 > n) return {};

		string ans;
		while (size(pq) > 1) {
			auto x = pq.top();
			pq.pop();
			auto y = pq.top();
			pq.pop();

			if (!empty(ans) && ans.back() == x.second) {
				ans += y.second;
				ans += x.second;
			}
			else {
				ans += x.second;
				ans += y.second;
			}

			x.first--, y.first--;
			if (x.first)
				pq.push(x);
			if (y.first)
				pq.push(y);
		}
		if (!empty(pq))
			ans += pq.top().second;

		return ans;
	}
	vector<string> output = {
		"aba",
		""
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"aab",
		"aaab"
	};
};