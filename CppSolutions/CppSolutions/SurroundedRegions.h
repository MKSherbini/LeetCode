#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/surrounded-regions/

class SurroundedRegions
{
public:
	// 7 ms, faster than 99.42% : 12.8 MB, less than 15.28%
	vector<vector<char>> solution(vector<vector<char>> board) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (!sink(board, i, j)) revert(board, i, j);
				if (board[i][j] == 'o') board[i][j] = 'X';
				else if (board[i][j] == 'x') board[i][j] = 'O';
			}
		}
		return board;
	}
	bool sink(vector<vector<char>>& board, int i, int j) {
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
			return 0;
		if (board[i][j] != 'O') return 1;
		board[i][j] = 'o';
		bool safe = 1;
		//Printer::printAll(i, j);

		int dx[] = { 0, 0,-1,+1 };
		int dy[] = { -1,+1, 0, 0 };
		for (int z = 0; z < 4; z++)
			safe &= sink(board, i + dx[z], j + dy[z]);

		return safe;
	}
	void revert(vector<vector<char>>& board, int i, int j) {
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
			return;
		if (board[i][j] != 'o') return;
		board[i][j] = 'x';
		//Printer::printAll(i, j);

		int dx[] = { 0, 0,-1,+1 };
		int dy[] = { -1,+1, 0, 0 };
		for (int z = 0; z < 4; z++)
			revert(board, i + dx[z], j + dy[z]);
	}
	vector<vector<vector<char>>> output = {
		{{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'},{'X','O','X','X'}},
		{{'X'}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<char>>> input1 = {
		{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'},{'X','O','X','X'}},
		{{'X'}}
	};
};