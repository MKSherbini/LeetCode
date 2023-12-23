#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/path-crossing/

class PathCrossing
{
public:
	// 0 ms, faster than 100% : 7 MB, less than 93.92%
	uint8_t solution(string path) {
		int x = 0, y = 0;
		set<pair<int, int>> s;
		s.insert({ x, y });
		for (auto c : path) {
			if (c == 'N') {
				y++;
			}
			else if (c == 'S') {
				y--;
			}
			else if (c == 'E') {
				x++;
			}
			else if (c == 'W') {
				x--;
			}
			int sz = size(s);
			s.insert({ x, y });
			if (sz == size(s)) return 1;
		}
		return 0;
	}
	vector<uint8_t> output = {
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"NES",
		"NESWW"
	};
};