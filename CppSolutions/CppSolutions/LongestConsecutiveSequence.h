#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-consecutive-sequence/

class LongestConsecutiveSequence
{
public:
	// 141 ms, faster than 79.89% : 51.8 MB, less than 14.24%
	int solution(vector<int> nums) {
		parents.resize(size(nums));
		sizes.assign(size(nums), 1);
		for (size_t i = 0; i < size(parents); i++)
			parents[i] = i;

		for (size_t i = 0; i < size(nums); i++)
		{
			if (s.find(nums[i]) != end(s)) continue;

			s.insert({ nums[i] , i });

			joinIfPresent(nums[i] + 1, i);
			joinIfPresent(nums[i] - 1, i);
		}

		Printer::print(parents, sizes, mxSize, s);

		return size(s) < 2 ? size(s) : mxSize;
	}
	void joinIfPresent(int i, int j) {
		auto f = s.find(i);
		if (f != end(s))
			joinSet(f->second, j);
	}

	int findSet(int i) {
		return (parents[i] == i) ? i : parents[i] = findSet(parents[i]);
	}

	void joinSet(int i, int j) {
		int x = findSet(i);
		int y = findSet(j);
		if (x == y) return;

		if (sizes[x] > sizes[y]) {
			parents[y] = x;
			sizes[x] += sizes[y];
			mxSize = max(mxSize, sizes[x]);
		}
		else {
			parents[x] = y;
			sizes[y] += sizes[x];
			mxSize = max(mxSize, sizes[y]);
		}
	}

	int mxSize = 1;
	vector<int> parents;
	vector<int> sizes;
	unordered_map<int, int> s;


	vector<int> output = {
		4,
		9,
		3
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{100,4,200,1,3,2},
		{0,3,7,2,5,8,4,6,0,1},
		{1,2,0,1}
	};
};