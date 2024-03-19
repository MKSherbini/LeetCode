#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/task-scheduler/

class TaskScheduler
{
public:
	// 54 ms, faster than 74.63% : 37.9 MB, less than 94.23%
	int solution(vector<char>& tasks, int n) {
		vector<int> f(26);
		for (auto c : tasks) f[c - 'A']++;

		auto cmp = [](const auto& x, const auto& y) {
			return x.first != y.first ? x.first > y.first : x.second < y.second;
			};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

		sort(begin(f), end(f), greater());
		int i = 1;
		pq.push({ 0, f[0] });
		int t = 0;
		n++;
		while (!empty(pq)) {
			auto [cycle, left] = pq.top();
			pq.pop();
			if (i < 26 && f[i] && (cycle > t || left < f[i])) {
				pq.push({ cycle, left });
				cycle = t;
				left = f[i++];
			}
			else if (cycle > t) {
				t = cycle;
			}
			//cout << t << " " << cycle << " " << left << endl;

			if (left > 1)
				pq.push({ cycle + n, left - 1 });
			t++;
			if (empty(pq) && i < 26 && f[i]) pq.push({ t, f[i++] });
		}

		return t;
	}

};