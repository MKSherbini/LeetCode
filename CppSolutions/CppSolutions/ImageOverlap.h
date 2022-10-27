#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/image-overlap/

class ImageOverlap
{
public:
	// 126 ms, faster than 65.97% : 9.2 MB, less than 100%
	int solution(vector<vector<int>> img1, vector<vector<int>> img2) {
		int n = size(img1), m = size(img2);
		int ans = 0;
		for (int di = -n; di < n; di++)
			for (int dj = -m; dj < m; dj++) {
				int c = 0;
				for (int i = abs(di); i < n; i++)
					for (int j = abs(dj); j < m; j++) {
						int dx1 = (di < 0 ? di : 0), dy1 = (dj < 0 ? dj : 0), dx2 = -(di > 0 ? di : 0), dy2 = -(dj > 0 ? dj : 0);
						if (img1[i + dx1][j + dy1] == img2[i + dx2][j + dy2] && img2[i + dx2][j + dy2])
							++c;
					}
				ans = max(ans, c);
			}
		return ans;
	}

	// 203 ms, faster than 43.75% : 9.2 MB, less than 100%
	int solution2(vector<vector<int>> img1, vector<vector<int>> img2) {
		int n = size(img1), m = size(img2);
		int ans = 0;
		for (int di = -n; di < n; di++)
			for (int dj = -m; dj < m; dj++) {
				int c = 0;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
					{
						if (img2[i][j] && valid(i + di, n) && valid(j + dj, m))
							c += img1[i + di][j + dj] == img2[i][j];
					}
				ans = max(ans, c);
			}
		return ans;
	}
	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}

	vector<int> output = {
		3,
		1,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<int>>> input1 = {
		{{1,1,0},{0,1,0},{0,1,0}},
		{{1}},
		{{0}}
	};
	vector<vector<vector<int>>> input2 = {
		{{0,0,0},{0,1,1},{0,0,1}},
		{{1}},
		{{0}}
	};
};