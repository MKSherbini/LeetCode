#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/substring-with-largest-variance/

class SubstringWithLargestVariance
{
public:
	//
	int solution(string s) {
		uint8_t vis[26] = { 0 };
		for (size_t i = 0; i < s.size(); i++) vis[s[i] - 'a'] = 1;
		int ans = 0;
		for (char x = 'a'; x <= 'z'; x++)
		{
			for (char y = 'a'; y <= 'z'; y++)
			{
				if (x == y || !vis[x - 'a'] || !vis[y - 'a']) continue;
				int pre = 0, t = 0, t2 = 0, m = 99999;
				for (size_t i = 0; i < s.size(); i++)
				{
					if (s[i] == x) {
						++pre;
						t = 1;
						ans = max(ans, pre - 1);
					}
					else if (s[i] == y) {
						--pre;
						if (t == 1) t2 = 1;
					}
					if (t2)
						ans = max(ans, pre);
					if (pre < 0) pre = 0, t = 0, t2 = 0;
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