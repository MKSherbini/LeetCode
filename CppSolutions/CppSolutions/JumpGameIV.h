#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/jump-game-iv/

class JumpGameIV
{
public:
	// 205 ms, faster than 84.52% : 73.4 MB, less than 71.17%
	int solution(vector<int> arr) {
		int n = size(arr);
		if (n == 1) return 0;
		map<int, vector<int>> m;
		vector<int> dist(n, -1);
		for (size_t i = 0; i < n; i++)
			m[arr[i]].push_back(i);
		Printer::print(m);
		queue<int> q;
		q.push(0);
		int lvl = 1;
		while (!q.empty()) {
			int c = size(q);
			Printer::print(q);
			while (c--) {
				auto i = q.front();
				q.pop();
				if (i + 1 == n - 1) return lvl;

				if (i + 1 < n && dist[i + 1] == -1) {
					dist[i + 1] = lvl;
					q.push(i + 1);
				}
				if (i - 1 >= 0 && dist[i - 1] == -1) {
					dist[i - 1] = lvl;
					q.push(i - 1);
				}
				for (auto j : m[arr[i]]) {
					if (j == n - 1) return lvl;
					if (i != j && dist[j] == -1) {
						dist[j] = lvl;
						q.push(j);
					}
				}
				m[arr[i]].clear();
			}
			lvl++;
		}
		return -1;
	}
	const int OO = 1e6;
	vector<int> output = {
		3,
		0,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{100,-23,-23,404,100,23,23,23,3,404},
		{7},
		{7,6,9,6,9,6,9,7}
	};
};