#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/ransom-note/

class RansomNote
{
public:
	// 12 ms, faster than 89.49% : 8.6 MB, less than 98.75%
	int solution(string ransomNote, string magazine) {
		vector<int> availableChars(26, 0);
		for (int i = 0; i < magazine.size(); i++)
			availableChars[magazine[i] - 'a']++;
		for (int i = 0; i < ransomNote.size(); i++) {
			availableChars[ransomNote[i] - 'a']--;
			if (availableChars[ransomNote[i] - 'a'] < 0) return false;
		}
		return true;
	}
	vector<int> output = {
		false,
		false,
		true,
		true,
		true,
	};
	vector<string> input1 = {
		"a",
		"aa",
		"aa",
		"aa",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

	};
	vector<string> input2 = {
		"b",
		"ab",
		"aab",
		"aba",
		"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
	};
};

