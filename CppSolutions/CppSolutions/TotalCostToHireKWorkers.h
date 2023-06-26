#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/total-cost-to-hire-k-workers/

class TotalCostToHireKWorkers
{
public:
	// 260 ms, faster than 35.31% : 75.6 MB, less than 44.55%
	int solution(vector<int> costs, int k, int candidates) {
		int n = size(costs);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		int i = 0, j;
		for (; i < candidates; i++) {
			pq.emplace(costs[i], i);
		}
		for (j = n - 1; j >= n - candidates && j >= i; j--) {
			pq.emplace(costs[j], j);
		}

		Printer::print(i, j, pq.size(), costs.size());
		long long ans = 0;
		while (!pq.empty() && k) {
			auto [cost, index] = pq.top();
			pq.pop();
			k--;

			if (i <= j) {
				if (index > j) {
					pq.emplace(costs[j], j);
					j--;
				}
				else {
					pq.emplace(costs[i], i);
					i++;
				}
			}

			Printer::print(index, cost);
			ans += cost;
		}

		return ans;
	}

	// 286 ms, faster than 19.53% : 78.7 MB, less than 14.82%
	int solution2(vector<int> costs, int k, int candidates) {
		int n = size(costs);
		priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;
		int i = 0, j;
		for (; i < candidates; i++) {
			pq.emplace(costs[i], i, 0);
		}
		for (j = n - 1; j >= n - candidates && j >= i; j--) {
			pq.emplace(costs[j], j, 1);
		}

		Printer::print(i, j, pq.size(), costs.size());
		long long ans = 0;
		while (!pq.empty() && k) {
			auto [cost, index, dir] = pq.top();
			pq.pop();
			k--;

			if (i <= j) {
				if (dir) {
					pq.emplace(costs[j], j, dir);
					j--;
				}
				else {
					pq.emplace(costs[i], i, dir);
					i++;
				}
			}

			Printer::print(index, cost, dir);
			ans += cost;
		}

		return ans;
	}
	vector<int> output = {
		11,
		4,
		423
	};
	static constexpr int const& inputs = 3;
	vector<vector<int>> input1 = {
		{17,12,10,2,7,2,11,20,8},
		{1,2,4,1},
		{31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58}
	};
	vector<int> input2 = {
		3,
		3,
		11
	};
	vector<int> input3 = {
		4,
		3,
		2
	};
};