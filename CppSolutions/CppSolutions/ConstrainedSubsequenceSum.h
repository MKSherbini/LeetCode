#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/constrained-subsequence-sum/

class ConstrainedSubsequenceSum
{
public:
	// 267 ms, faster than 56.7% : 139.5 MB, less than 45.98%
	int solution(vector<int> nums, int k) {
		int n = size(nums);
		priority_queue<pair<int, int>> pq;

		pq.push({ nums[0], 0 });
		int ans = nums[0];
		for (size_t i = 1; i < n; i++) {
			while (i - pq.top().second > k) {
				pq.pop();
			}

			int cur = max(0, pq.top().first) + nums[i];
			ans = max(ans, cur);
			pq.push({ cur, i });
		}

		return ans;
	}
	vector<int> output = {
		37,
		-1,
		23
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{10,2,-10,5,20},
		{-1,-2,-3},
		{10,-2,-10,-5,20}
	};
	vector<int> input2 = {
		2,
		1,
		2
	};
};