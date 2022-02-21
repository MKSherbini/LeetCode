#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class FindMinimumInRotatedSortedArray
{
public:
	// 0 ms, faster than 100% : 10 MB, less than 95.89%
	int solution(vector<int> nums) {
		if (nums.size() == 1) return nums[0];
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > nums[lo]) lo = mid;
			else hi = mid;
		}

		return min(nums[0], nums[lo + 1]);
	}

	int solution2(vector<int> nums) {
		int it = 0, sz = nums.size(), step = (sz + 1) / 2, dir = 0, mul = 1, last = 0;

		while (step > 0) {

			int prev = (it - 1 + sz) % sz;
			int next = (it + 1) % sz;

			cout << "At " << nums[it] << ", Step " << step << ", Mul " << mul << endl;
			if (nums[next] < nums[it]) return nums[next];
			if (nums[prev] > nums[it]) return nums[it];

			if ((dir == -1 && nums[it] > nums[last]) || (dir == 1 && nums[it] < nums[last]))
				mul *= -1;
			last = it;
			if (nums[it] > nums[prev]) {
				cout << "Going " << "<<" << endl;
				it -= mul * step, it += sz, it %= sz, dir = -1;
			}
			else {
				cout << "Going " << ">>" << endl;
				it += mul * step, it += sz, it %= sz, dir = 1;
			}
			step /= 2;
		}
		int prev = (it - 1 + sz) % sz;
		int next = (it + 1) % sz;
		//return min(min(nums[it], nums[prev]), nums[next]);
		return nums[it];
	}
	vector<int> output = {
		1,
		0,
		0,
		9,
		0,
		0,
		0,
		0,
		0,
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,4,5,1,2},
		{4,5,6,7,0,1,2},
		{4,5,0,1,2},
		{9,10,11,13,15,17},
		{1,2,3,4,5,6,7,8,9,0},
		{3,4,5,6,7,8,9,10,0,1,2},
		{3,4,5,6,7,8,9,10,0},
		{0},
		{1,0},
	};
};