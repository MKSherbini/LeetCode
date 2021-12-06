#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/


class TwoSum2
{
public:
	// 0ms, 9.5mb
	vector<int> solution(vector<int>& v, int target) {
		int sz = v.size();
		int i = 0, j = sz - 1;
		while (v[i] + v[j] != target)
		{
			if (v[i] + v[j] > target) {
				j--;
			}
			else if (v[i] + v[j] < target) {
				i++;
			}
		}
		return { i + 1,j + 1 };
	}

	// 8ms, 9.6ms
	vector<int> solution2(vector<int>& v, int target) {
		int sz = v.size();
		for (int i = 0; i < sz; i++)
		{
			int  x = v[i], y = target - x;
			int j = lower_bound(begin(v), end(v), y) - begin(v);
			if (i == j) j++;
			if (j < sz && v[j] == y) return { i + 1,j + 1 };
		}
		return {};
	}
};

