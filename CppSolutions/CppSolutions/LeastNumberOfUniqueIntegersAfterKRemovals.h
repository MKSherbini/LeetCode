#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class LeastNumberOfUniqueIntegersAfterKRemovals
{
public:
	// 122 ms, faster than 75.67% : 66.1 MB, less than 60.95%
	int solution(vector<int> arr, int k) {
		sort(begin(arr), end(arr));
		unordered_map<int, int> m;
		for (auto x : arr) m[x]++;
		vector<int> v;
		for (auto [_, c] : m) v.push_back(c);
		sort(begin(v), end(v));
		int n = size(v);
		for (size_t i = 0; i < n; i++) {
			if (k < v[i]) return n - i;
			k -= v[i];
		}
		return 0;
	}
	vector<int> output = {
		1,
		2
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{5,5,4},
		{4,3,1,1,3,3,2}
	};
	vector<int> input2 = {
		1,
		3
	};
};