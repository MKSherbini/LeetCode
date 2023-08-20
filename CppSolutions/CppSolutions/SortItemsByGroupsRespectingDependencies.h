#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

class SortItemsByGroupsRespectingDependencies
{
public:
	// 153 ms, faster than 40.99% : 60.8 MB, less than 49.13%
	vector<int> solution(int n, int m, vector<int> group, vector<vector<int>> beforeItems) {
		for (size_t i = 0; i < n; i++) {
			if (group[i] == -1) group[i] = m++;
		}

		vector<set<int>> adjG(m);
		vector<vector<int>> adj(n);
		for (size_t i = 0; i < n; i++) {
			for (auto b4 : beforeItems[i]) {
				adj[i].push_back(b4);
				if (group[b4] != group[i])
					adjG[group[i]].insert(group[b4]);
			}
		}
		vector<int> groupOrder;
		set<int> visG;
		set<int> pg;
		function<bool(int)> fg = [&](int i) -> bool {
			if (pg.contains(i)) return true;
			if (visG.contains(i)) return false;
			pg.insert(i);
			visG.insert(i);

			int ret = 0;
			for (auto j : adjG[i]) {
				ret |= fg(j);
				if (ret) return ret;
			}

			pg.erase(i);
			groupOrder.push_back(i);

			return ret;
		};
		for (size_t i = 0; i < m; i++) {
			if (fg(i)) {
				return {};
			}
		}
		Printer::print(groupOrder);
		Printer::print(adj);

		set<int> vis;
		set<int> p;
		vector<int> order;
		function<bool(int)> f = [&](int i) -> bool {
			if (p.contains(i)) return true;
			if (vis.contains(i)) return false;
			p.insert(i);
			vis.insert(i);

			int ret = 0;
			for (auto j : adj[i]) {
				ret |= f(j);
				if (ret) return ret;
			}

			p.erase(i);
			order.push_back(i);

			return ret;
		};
		for (size_t i = 0; i < n; i++) {
			if (f(i)) {
				return {};
			}
		}
		Printer::print(order);

		vector<vector<int>> groups(m);
		for (int i : order) {
			groups[group[i]].push_back(i);
		}

		vector<int> ans;
		for (auto g : groupOrder) {
			for (auto x : groups[g])
				ans.push_back(x);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{6,3,4,1,5,2,0,7},
		{}
	};
	static constexpr int const& inputs = 4;
	vector<int> input1 = {
		8,
		8
	};
	vector<int> input2 = {
		2,
		2
	};
	vector<vector<int>> input3 = {
		{-1,-1,1,0,0,1,0,-1},
		{-1,-1,1,0,0,1,0,-1}
	};
	vector<vector<vector<int>>> input4 = {
		{{},{6},{5},{6},{3,6},{},{},{}},
		{{},{6},{5},{6},{3},{},{4},{}}
	};
};