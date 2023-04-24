#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/last-stone-weight/

class LastStoneWeight
{
public:
	// 0 ms, faster than 100% : 7.5 MB, less than 84.27%
	int solution(vector<int> stones) {
		priority_queue<int> pq;
		for (auto x : stones)
			pq.push(x);

		while (size(pq) > 1) {
			int t = pq.top();
			pq.pop();
			int t2 = pq.top();
			pq.pop();
			if (t != t2)
				pq.push(t - t2);
		}
		return size(pq) == 0 ? 0 : pq.top();
	}
	vector<int> output = {
		1,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,7,4,1,8,1},
		{1}
	};
};