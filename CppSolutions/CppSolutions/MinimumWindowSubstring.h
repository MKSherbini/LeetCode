#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-window-substring/

class MinimumWindowSubstring
{
public:
	// 0 ms, faster than 100% : 7.5 MB, less than 98.12%
	string solution(string s, string t) {
		vector<int> vt(58, 0);
		int n = size(s);
		int ans = -1, len = n + 1;

		for (auto c : t)
			vt[c - 'A']++;

		int i = 0, j = 0, c = size(t);

		do {
			while (j < n && c > 0)
				if (vt[s[j++] - 'A']-- > 0)
					c--;

			if (c > 0) break;

			while (c == 0)
				if (vt[s[i++] - 'A']++ == 0)
					c++;

			Printer::print(i, j);

			if (j - i + 1 < len) {
				len = j - i + 1;
				ans = i - 1;
			}
		} while (j < n);

		return ans == -1 ? "" : s.substr(ans, len);
	}

	// 75 ms, faster than 20.82% : 7.6 MB, less than 94.27%
	string solution2(string s, string t) {
		vector<int> vt(58, 0), vs(58, 0);
		int n = size(s);
		int ans = -1, len = n + 1;

		for (auto c : t)
			vt[c - 'A']++;

		int i = 0, j = 0;

		do {
			while (j < n && !valid(vt, vs))
				vs[s[j++] - 'A']++;

			if (!valid(vt, vs)) break;

			while (valid(vt, vs))
				vs[s[i++] - 'A']--;

			Printer::print(i, j);

			if (j - i + 1 < len) {
				len = j - i + 1;
				ans = i - 1;
			}
		} while (j < n);

		return ans == -1 ? "" : s.substr(ans, len);
	}
	bool valid(vector<int>& vt, vector<int>& vs) {
		for (size_t i = 0; i < 58; i++)
			if (vt[i] > vs[i]) return false;
		return true;
	}

	vector<string> output = {
		"BANC",
		"a",
		""
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"ADOBECODEBANC",
		"a",
		"a"
	};
	vector<string> input2 = {
		"ABC",
		"a",
		"aa"
	};
};