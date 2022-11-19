#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/erect-the-fence/

class ErectTheFence
{
public:
	// 63 ms, faster than 90.63% : 23 MB, less than 43.75%
	vector<vector<int>> solution(vector<vector<int>> trees) {
		int n = size(trees);
		if (n <= 3) return trees;

		sort(begin(trees), end(trees), [](auto& x, auto& y) {return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0]; });

		vector<vector<int>> ans;
		ans.reserve(n);

		for (size_t i = 0; i < n; i++) {
			while (size(ans) > 1 && cross(ans[size(ans) - 2], ans.back(), trees[i]) < 0)
				ans.pop_back();
			ans.push_back(trees[i]);
		}
		if (size(ans) == n) return ans;

		for (int i = n - 2; i >= 0; i--) {
			while (size(ans) > 1 && cross(ans[size(ans) - 2], ans.back(), trees[i]) < 0)
				ans.pop_back();
			ans.push_back(trees[i]);
		}
		ans.pop_back();

		return ans;
	}
	int cross(const vector<int>& o, const vector<int>& a, const vector<int>& b) {
		return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
	}
	vector<vector<vector<int>>> output = {
		{{1,1},{2,0},{3,3},{2,4},{4,2}},
		{{4,2},{2,2},{1,2}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}},
		{{1,2},{2,2},{4,2}}
	};
};