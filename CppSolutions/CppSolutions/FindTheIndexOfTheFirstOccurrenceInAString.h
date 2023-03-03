#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class FindTheIndexOfTheFirstOccurrenceInAString
{
public:
	// 0 ms, faster than 100% : 6.1 MB, less than 95.03%
	int solution(string haystack, string needle) {
		return haystack.find(needle);
	}
	vector<int> output = {
		0,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"sadbutsad",
		"leetcode"
	};
	vector<string> input2 = {
		"sad",
		"leeto"
	};
};