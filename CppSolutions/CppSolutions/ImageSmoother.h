#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/image-smoother/

class ImageSmoother
{
public:
	// 93 ms, faster than 7.12% : 41.2 MB, less than 5.64%
	vector<vector<int>> solution(vector<vector<int>> img) {
		int n = size(img), m = size(img[0]);
		vector<vector<int>> ans(img);

		function<bool(int, int)> valid = [&](int x, int n) -> bool {
			return x >= 0 && x < n;
		};
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
				int sm = img[i][j], c = 1;
				for (auto [dx, dy] : dir) {
					int ii = i + dx, jj = j + dy;
					if (valid(ii, n) && valid(jj, m))
						sm += img[ii][jj], c++;
				}
				ans[i][j] = sm / c;
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{0,0,0},{0,0,0},{0,0,0}},
		{{137,141,137},{141,138,141},{137,141,137}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,1,1},{1,0,1},{1,1,1}},
		{{100,200,100},{200,50,200},{100,200,100}}
	};
};