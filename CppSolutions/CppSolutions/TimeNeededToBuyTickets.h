#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/time-needed-to-buy-tickets/

class TimeNeededToBuyTickets
{
public:
	// 0 ms, faster than 100% : 9.2 MB, less than 91.31%
	int solution(vector<int> tickets, int k) {
		int n = size(tickets);
		bool done = false;
		int ans = 0;
		while (!done) {
			done = true;
			for (size_t i = 0; i < n; i++) {
				if (!tickets[i]) continue;
				done = false;
				tickets[i]--;
				ans++;
				if (i == k && !tickets[i]) return ans;
			}
		}

		return 66;
	}
	vector<int> output = {
		6,
		8
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{2,3,2},
		{5,1,1,1}
	};
	vector<int> input2 = {
		2,
		0
	};
};