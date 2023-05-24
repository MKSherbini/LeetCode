#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-subsequence-score/

class MaximumSubsequenceScore
{
public:
	// 263 ms, faster than 78.57% : 91.8 MB, less than 72.17%
	long long solution(vector<int> nums1, vector<int> nums2, int k) {
		int n = size(nums1);

		vector<pair<int, int>> v;
		for (size_t i = 0; i < n; i++) {
			v.emplace_back(nums2[i], nums1[i]);
		}

		sort(begin(v), end(v), greater());

		priority_queue<int, vector<int>, greater<int>> pq;
		long long sum = 0;
		long long ans = 0;
		for (auto& [n2, n1] : v) {
			pq.push(n1);
			sum += n1;

			if (size(pq) > k) {
				sum -= pq.top(), pq.pop();
			}

			if (size(pq) == k) {
				ans = max(ans, sum * n2);
			}
		}

		return ans;
	}
	vector<int> output = {
		12,
		30
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{1,3,3,2},
		{4,2,3,1,1}
	};
	vector<vector<int>> input2 = {
		{2,1,3,4},
		{7,5,10,9,6}
	};
	vector<int> input3 = {
		3,
		1
	};
};