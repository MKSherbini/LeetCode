#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/interval-list-intersections/

class IntervalListIntersections
{
public:
	// 28 ms, faster than 96.22% : 18.5 MB, less than 99.62%
	vector<vector<int>> solution(vector<vector<int>> firstList, vector<vector<int>> secondList) {
		int i = 0, j = 0;
		vector<vector<int>> ans;
		while (i < firstList.size() && j < secondList.size()) {
			int st1 = firstList[i][0], end1 = firstList[i][1], st2 = secondList[j][0], end2 = secondList[j][1];
			int len = 0;
			if ((len = sizeOf1In2(st1, end1, st2, end2)) >= 0) {
				ans.push_back({ st1, st1 + len });
			}
			else if ((len = sizeOf1In2(st2, end2, st1, end1)) >= 0) {
				ans.push_back({ st2, st2 + len });
			}

			if (end1 < end2) i++;
			else j++;
		}
		return ans;
	}
	int sizeOf1In2(int st1, int end1, int st2, int end2) {
		if (st2 <= st1 && st1 <= end2)
			return min(end2, end1) - st1;
		return -1;
	}
	vector<vector<vector<int>>> output = {
		{{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}},
		{}
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{0,2},{5,10},{13,23},{24,25}},
		{{1,3},{5,9}}
	};
	vector<vector<vector<int>>> input2 = {
		{{1,5},{8,12},{15,24},{25,26}},
		{}
	};
};