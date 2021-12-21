#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/build-array-from-permutation/

class RottingOranges
{
public:
	// 0 ms, faster than 100.00% : 13 MB, less than 76.31%
	int solution(vector<vector<int>>& mat) {
		int rows = mat.size();
		if (rows == 0)
			return 0;
		int cols = mat[0].size();
		int ans = 0;

		queue<pair<int, int>> q;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				switch (mat[i][j])
				{
				case 2:
					q.push({ i,j });
				case 0:
					mat[i][j] = 0;
					break;
				default:
					mat[i][j] = OO;
					break;
				}
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
					mat[x][y] = ret, q.push({ x,y }), ans = max(ans, ret);
			}
		}

		//for (auto a : mat) {
		//	for (auto b : a) {
		//		cout << b << " ";
		//	}
		//	cout << endl;
		//}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (mat[i][j] == OO) return -1;
			}
		}


		return ans;
	}

private:
	int8_t isValid(int x, int sz) {
		return x >= 0 && x < sz;
	}
	const int OO = INT_MAX - 100001;
};

