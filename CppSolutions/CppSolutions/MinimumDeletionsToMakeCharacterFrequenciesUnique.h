#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class MinimumDeletionsToMakeCharacterFrequenciesUnique
{
public:
	// 74 ms, faster than 67.14% : 17.1 MB, less than 95.28%
	int solution(string s) {
		vector<int> freq(26, 0);

		for (size_t i = 0; i < size(s); i++)
			freq[s[i] - 'a']++;

		sort(begin(freq), end(freq), greater());

		Printer::print(freq);
		int ans = 0;
		for (size_t i = 1; i < 26 && freq[i] != 0; i++)
		{
			if (freq[i] < freq[i - 1]) continue;

			int t = max(freq[i - 1] - 1, 0);
			ans += freq[i] - t, freq[i] = t;
		}
		//vector<int> mem(26, -1);
		//int ans = curse(freq, mem, 1);
		Printer::print(freq);
		return ans;
	}

	int curse(vector<int>& freq, vector<int>& mem, int i) {
		if (i >= 26 || freq[i] <= 0) return 0;

		if (mem[i] != -1) return mem[i];

		if (freq[i] > freq[i - 1]) {
			int t = freq[i];
			freq[i] = max(freq[i - 1] - 1, 0);
			int ans = (t - freq[i]) + curse(freq, mem, i + 1);
			//freq[i] = t;
			Printer::print(i, freq[i]);
			return ans;
		}

		if (freq[i] != freq[i - 1])
			return curse(freq, mem, i + 1);


		freq[i]--;
		int ans = 1 + curse(freq, mem, i + 1);
		//freq[i]++;
		Printer::print(i, 1);


		return ans;
	}
	vector<int> output = {
		0,
		2,
		2,
		5,
		276
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"aab",
		"aaabbbcc",
		"ceabaacb",
		"ceabaacbzzz",
		"abcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwz"
	};
};