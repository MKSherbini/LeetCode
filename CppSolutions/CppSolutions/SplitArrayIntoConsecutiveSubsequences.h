#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/split-array-into-consecutive-subsequences/

class SplitArrayIntoConsecutiveSubsequences
{
public:
	// 75 ms, faster than 99.53% : 56.5 MB, less than 78.51%
	bool solution(vector<int> nums) {
		vector f(2003, 0);
		for (auto x : nums)
			f[x + 1000]++;

		Printer::print(f);
		for (size_t i = 0; i < size(f); i++)
		{
			int t = f[i];
			int l = 0, m = 0, r = 0;
			if (i > 1)
				l = min(f[i - 1], f[i - 2]);
			if (i < size(f) - 1 && i > 0)
				m = min(f[i - 1], f[i + 1]);

			int lm = 0;
			if (i > 0)
				lm = min(l + m, f[i - 1]);
			if (i < size(f) - 2)
				r = min(f[i + 1] - lm + l, f[i + 2]);

			t -= lm + r;

			Printer::print(i, t, lm);
			Printer::print(l, m, r);

			if (t > 0)
				return false;
		}

		return true;
	}

	// 165 ms, faster than 50.77% : 69.5 MB, less than 12.99%
	bool solution2(vector<int> nums) {
		vector f(2003, 0);
		for (auto x : nums)
			f[x + 1000]++;

		Printer::print(f);
		for (size_t i = 0; i < size(f); i++)
		{

			vector t(begin(f) + max(0, (int)i - 2), begin(f) + min(i + 3, size(f)));

			if (i < size(f) - 2)
				mini(f, f[i], i, i + 2);
			if (i > 1)
				mini(f, f[i], i - 2, i);
			if (i < size(f) - 1 && i>0)
				mini(f, f[i], i - 1, i + 1);
			Printer::print(f);

			if (f[i] != 0)
				return false;

			copy(begin(t), end(t), begin(f) + max(0, (int)i - 2));
		}

		return true;
	}

	void mini(vector<int>& f, int& base, int st, int end) {
		int mn = base;
		for (size_t j = st; j <= end; j++)
			mn = min(mn, f[j]);
		for (size_t j = st; j <= end; j++)
			f[j] -= mn;
	}
	vector<int> output = {
		true,
		true,
		false,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,3,3,4,5},
		{1,2,3,3,4,4,5,5},
		{1,2,3,4,4,5},
		{3,4,4,5,6,7,8,9,10,11}
	};
};