#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/triangle/

class Triangle
{
public:
	// 3 ms, faster than 96.91% : 8.4 MB, less than 98.64%
	int solution(vector<vector<int>>& triangle) {
		for (int level = triangle.size() - 2; level >= 0; level--)
			for (int i = triangle[level].size() - 1; i >= 0; i--)
					triangle[level][i] = triangle[level][i] +
					min(triangle[level + 1][i],
						triangle[level + 1][i + 1]);

		return triangle[0][0];
	}
	// 4 ms, faster than 94.28% : 8.4 MB, less than 98.64%
	int solution3(vector<vector<int>>& triangle) {
		for (int level = 1; level < triangle.size(); level++)
			for (int i = 0; i < triangle[level].size(); i++)
				if (i == 0)
					triangle[level][i] = triangle[level][i] +
					triangle[level - 1][i];
				else if (triangle[level].size() - 1 == i)
					triangle[level][i] = triangle[level][i] +
					triangle[level - 1][i - 1];
				else
					triangle[level][i] = triangle[level][i] +
					min(triangle[level - 1][i],
						triangle[level - 1][i - 1]);

		return *min_element(begin(triangle[triangle.size() - 1]),
			end(triangle[triangle.size() - 1]));
	}

	// 3 ms, faster than 96.91% : 8.8 MB, less than 38.18%
	int solution2(vector<vector<int>>& triangle) {
		vector<vector<int>> mem(triangle);
		for (int i = 0; i < mem.size(); i++)
			for (int j = 0; j < mem[i].size(); j++)
				mem[i][j] = -1;
		return curse2(triangle, mem, 0, 0);
	}

	int curse2(vector<vector<int>>& triangle, vector<vector<int>>& mem, int level, int i) {
		if (level >= triangle.size() || i >= triangle[level].size()) return 0;

		if (mem[level][i] != -1) return mem[level][i];

		return mem[level][i] = (triangle[level][i] +
			min(curse2(triangle, mem, level + 1, i),
				curse2(triangle, mem, level + 1, i + 1)));
	}
	vector<int> output = {
		11,
		-10,
	};
	vector<vector<vector<int>>> input1 = {
		{{2},{3,4},{6,5,7},{4,1,8,3}},
		{{-10}},
	};
};

