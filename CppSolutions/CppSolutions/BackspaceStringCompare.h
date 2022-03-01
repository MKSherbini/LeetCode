#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/backspace-string-compare/

class BackspaceStringCompare
{
public:
	// 0 ms, faster than 100% : 6.5 MB, less than 24.45%
	int solution(string s, string t) {
		int i = s.size() - 1, j = t.size() - 1, lastCheck = 1;
		do {
			i = nextValidChar(s, i);
			j = nextValidChar(t, j);
		} while (i >= 0 && j >= 0 && (lastCheck = (s[i--] == t[j--])));

		return lastCheck && i == j && j <= 0;
	}
	int nextValidChar(string s, int i) {
		int charsToRemove = 0;
		while (i >= 0 && !(s[i] != '#' && !charsToRemove))
			if (s[i] == '#')
				i--, charsToRemove++;
			else
				i--, charsToRemove--;
		return i;
	}
	vector<int> output = {
		true,
		true,
		false,
		true,
		false,
		false,
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"ab#c",
		"ab##",
		"a#c",
		"",
		"bxj##tw",
		"abc#"
	};
	vector<string> input2 = {
		"ad#c",
		"c#d#",
		"b",
		"##xx###",
		"bxj###tw",
		"bac#"
	};
};