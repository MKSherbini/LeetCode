#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/snakes-and-ladders/

class SnakesAndLadders
{
public:
	// 50 ms, faster than 34.12% : 23.1 MB, less than 9.87%
	int solution(vector<vector<int>> board) {
		int n = size(board);
		vector<pair<int, int>> v(n * n);
		vector<vector<int>> adj(n * n);
		vector<int> vis(n * n, 0);

		int x = n % 2 ? n - 1 : 0, y = 0, dir = n % 2 ? -1 : 1, f = 0;

		for (int i = n * n - 1; i >= 0; i--) {
			v[i] = { x, y - f };
			Printer::print(v[i], i);
			if (!f) x += dir;
			if (f) f = 0, dir *= -1, Printer::print("");
			if ((x == n - 1 && dir == 1) || (x == 0 && dir == -1)) y++, f = 1;
		}

		for (int i = 0; i < n * n - 1; i++) {
			for (int j = i + 1; j <= n * n - 1 && j <= i + 6; j++) {
				auto& xy = v[j];
				if (board[xy.second][xy.first] == -1)
					adj[i].push_back(j);
				else
					adj[i].push_back(board[xy.second][xy.first] - 1);
			}
		}
		Printer::print(adj);

		queue<int> q;
		q.push(0);
		vis[0] = 1;
		int ans = OO;
		while (!q.empty()) {
			auto& cur = q.front();
			if (cur == n * n - 1) {
				ans = vis[cur];
				break;
			}
			for (auto& nxt : adj[cur])
				if (!vis[nxt])
					q.push(nxt), vis[nxt] = vis[cur] + 1, Printer::print(cur, " -> ", nxt);
			q.pop();
		}

		return ans == OO ? -1 : ans - 1;
	}

	const int OO = 1e6;
	vector<int> output = {
		4,
		1,
		2
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}},
		{{-1,-1},{-1,1}},
		{{-1,-1,19,10,-1},{2,-1,-1,6,-1},{-1,17,-1,19,-1},{25,-1,20,-1,-1},{-1,-1,-1,-1,15}}

	};
};