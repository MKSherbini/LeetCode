#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/meeting-rooms-iii/

class MeetingRoomsIII
{
public:
	// 335 ms, faster than 76.92% : 113.6 MB, less than 33.01%
	int solution(int n, vector<vector<int>> meetings) {
		sort(begin(meetings), end(meetings), [](const auto& a, const auto& b) {return a[0] < b[0]; });
		Printer::print(meetings);

		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		priority_queue<int, vector<int>, greater<int>> rooms;
		for (size_t i = 0; i < n; i++) {
			rooms.push(i);
		}

		vector<int> len(n);
		int ans = 0, ansI = n;
		for (auto m : meetings) {
			long long currTime = m[0];
			while (size(rooms) == 0 || (!pq.empty() && m[0] >= pq.top().first)) {
				rooms.push(pq.top().second);
				currTime = max(currTime, pq.top().first);
				pq.pop();
			}
			int i = rooms.top();
			rooms.pop();
			len[i]++;
			pq.push({ currTime + m[1] - m[0], i });
			if (len[i] > ans || len[i] == ans && ansI > i) {
				ans = len[i], ansI = i;
			}
			Printer::print(pq);
		}
		Printer::print(len);
		return ansI;
	}
	vector<int> output = {
		0,
		1,
		1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		2,
		3,
		3
	};
	vector<vector<vector<int>>> input2 = {
		{{0,10},{1,5},{2,7},{3,4}},
		{{0,10},{1,9},{2,8},{3,7},{4,6}},
		{{1,20},{2,10},{3,5},{4,9},{6,8}}
	};
};