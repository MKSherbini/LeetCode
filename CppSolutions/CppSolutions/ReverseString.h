#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reverse-string/

class ReverseString
{
public:
	// 21 ms	23.3 MB
	vector<char>& solution(vector<char>& s) {
		int sz = s.size();
		for (int i = 0; i < sz / 2; i++)
		{
			swap(s[i], s[sz - i - 1]);
		}
		return s;
	}
};

