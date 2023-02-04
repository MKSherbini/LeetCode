#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/permutation-in-string/

class PermutationInString
{
public:
	// 0 ms, faster than 100% : 7.1 MB, less than 98.93%
	bool solution(string s1, string s2) {
		vector<int> target(26);
		for (int i = 0; i < size(s1); i++)
			target[s1[i] - 'a']++;

		int n = size(s1), chars = n, st = 0;
		for (int i = 0; i < size(s2); i++) {
			int charIdx = s2[i] - 'a';

			if (target[charIdx] > 0)
				--target[charIdx], --chars;
			else {
				while (st <= i) {
					if (s2[st] == s2[i]) {
						++st;
						break;
					}
					++target[s2[st] - 'a'], ++chars, ++st;
				}
			}

			Printer::print(i, chars);
			if (chars == 0) return true;
		}

		return false;
	}

	// 4 ms, faster than 97.21% : 7.2 MB, less than 73.61%
	bool solution2(string s1, string s2) {
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

	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"ab",
		"ab"
	};
	vector<string> input2 = {
		"aidbaooo",
		"eidboaoo"
	};
};

