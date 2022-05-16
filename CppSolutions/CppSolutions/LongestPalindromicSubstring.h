#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-palindromic-substring/

class LongestPalindromicSubstring
{
public:
	// 21 ms, faster than 87.69% : 6.9 MB, less than 99.83%
	string solution(string s) {
		int st = 0, limit = 1;
		for (size_t i = 0; i < s.size(); i++)
		{
			int lo = i - 1;
			int hi = i + 1;

			while (lo >= 0 && s[i] == s[lo])
				lo--;
			while (hi < s.size() && s[i] == s[hi])
				hi++;

			while (lo >= 0 && hi < s.size() && s[lo] == s[hi])
				hi++, lo--;

			if (limit < hi - lo - 1)
				st = lo + 1, limit = hi - lo - 1;
		}
		return s.substr(st, limit);
	}

	// 2341 ms, faster than 5.01% : 387.3 MB, less than 5.03%
	string solution2(string s) {
		vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
		pair<int, int> ans;
		int mx = 0;
		curse2(s, mem, mx, ans, 0, s.size() - 1);
		Printer::print(mem);
		return s.substr(ans.first, ans.second - ans.first + 1);
	}
	int curse2(string& s, vector<vector<int>>& mem, int& mx, pair<int, int>& ans, int i, int j) {
		if (i > j) return 0;
		if (i == j) return mem[i][j] = 1;
		if (mem[i][j] != -1) return mem[i][j];
		curse2(s, mem, mx, ans, i, j - 1);
		curse2(s, mem, mx, ans, i + 1, j);
		int ret = 0;
		if (s[i] == s[j])
			ret = 2 + curse2(s, mem, mx, ans, i + 1, j - 1);
		else ret = -OO;
		if (ret > mx)
			mx = ret, ans = { i,j };
		return mem[i][j] = ret;
	}
	const int OO = (int)1e8;

	vector<string> output = {
		"bab",
		"bab",
		"bb",
		"baaab",
		"a",
		"aca"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"babad",
		"babadbabad",
		"cbbd",
		"cxbaaabd",
		"a",
		"aacabdkacaa"
	};
};