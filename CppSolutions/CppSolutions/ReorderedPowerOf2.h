#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reordered-power-of-2/

class ReorderedPowerOf2
{
public:
	// 0 ms, faster than 100% : 6.3 MB, less than 40.11%
	bool solution(int n) {
		string s = to_string(n);
		sort(begin(s), end(s));

		vector<string> nums;
		for (size_t i = 1; i < INT_MAX; i <<= 1)
			nums.push_back(to_string(i));

		for (auto x : nums) {
			sort(begin(x), end(x));
			if (x == s) return true;
		}

		return false;
	}

	// 951 ms, faster than 5.08% : 139.6 MB, less than 5.37%
	bool solution3(int n) {
		vector<int> nums;
		while (n)
			nums.push_back(n % 10), n /= 10;
		Printer::print(nums);
		unordered_map<int, bool> mem;
		return f(nums, mem, 0, 0);
	}
	bool f(vector<int>& nums, unordered_map<int, bool>& mem, int n, int taken) {
		Printer::print(n, taken);
		if (taken == (1 << size(nums)) - 1) return powerof2(n);
		if (mem.find(n) != mem.end()) return mem[n];
		bool ret = false;
		for (int i = 0; i < nums.size(); i++)
		{
			int vis = (taken & (1 << i));
			if (vis || (nums[i] == 0 && taken == 0)) continue;
			ret |= f(nums, mem, n * 10 + nums[i], taken | (1 << i));
			if (ret) return ret;
		}
		return mem[n] = ret;
	}

	// 410 ms, faster than 7.06% : 5.9 MB, less than 96.61%
	bool solution2(int n) {
		vector<int> nums;
		while (n)
			nums.push_back(n % 10), n /= 10;
		Printer::print(nums);
		return f(nums, 0, 0);
	}
	bool f(vector<int>& nums, int n, int taken) {
		Printer::print(n, taken);
		if (taken == (1 << size(nums)) - 1) return powerof2(n);
		bool ret = false;
		for (int i = 0; i < nums.size(); i++)
		{
			int vis = (taken & (1 << i));
			if (vis || (nums[i] == 0 && taken == 0)) continue;
			ret |= f(nums, n * 10 + nums[i], taken | (1 << i));
			if (ret) return ret;
		}
		return ret;
	}
	bool powerof2(int n) {
		Printer::print(n);
		while ((n & 1) == 0)
			n >>= 1;
		return n == 1;
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		1,
		100
	};
};