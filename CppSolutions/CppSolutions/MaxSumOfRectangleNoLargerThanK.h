#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

class MaxSumOfRectangleNoLargerThanK
{
public:
	// 662 ms, faster than 96.3% : 10.3 MB, less than 100%
	int solution(vector<vector<int>> matrix, int k) {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		int n = size(matrix);
		int m = size(matrix[0]);

		int sum[n + 1][m + 1];
		memset(sum, 0, sizeof(sum));
		for (size_t i = 1; i <= n; i++)
		{
			for (size_t j = 1; j <= m; j++)
			{
				sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}

		Printer::print(matrix);
		Printer::print(sum);

		int ans = INT_MIN;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				for (size_t endI = i + 1; endI <= n; endI++)
				{
					for (size_t endJ = j + 1; endJ <= m; endJ++)
					{
						int range = sum[endI][endJ] - sum[i][endJ] - sum[endI][j] + sum[i][j];
						Printer::print(i, j, endI, endJ, range);
						if (range == k) return k;
						else if (range < k) ans = max(ans, range);
					}
				}
			}
		}
		return ans;
	}

	// TLE
	int solution2(vector<vector<int>> matrix, int k) {
		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
		int n = size(matrix);
		int m = size(matrix[0]);

		//vector<vector<int>> sum(matrix);
		int sum[n][m];
		memset(sum, 0, sizeof(sum));
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				if (i > 0)
					sum[i][j] += sum[i - 1][j];
				if (j > 0)
					sum[i][j] += sum[i][j - 1];
				if (j > 0 && i > 0)
					sum[i][j] -= sum[i - 1][j - 1];

			}
		}

		Printer::print(matrix);
		Printer::print(sum);

		int ans = INT_MIN;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				for (size_t endI = i; endI < n; endI++)
				{
					for (size_t endJ = j; endJ < m; endJ++)
					{
						int range = sum[endI][endJ];
						if (i > 0) range -= sum[i - 1][endJ];
						if (j > 0) range -= sum[endI][j - 1];
						if (i > 0 && j > 0) range += sum[i - 1][j - 1];
						Printer::print(i, j, endI, endJ, range);
						if (range == k) return k;
						else if (range < k) ans = max(ans, range);
					}
				}
			}
		}
		return ans;
	}
	vector<int> output = {
		2,
		3,
		-1,
		3
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,0,1},{0,-2,3}},
		{{2,2,-1}},
		{{2,2,-1}},
		{{1,1,1},{1,1,1},{1,1,1}}
	};
	vector<int> input2 = {
		2,
		3,
		0,
		3
	};
};