#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/permutation-in-string/

class PermutationInString
{
public:
	// 4 ms, faster than 97.21% : 7.2 MB, less than 73.61%
	bool solution(string s1, string s2) {
		for (int i = 0; i < s1.size(); i++)
			target[s1[i] - 'a']++;

		for (int i = 0; i < s2.size(); i++)
		{
			int char1Idx = s2[i] - 'a', char2Idx = i - s1.size();
			found[char1Idx]++;
			if (char2Idx >= 0)
				found[s2[char2Idx] - 'a']--;
			if (found[char1Idx] == target[char1Idx] && (i + 1) >= s1.size() && isDone())
				return true;
		}
		return false;
	}
private:
	int target[26] = { 0 }, found[26] = { 0 };
	void resetFound() {
		memset(found, 0, sizeof(int) * 26);
	}
	bool isDone() {
		return equal(begin(target), end(target), begin(found));
	}
	void printFound() {
		for (int i = 0; i < 26; i++)
			if (found[i]) cout << char(i + 'a') << ": " << found[i] << ", ";
		cout << endl;
	}
};

