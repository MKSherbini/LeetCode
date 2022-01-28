#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reverse-vowels-of-a-string/

class ReverseVowelsOfAString
{
public:
	// 8 ms, faster than 72.07% : 8.1 MB, less than 27.93%
	string solution(string s) {
		string vowels = "aeiou";
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
			if (vowels.find(tolower(s[i])) != -1)
				st.push(s[i]);

		for (int i = 0; i < s.size(); i++)
			if (vowels.find(tolower(s[i])) != -1)
				s[i] = st.top(), st.pop();
		return s;
	}
	vector<string> output = {
		"holle",
		"leotcede",
		"Aa",
	};
	vector<string> input1 = {
		"hello",
		"leetcode",
		"aA",
	};
};

