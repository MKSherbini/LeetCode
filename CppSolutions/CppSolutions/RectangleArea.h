#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/rectangle-area/

class RectangleArea
{
public:
	// 4 ms, faster than 96.35% : 5.8 MB, less than 96.47%
	int solution(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
		int x1 = max(ax1, bx1);
		int x2 = min(ax2, bx2);
		int y1 = max(ay1, by1);
		int y2 = min(ay2, by2);

		int ans = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
		if (x1 < x2 && y1 < y2)
			ans -= (x2 - x1) * (y2 - y1);

		return ans;
	}
	vector<int> output = {
		45,
		16
	};
	static constexpr int const& inputs = 8;
	vector<int> input1 = {
		-3,
		-2
	};
	vector<int> input2 = {
		0,
		-2
	};
	vector<int> input3 = {
		3,
		2
	};
	vector<int> input4 = {
		4,
		2
	};
	vector<int> input5 = {
		0,
		-2
	};
	vector<int> input6 = {
		-1,
		-2
	};
	vector<int> input7 = {
		9,
		2
	};
	vector<int> input8 = {
		2,
		2
	};
};