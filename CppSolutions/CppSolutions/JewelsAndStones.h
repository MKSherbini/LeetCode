#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/jewels-and-stones/

class JewelsAndStones
{
public:
	// 0 ms, faster than 100.00% : 6.1 MB, less than 96.14%
	int solution(string jewels, string stones) {
		int arr[58] = { 0 }, cnt = 0;
		for (int i = 0; i < jewels.size(); i++)
			arr[jewels[i] - 65] = 1;
		for (int i = 0; i < stones.size(); i++)
			if (arr[stones[i] - 65]) cnt++;
		return cnt;
	}
	vector<int> output = {
	3,
	0,
	};
	vector<string> input1 = {
		"aA",
		"z",
	};
	vector<string> input2 = {
		"aAAbbbb",
		"ZZ",
	};
};

