#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class PartitioningIntoMinimumNumberOfDeciBinaryNumbers
{
public:
	// 32 ms, faster than 83.10% : 13.5 MB, less than 92.98%
	int solution(string n) {
		int mx = 0;
		for (int i = 0; i < n.size(); i++)
			mx = max(mx, n[i] - 48);
		return mx;
	}

	vector<int> output = {
		3,
		8,
		9
	};
	vector<string> input1 = {
		"32",
		"82734",
		"27346209830709182346"
	};
};

