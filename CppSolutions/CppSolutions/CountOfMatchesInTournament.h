#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-of-matches-in-tournament/

class CountOfMatchesInTournament
{
public:
	// 0 ms, faster than 100% : 6.2 MB, less than 72.91%
	int solution(int n) {
		int ans = 0;
		while (n) {
			if (n & 1) {
				n >>= 1;
				ans += n + 1;
			}
			else {
				n >>= 1;
				ans += n;
			}
		}

		return ans - 1;
	}
	vector<int> output = {
		6,
		13
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		7,
		14
	};
};