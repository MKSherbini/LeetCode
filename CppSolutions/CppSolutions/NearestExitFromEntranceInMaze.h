#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class NearestExitFromEntranceInMaze
{
public:
	// 165 ms, faster than 83.69% : 41.5 MB, less than 17.85%
	int solution(vector<vector<char>> maze, vector<int> entrance) {
		Printer::print(maze);
		int n = size(maze), m = size(maze[0]);
		queue<vector<int>> q;
		entrance.push_back(0);
		q.push(entrance);
		maze[entrance[0]][entrance[1]] = '+';
		int f = 0;
		while (!q.empty()) {
			auto cur = q.front();
			Printer::print(cur);
			q.pop();
			if (f && (cur[0] == 0 || cur[0] == n - 1 || cur[1] == 0 || cur[1] == m - 1)) return cur[2];
			if (!f) f = 1;
			++cur[2];
			Printer::print(maze);
			int dx[] = { 1,-1,0,0 };
			int dy[] = { 0,0,1,-1 };
			for (int i = 0; i < 4; i++) {
				int x = cur[0] + dx[i], y = cur[1] + dy[i];
				if (valid(x, n) && valid(y, m) && maze[x][y] == '.')
					q.push({ x, y, cur[2] }), maze[x][y] = '+';
			}
		}
		return -1;
	}
	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}

	vector<int> output = {
		1,
		2,
		-1
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<char>>> input1 = {
		{{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}},
		{{'+','+','+'},{'.','.','.'},{'+','+','+'}},
		{{'.','+'}}
	};
	vector<vector<int>> input2 = {
		{1,2},
		{1,0},
		{0,0}
	};
};