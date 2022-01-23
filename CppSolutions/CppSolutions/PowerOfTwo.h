#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/power-of-two/

class PowerOfTwo
{
public:
	// 7 ms, faster than 100% : 5.6 MB, less than 99.51%
	bool solution(int n) {
		bool done = false;
		while (n)
		{
			if (n & 1) {
				if (!done)
					done = true;
				else
					return false;
			}
			n >>= 1;
		}
		return done;
	}
	vector<int> output = {
		true,
		true,
		false,
		false,
	};
	vector<int> input1 = {
		1,
		16,
		3,
		0,
	};
};

