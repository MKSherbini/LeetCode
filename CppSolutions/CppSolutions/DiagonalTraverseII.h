#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/diagonal-traverse-ii/?envType=daily-question&envId=2023-11-22

class DiagonalTraverseII
{
public:
	// 130 ms, faster than 84.4% : 69.9 MB, less than 85.9%
	vector<int> solution(vector<vector<int>> nums) {
		vector<int> ans;
		vector<pair<int, int>> v;
		for (size_t i = 0; i < size(nums); i++) {
			for (size_t j = 0; j < size(nums[i]); j++) {
				v.push_back({ i, j });
			}
		}

		sort(begin(v), end(v), [&](const auto& a, const auto& b) {
			auto& [i, j] = a; auto& [ii, jj] = b;
			int d = i + j, dd = ii + jj;
			if (d != dd)
				return d < dd;

			return i > ii;
			});

		for (auto& [i, j] : v)
			ans.push_back(nums[i][j]);

		return ans;
	}

	//TLE :)
	vector<int> solution2(vector<vector<int>> nums) {
		int n = size(nums), m = 0;
		vector<int> ans;

		for (size_t d = 0; d < n; d++) {
			int l = size(nums[d]);
			m = max(m, l);

			int i = d, j = 0;
			while (i >= 0) {
				if (j < size(nums[i]))
					ans.push_back(nums[i][j]);
				i--, j++;
			}
		}

		for (size_t d = 1; d < m; d++) {
			int i = n - 1, j = d;
			while (i >= 0) {
				if (j < size(nums[i]))
					ans.push_back(nums[i][j]);
				i--, j++;
			}
		}

		return ans;
	}
	vector<vector<int>> output = {
		{1,4,2,7,5,3,8,6,9},
		{1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16},
		{1,2,3,4,5,6}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,3},{4,5,6},{7,8,9}},
		{{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}},
		{{1,2,3,4,5,6}},
	};
};