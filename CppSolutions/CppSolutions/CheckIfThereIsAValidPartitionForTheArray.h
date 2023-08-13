#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

class CheckIfThereIsAValidPartitionForTheArray
{
public:
	// 135 ms, faster than 80.61% : 83.6 MB, less than 99.69%
	bool solution(vector<int> nums) {
		int n = size(nums);

		vector mem(4, 0);
		for (int i = n - 2; i >= 0; i--) {
			if (i + 1 < n && nums[i] == nums[i + 1])
				mem[0] |= mem[2] | i + 2 == n;
			if (i + 2 < n && nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
				mem[0] |= mem[3] | i + 3 == n;
			if (i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1)
				mem[0] |= mem[3] | i + 3 == n;

			Printer::print(mem);
			swap(mem[2], mem[3]);
			swap(mem[1], mem[2]);
			swap(mem[0], mem[1]);
			mem[0] = 0;
		}

		return mem[1];
	}

	// 117 ms, faster than 95.38% : 105 MB, less than 5.23%
	bool solution2(vector<int> nums) {
		int n = size(nums);

		vector mem(n, -1);
		function<bool(int)> f = [&](int i) -> int {
			if (i == n) return 1;
			if (mem[i] != -1) return mem[i];

			bool ret = 0;
			if (i + 1 < n && nums[i] == nums[i + 1])
				ret |= f(i + 2);
			if (i + 2 < n && nums[i] == nums[i + 1] && nums[i] == nums[i + 2])
				ret |= f(i + 3);
			if (i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1)
				ret |= f(i + 3);

			return mem[i] = ret;
		};

		return f(0);
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{4,4,4,5,6},
		{1,1,1,2}
	};
};