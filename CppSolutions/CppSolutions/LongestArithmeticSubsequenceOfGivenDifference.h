#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class LongestArithmeticSubsequenceOfGivenDifference
{
public:
	// 142 ms, faster than 93.46% : 54.7 MB, less than 92.6%
	int solution(vector<int> arr, int difference) {
		unordered_map<int, int> scores;

		int ans = 0;
		for (int i = size(arr) - 1; i >= 0; i--) {
			int score = 1;
			if (scores.count(arr[i] + difference))
				score += scores[arr[i] + difference];
			scores[arr[i]] = score;
			ans = max(ans, score);
		}

		return ans;
	}
	vector<int> output = {
		4,
		1,
		4
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{1,3,5,7},
		{1,5,7,8,5,3,4,2,1}
	};
	vector<int> input2 = {
		1,
		1,
		-2
	};
};