#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/n-queens/

class NQueens
{
public:
	// 12 ms, faster than 43.91% : 
	vector<vector<string>> solution(int n) {
		this->n = n;
		vector<vector<string>> ans;
		vector<string> set(n, string(n, '.'));
		curse(ans, set, 0);
		return ans;
	}
	int n;
	void curse(vector<vector<string>>& ans, vector<string>& set, int x) {
		int queens = fullBoard(set);
		if (queens) {
			if (queens == n) {
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++) {
						if (set[i][j] == 'X')
							set[i][j] = '.';
					}
				ans.push_back(set);
			}
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (set[i][x] == '.') {
				auto newSet = set;
				playQueen(newSet, i, x);
				curse(ans, newSet, x + 1);
			}
		}
	}
	void playQueen(vector<string>& set, int i, int j) {
		set[i][j] = 'Q';

		for (int k = 0; k < n; k++)
		{
			if (set[k][j] != 'Q')
				set[k][j] = 'X';
			if (set[i][k] != 'Q')
				set[i][k] = 'X';
		}
		for (int ki = i + 1, kj = j + 1; ki < n && kj < n; ki++, kj++)
			set[ki][kj] = 'X';
		for (int ki = i - 1, kj = j - 1; ki >= 0 && kj >= 0; ki--, kj--)
			set[ki][kj] = 'X';
		for (int ki = i - 1, kj = j + 1; ki >= 0 && kj < n; ki--, kj++)
			set[ki][kj] = 'X';
		for (int ki = i + 1, kj = j - 1; ki < n && kj >= 0; ki++, kj--)
			set[ki][kj] = 'X';

	}

	int fullBoard(vector<string>& set) {
		int queens = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (set[i][j] == '.') return 0;
				if (set[i][j] == 'Q') queens++;
			}
		}
		return queens;
	}

	vector<vector<vector<string>>> output = {
		{{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}},
		{{"Q"}},
	};
	vector<int> input1 = {
		4,
		1,
	};
};

