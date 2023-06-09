#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class FindSmallestLetterGreaterThanTarget
{
public:
	// 11 ms, faster than 94.29% : 15.8 MB, less than 96.78%
	char solution(vector<char> letters, char target) {
		char ans = 'z';
		bool in = 0;
		for (auto c : letters) {
			if (c > target)
				ans = min(ans, c), in = 1;
		}

		return in ? ans : letters[0];
	}
	vector<char> output = {
		'c',
		'f',
		'x'
	};
	static constexpr int const& inputs = 2;
	vector<vector<char>> input1 = {
		{'c','f','j'},
		{'c','f','j'},
		{'x','x','y','y'}
	};
	vector<char> input2 = {
		'a',
		'c',
		'z'
	};
};