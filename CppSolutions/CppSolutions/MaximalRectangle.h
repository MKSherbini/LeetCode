#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximal-rectangle/

class MaximalRectangle
{
public:
	// 28 ms, faster than 79.84% : 16.7 MB, less than 87.72%
	int solution(vector<vector<char>> matrix) {
		int n = size(matrix), m = size(matrix[0]);
		vector<int> heights(m + 1);
		int ans = 0;

		for (size_t i = 0; i < n; i++) {
			stack<int> st;
			st.push(-1);

			for (size_t j = 0; j <= m; j++) {
				heights[j] = (j == m || matrix[i][j] == '0') ? 0 : heights[j] + 1;

				while (size(st) > 1 && (j == m || heights[j] < heights[st.top()])) {
					int h = st.top();
					st.pop();
					int w = j - st.top() - 1;
					int area = heights[h] * w;
					ans = max(ans, area);
				}
				st.push(j);
			}

			Printer::print(heights);
		}

		return ans;
	}
	vector<int> output = {
		6,
		0,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<char>>> input1 = {
		{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}},
		{{'0'}},
		{{'1'}}
	};
};