#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

class RemoveColoredPiecesIfBothNeighborsAreTheSameColor
{
public:
	// 27 ms, faster than 93.3% : 13.5 MB, less than 33.01%
	bool solution(string colors) {
		int n = size(colors);
		int a = 0, b = 0;
		for (size_t i = 1; i < n - 1; i++) {
			if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1])
				a += colors[i] == 'A', b += colors[i] == 'B';
		}

		Printer::print(a, b);

		return a > b;
	}
	vector<bool> output = {
		true,
		false,
		false
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"AAABABB",
		"AA",
		"ABBBBBBBAAA"
	};
};