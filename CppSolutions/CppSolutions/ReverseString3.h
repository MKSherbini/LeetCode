#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reverse-words-in-a-string-iii/

class ReverseString3
{
public:
	// 14 ms	9.5 MB
	string solution(string s) {
		int sz = s.size(), j = -1;
		for (int i = 0; i < sz; i++)
			if (s[i] == ' ' && i > 0 && s[i - 1] != ' ')
				reverse(begin(s) + j, begin(s) + i), j = -1;
			else if (s[i] != ' ' && j == -1) j = i;
		if (j != -1)
			reverse(begin(s) + j, begin(s) + sz);
		return s;
	}
};

