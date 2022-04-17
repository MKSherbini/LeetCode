#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/arithmetic-slices/

class ArithmeticSlices
{
public:
	// 0 ms, faster than 100% : 7.2 MB, less than 98.74%
	int solution(vector<int> nums) {
		int ret = 0;
		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			int j = i + 1, diff = nums[j] - nums[i];
			int cnt = 1;
			while (j < nums.size() && nums[j] - nums[i] == diff)
			{
				cnt++;
				i++;
				j++;
			}
			ret += ((cnt - 1) * (cnt - 2)) / 2;
			i--;
		}
		return ret;
	}

	// WA
	int solution2(vector<int> nums) {
		vector<int> mem(4001, -1);
		auto ret = curse(mem, nums, 0, 0, OO, -1);
		cout << endl;
		for (int i = 0; i < mem.size(); i++)
			if (mem[i] != -1)
				cout << i - 2000 << " " << mem[i] << endl;
		return ret;
	}
	int curse(vector<int>& mem, vector<int>& nums, int i, int cnt, int diff, int lastI) {
		if (i == nums.size()) return diff != OO && cnt >= 3 ? cnt : 0;
		if (diff != OO && mem[diff + 2000] != -1) return mem[diff + 2000];

		int ret = 0;
		if (diff == OO && lastI == -1)
			ret += curse(mem, nums, i + 1, cnt + 1, OO, i),
			ret += curse(mem, nums, i + 1, cnt, OO, -1);
		else if (diff == OO)
			ret += curse(mem, nums, i + 1, cnt + 1, nums[i] - nums[lastI], i);
		else if (lastI + 1 == i && nums[i] - nums[lastI] == diff)
			ret += curse(mem, nums, i + 1, cnt + 1, diff, i);

		Printer::print(lastI, i, diff);
		return diff != OO ? mem[diff + 2000] = max(ret, mem[diff + 2000]) : ret;
	}
	const int OO = (int)1e8;

	vector<int> output = {
		3,
		56,
		0
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,4},
		{1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9},
		{1}
	};
};
//
//vector<vector<int>> mem(4001, vector<int>(5000, -1));
//return curse(mem, nums, 0, 0, OO, -1, -1);
//	}
//	int curse(vector<vector<int>>& mem, vector<int>& nums, int i, int cnt, int diff, int next, int start) {
//		if (i == nums.size()) return diff != OO && cnt >= 3 ? cnt - 2 : 0;
//		if (diff != OO && mem[diff + 1000][start] != -1) return mem[diff + 1000][start];
//
//		int ret = 0;
//		if (diff == OO && next == -1)
//			ret += curse(mem, nums, i + 1, cnt + 1, OO, i, i),
//			ret += curse(mem, nums, i + 1, cnt, OO, -1, -1);
//		else if (diff == OO)
//			ret += curse(mem, nums, i + 1, cnt + 1, nums[i] - nums[next], nums[i] + nums[i] - nums[next], start);
//		else if (nums[i] == next)
//			ret += curse(mem, nums, i + 1, cnt + 1, diff, next + diff, start);
//
//		return diff != OO ? mem[diff + 2000][start] = ret : ret;
//	}