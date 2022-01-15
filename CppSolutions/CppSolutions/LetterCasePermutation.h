#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/letter-case-permutation/

class LetterCasePermutation
{
public:
	// 0 ms, faster than 100.00% : 9.2 MB, less than 98.30%
	vector<string> solution(string s) {
		vector<string> ans;
		curse(s, ans, 0);
		return ans;
	}
	void curse(string& s, vector<string>& ans, int index) {
		cout << index << " " << s << endl;
		if (index >= s.size()) return ans.push_back(s);
		if (isdigit(s[index])) return curse(s, ans, index + 1);
		curse(s, ans, index + 1);
		toggleCase(s[index]);
		curse(s, ans, index + 1);
	}

	void toggleCase(char& c) {
		if (islower(c))
			c = toupper(c);
		else
			c = tolower(c);
	}

	vector<vector<string>> output = {
		{"a1b2","a1B2","A1b2","A1B2"},
		{"3z4","3Z4"},
	};
	vector<string> input1 = {
		"a1b2",
		"3z4",
	};
};

