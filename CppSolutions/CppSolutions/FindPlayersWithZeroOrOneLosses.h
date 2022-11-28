#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class FindPlayersWithZeroOrOneLosses
{
public:
	// 858 ms, faster than 84.89% : 171.3 MB, less than 61.6%
	vector<vector<int>> solution(vector<vector<int>> matches) {
		set<int> s, s1, ss;

		for (auto& m : matches)
			s.insert(m[0]);

		for (auto& m : matches) {
			if (ss.contains(m[1]));
			else if (s1.contains(m[1])) s1.erase(m[1]), ss.insert(m[1]);
			else s1.insert(m[1]);
			s.erase(m[1]);
		}

		vector<vector<int>> ans;
		ans.emplace_back(begin(s), end(s));
		ans.emplace_back(begin(s1), end(s1));

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{1,2,10},{4,5,7,8}},
		{{1,2,5,6},{}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}},
		{{2,3},{1,3},{5,4},{6,4}}
	};
};