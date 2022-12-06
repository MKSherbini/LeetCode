#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/top-k-frequent-elements/

class TopKFrequentElements
{
public:
	// 11 ms, faster than 98.95% : 13.3 MB, less than 99.9%
	vector<int> solution(vector<int> nums, int k) {
		vector<int> ans;
		unordered_map<int, int> f;
		auto cmp = [&](int i, int j) { return f[i] > f[j]; };

		for (auto x : nums)
			++f[x];

		Printer::print(f);
		for (auto& p : f) {
			if (size(ans) <= k) {
				ans.push_back(p.first);
				push_heap(begin(ans), end(ans), cmp);
				if (size(ans) > k) pop_heap(begin(ans), end(ans), cmp);
			}
			else {
				ans.back() = p.first;
				push_heap(begin(ans), end(ans), cmp);
				pop_heap(begin(ans), end(ans), cmp);
			}
			Printer::print(ans);
		}

		if (size(ans) > k)
			ans.pop_back();
		return ans;
	}

	// 55 ms, faster than 5.2% : 15.1 MB, less than 13.93%
	vector<int> solution1(vector<int> nums, int k) {
		const int MAX = 20001;
		vector<int> ans;
		vector<int> f(MAX, 0);
		auto cmp = [&](int i, int j) { return f[i] > f[j]; };

		for (size_t i = 0; i < k + 1; i++)
			ans.push_back(i);

		for (auto x : nums)
			++f[x + 10000];

		make_heap(begin(ans), end(ans), cmp);
		pop_heap(begin(ans), end(ans), cmp);

		for (size_t i = k + 1; i < MAX; i++) {
			ans.back() = i;
			push_heap(begin(ans), end(ans), cmp);
			pop_heap(begin(ans), end(ans), cmp);
		}

		ans.pop_back();
		for (auto& x : ans)
			x -= 10000;

		return ans;
	}
	vector<vector<int>> output = {
		{1,2},
		{1}
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,1,1,2,2,3},
		{1}
	};
	vector<int> input2 = {
		2,
		1
	};
};