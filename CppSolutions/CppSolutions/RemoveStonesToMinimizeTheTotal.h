#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-stones-to-minimize-the-total/

class RemoveStonesToMinimizeTheTotal
{
public:
	// 495 ms, faster than 98.62% : 104.9 MB, less than 66.84%
	int solution(vector<int> piles, int k) {
		priority_queue<int> pq;
		int ans = 0;

		for (auto x : piles)
			ans += x, pq.push(x);

		for (size_t i = 0; i < k; i++)
			ans -= pq.top() / 2, pq.push((pq.top() + 1) / 2), pq.pop();

		return ans;
	}
	vector<int> output = {
		12,
		12
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{5,4,9},
		{4,3,6,7}
	};
	vector<int> input2 = {
		2,
		3
	};
};