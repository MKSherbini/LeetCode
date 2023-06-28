#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

class FindKPairsWithSmallestSums
{
public:
	// 277 ms, faster than 88.98% : 119.2 MB, less than 36.75%
	vector<vector<int>> solution(vector<int> nums1, vector<int> nums2, int k) {
		int n = size(nums1);
		int m = size(nums2);
		int all = 1LL * n * m > 1e5 ? 1e5 : n * m;
		k = min(all, k);
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

		vector<vector<int>> ans;
		for (size_t i = 0; i < n; i++) {
			pq.emplace(nums1[i] + nums2[0], i, 0);
		}
		for (size_t c = 0; c < k; c++) {
			auto [_, i, j] = pq.top();
			pq.pop();
			ans.push_back({ nums1[i], nums2[j] });
			if (j + 1 < m) {
				j++;
				pq.emplace(nums1[i] + nums2[j], i, j);
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1,2},{1,4},{1,6}},
		{{1,1},{1,1}},
		{{1,3},{2,3}}
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{1,7,11},
		{1,1,2},
		{1,2}
	};
	vector<vector<int>> input2 = {
		{2,4,6},
		{1,2,3},
		{3}
	};
	vector<int> input3 = {
		3,
		2,
		3
	};
};