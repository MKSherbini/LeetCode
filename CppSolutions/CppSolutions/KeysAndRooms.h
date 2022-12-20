#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/keys-and-rooms/

class KeysAndRooms
{
public:
	// 7 ms, faster than 96.41% : 10.6 MB, less than 24.42%
	bool solution(vector<vector<int>> rooms) {
		unordered_set<int> s;
		f(rooms, s, 0);
		return size(rooms) == size(s);
	}
	void f(vector<vector<int>>& rooms, unordered_set<int>& s, int i) {
		if (s.count(i)) return;
		s.insert(i);

		for (auto j : rooms[i])
			f(rooms, s, j);
	}
	vector<int> output = {
		true,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1},{2},{3},{}},
		{{1,3},{3,0,1},{2},{0}}
	};
};