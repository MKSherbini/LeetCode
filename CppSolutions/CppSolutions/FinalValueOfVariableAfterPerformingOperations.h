#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

class FinalValueOfVariableAfterPerformingOperations
{
public:
	// 4 ms, faster than 95.76% : 13.9 MB, less than 91.81%
	int solution(vector<string>& operations) {
		int x = 0;
		for (int i = 0; i < operations.size(); i++)
			x = x + (operations[i][1] == '+') - (operations[i][1] == '-');
		return x;
	}
};

//run(FinalValueOfVariableAfterPerformingOperations(), vector<string> { "--X", "X++", "X++" });
//run(FinalValueOfVariableAfterPerformingOperations(), vector<string> { "++X", "++X", "X++" });
//run(FinalValueOfVariableAfterPerformingOperations(), vector<string> { "X++", "++X", "--X", "X--" });
