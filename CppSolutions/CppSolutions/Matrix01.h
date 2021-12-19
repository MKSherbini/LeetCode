#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/01-matrix/

class Matrix01
{
public:
	vector<vector<int>> solution(vector<vector<int>>& mat) {
		vector<vector<int>> res(mat);
		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < mat[0].size(); j++)
			{
				mat[i][j] = -1;
			}
		}
		dfs(mat, res, 0, 0);
		return res;
	}
private:
	static const int OO = 9999999;
	int dfs(vector<vector<int>>& mat, vector<vector<int>>& res, int i, int j) {
		if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size()) return OO;

		int& ret = res[i][j];
		if (ret != -1) return ret;
		if (mat[i][j] == 0) return ret = 0;

		ret = OO;
		ret = min(ret, 1 + dfs(mat, res, i - 1, j));
		ret = min(ret, 1 + dfs(mat, res, i + 1, j));
		ret = min(ret, 1 + dfs(mat, res, i, j + 1));
		ret = min(ret, 1 + dfs(mat, res, i, j - 1));
		return ret;
	}
};

