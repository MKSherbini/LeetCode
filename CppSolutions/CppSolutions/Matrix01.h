#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/01-matrix/

class Matrix01
{
public:
	// DP
	// 48 ms, faster than 99.58% : 27.4 MB, less than 95.22%  
	vector<vector<int>> solution1(vector<vector<int>>& mat) {
		int rows = mat.size();
		if (rows == 0)
			return mat;
		int cols = mat[0].size();
		vector<vector<int>> res(rows, vector<int>(cols, INT_MAX - 100001));

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				int& ret = res[i][j];
				if (!mat[i][j]) {
					ret = 0;
					continue;
				}

				if (i > 0)
					ret = min(ret, 1 + res[i - 1][j]);
				if (j > 0)
					ret = min(ret, 1 + res[i][j - 1]);
			}
		}
		for (int i = rows - 1; i >= 0; i--)
		{
			for (int j = cols - 1; j >= 0; j--)
			{
				int& ret = res[i][j];
				if (i < rows - 1)
					ret = min(ret, 1 + res[i + 1][j]);
				if (j < cols - 1)
					ret = min(ret, 1 + res[i][j + 1]);
			}
		}
		return res;
	}

	// BFS
	// 68 ms, faster than 71.82% : 30.2 MB, less than 61.60%
	vector<vector<int>> solution2(vector<vector<int>>& mat) {
		int rows = mat.size();
		if (rows == 0)
			return mat;
		int cols = mat[0].size();
		vector<vector<int>> res(rows, vector<int>(cols, OO));

		queue<pair<int, int>> q;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (mat[i][j])
					res[i][j] = OO;
				else
					res[i][j] = 0, q.push({ i,j });
			}
		}

		while (!q.empty())
		{
			auto top = q.front(); q.pop();
			int i = top.first, j = top.second;

			int dx[] = { 1,-1,0,0 };
			int dy[] = { 0,0,1,-1 };

			for (int z = 0; z < 4; z++)
			{
				int x = i + dx[z], y = j + dy[z], ret = res[i][j] + 1;
				if (isValid(x, rows) && isValid(y, cols) && ret < res[x][y])
					res[x][y] = ret, q.push({ x,y });
			}
		}

		return res;
	}

	// BFS inplace
	// 60 ms, faster than 90.23% : 30 MB, less than 70.24%
	vector<vector<int>> solution(vector<vector<int>>& mat) {
		int rows = mat.size();
		if (rows == 0)
			return mat;
		int cols = mat[0].size();

		queue<pair<int, int>> q;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (mat[i][j])
					mat[i][j] = OO;
				else
					mat[i][j] = 0, q.push({ i,j });
			}
		}

		while (!q.empty())
		{
			auto top = q.front(); q.pop();
			int i = top.first, j = top.second;

			int dx[] = { 1,-1,0,0 };
			int dy[] = { 0,0,1,-1 };

			for (int z = 0; z < 4; z++)
			{
				int x = i + dx[z], y = j + dy[z], ret = mat[i][j] + 1;
				if (isValid(x, rows) && isValid(y, cols) && ret < mat[x][y])
					mat[x][y] = ret, q.push({ x,y });
			}
		}

		return mat;
	}
private:
	int8_t isValid(int x, int sz) {
		return x >= 0 && x < sz;
	}
	static const int OO = INT_MAX - 100001;
	static const int OO_Vis = 88888888;
	// failed
	int dfs(vector<vector<int>>& mat, vector<vector<int>>& res, int i, int j) {
		if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size()) return OO;

		int& ret = res[i][j];

		//printf("before1: i: %d, j: %d, res: %d\n", i, j, ret);
		if (ret != OO_Vis) {
			//printf("ignore visited\n");
			return ret;
		}
		if (mat[i][j] == 0) {
			//printf("assign 0\n");
			return ret = 0;
		}
		//printf("before2: i: %d, j: %d, res: %d\n", i, j, ret);
		ret = OO;
		ret = min(ret, 1 + dfs(mat, res, i - 1, j));
		ret = min(ret, 1 + dfs(mat, res, i + 1, j));
		ret = min(ret, 1 + dfs(mat, res, i, j + 1));
		ret = min(ret, 1 + dfs(mat, res, i, j - 1));
		//printf("after: i: %d, j: %d, res: %d\n", i, j, ret);
		return ret;
	}
};

