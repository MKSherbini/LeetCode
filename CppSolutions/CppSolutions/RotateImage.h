#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/rotate-image/

class RotateImage
{
public:
	// 0 ms, faster than 100% : 6.9 MB, less than 92.76%
	vector<vector<int>> solution(vector<vector<int>> matrix) {
		int n = size(matrix);
		for (size_t lvl = 0; lvl < n / 2; lvl++)
		{
			Printer::print(lvl);
			int last = n - lvl - 1;
			for (size_t i = lvl; i < last; i++)
			{
				int& topleft = matrix[lvl][i];
				int& botleft = matrix[n - i - 1][lvl];
				int& botright = matrix[last][n - i - 1];
				int& topright = matrix[i][last];
				Printer::print(topleft, topright);
				Printer::print(botleft, botright);
				Printer::print("");
				int x = topleft;
				topleft = botleft;
				botleft = botright;
				botright = topright;
				topright = x;
			}
		}
		return matrix;
	}
	vector<vector<vector<int>>> output = {
		{{7,4,1},{8,5,2},{9,6,3}},
		{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,2,3},{4,5,6},{7,8,9}},
		{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}
	};
};