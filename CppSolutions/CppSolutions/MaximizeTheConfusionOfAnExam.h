#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

class MaximizeTheConfusionOfAnExam
{
public:
	// 88 ms, faster than 16% : 9.9 MB, less than 95.41%
	int solution(string answerKey, int k) {
		int n = size(answerKey);
		unordered_map<char, int> tf;

		for (int i = 0; i < k; i++)
			tf[answerKey[i]]++;

		int ans = k;
		int l = 0;
		for (int r = k; r < n; r++) {
			tf[answerKey[r]]++;

			while (min(tf['T'], tf['F']) > k) {
				tf[answerKey[l]]--;
				l++;
			}

			ans = max(ans, r - l + 1);

		}

		return ans;
	}
	vector<int> output = {
		4,
		3,
		5
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"TTFF",
		"TFFT",
		"TTFTTFTT"
	};
	vector<int> input2 = {
		2,
		1,
		1
	};
};