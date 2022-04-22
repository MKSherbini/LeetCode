#pragma o	nce
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/longest-increasing-subsequence/

class LongestIncreasingSubsequence
{
public:
	// 529 ms, faster than 13.65% : 10.7 MB, less than 17.06%
	int solution(vector<int> nums) {
		vector<int> mem(nums.size(), -1);
		int ret = 1;
		curse(nums, mem, 0, ret);
		Printer::print(mem);
		return max(0, ret);
	}
	int curse(vector<int>& nums, vector<int>& mem, int i, int& mx) {
		if (i + 1 == nums.size()) return 1;
		if (mem[i] != -1) return mem[i];

		int ret = 0, maxHere = 1;
		//if (nums[i] > nums[last]) {
		//	auto t = mem[i][last] + 1 + curse(nums, mem, i + 1, i);
		//	//Printer::print(nums[last], nums[i], t);
		//	ret = max(ret, t);
		//}
		//ret = max(ret, curse(nums, mem, i + 1, last));

		for (int j = i + 1; j < nums.size(); j++) {
			ret = curse(nums, mem, j, mx);
			if (nums[i] < nums[j]
				&& ret + 1 > maxHere)
				maxHere = ret + 1;
		}

		if (mx < maxHere)
			mx = maxHere;

		return mem[i] = maxHere;
	}
	vector<int> output = {
		4,
		4,
		4,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{10,9,2,5,3,7,101,18},
		{10,9,2,5,1,1,3,7,101,18},
		{0,1,0,3,2,3},
		{7,7,7,7,7,7,7}
	};
};