#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/substring-with-largest-variance/

class SubstringWithLargestVariance
{
public:
	// 138 ms, faster than 92.28% : 6.8 MB, less than 96.05%
	int solution(string s) {
		uint8_t vis[26] = { 0 };
		for (size_t i = 0; i < s.size(); i++) vis[s[i] - 'a'] = 1;
		int ans = 0;
		for (char x = 'a'; x <= 'z'; x++)
		{
			if (!vis[x - 'a']) continue;
			for (char y = 'a'; y <= 'z'; y++)
			{
				if (x == y || !vis[y - 'a']) continue;
				int pre = 0, t = 0;
				for (size_t i = 0; i < s.size(); i++)
				{
					if (s[i] == x) {
						++pre;
						ans = max(ans, pre - 1);
					}
					else if (s[i] == y) {
						--pre;
						t = 1;
					}
					if (t)
						ans = max(ans, pre);
					if (pre < 0) pre = 0, t = 0;
				}
			}
		}
		return ans;
	}
	vector<int> output = {
		3,
		0,
		0,
		1
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"aababbba",
		"abcde",
		"aaaaa",
		"lripaa"
	};
};