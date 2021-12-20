#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/01-matrix/

class Matrix01
{
public:
	// DP
	// 48 ms, faster than 99.58% : 27.4 MB, less than 95.22%  
	vector<vector<int>> solution(vector<vector<int>>& mat) {
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


	// failed
private:
	static const int OO = 99999999;
	static const int OO_Vis = 88888888;
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

