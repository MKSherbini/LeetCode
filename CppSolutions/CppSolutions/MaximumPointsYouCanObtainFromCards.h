#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class MaximumPointsYouCanObtainFromCards
{
public:
	// 63 ms, faster than 93.08% : 42.3 MB, less than 80.56%
	int solution(vector<int> cardPoints, int k) {
		int post = 0;
		for (int i = size(cardPoints) - k; i < size(cardPoints); i++)
			post += cardPoints[i];

		int mx = post;

		int pre = 0;
		for (size_t i = 0; i < k; i++)
			pre += cardPoints[i], post -= cardPoints[size(cardPoints) - k + i],
			mx = max(mx, pre + post);
		return mx;
	}

	// 67 ms, faster than 87.83% : 44.1 MB, less than 20.2%
	int solution2(vector<int> cardPoints, int k) {
		vector<int> post(cardPoints);
		for (int i = size(cardPoints) - 2; i >= 0; i--)
			post[i] += post[i + 1];

		int mx = max(post[0] - post[k - 1] + cardPoints[k - 1], post[size(cardPoints) - k]);

		int sum = 0;
		for (size_t i = 0; i < k - 1; i++)
			sum += cardPoints[i], mx = max(mx, sum + post[size(cardPoints) - k + i + 1]);
		return mx;
	}
	vector<int> output = {
		12,
		4,
		55
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2,3,4,5,6,1},
		{2,2,2},
		{9,7,7,9,7,7,9}
	};
	vector<int> input2 = {
		3,
		2,
		7
	};
};