#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/word-search/

class WordSearch
{
public:
	// 433 ms, faster than 73.2% : 9.1 MB, less than 5.54%, better but small set
	bool solution(vector<vector<char>> board, string word) {
		TrieNode trie;
		trie.add(word);
		bool ret = false;
		for (size_t i = 0; i < board.size(); i++) {
			for (size_t j = 0; j < board[0].size(); j++) {
				ret |= f(board, &trie, 0, i, j);
				if (ret) break;
			}
		}

		return ret;
	}
	bool f(vector<vector<char>>& board, TrieNode* p, int curr, int i, int j) {
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*') return false;
		auto node = p->next[board[i][j]];
		if (!node) return false;
		char t = board[i][j];
		board[i][j] = '*';

		if (node->isTerminal) return true;

		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };

		bool ret = false;
		for (int z = 0; z < 4; z++) {
			ret |= f(board, node, curr + 1, i + dx[z], j + dy[z]);
			if (ret) break;
		}

		board[i][j] = t;

		return ret;
	}
	// 480 ms, faster than 55.83% : 7.8 MB, less than 91.39%
	bool solution2(vector<vector<char>> board, string word) {
		bool ret = false;
		for (size_t i = 0; i < board.size(); i++)
		{
			for (size_t j = 0; j < board[0].size(); j++)
			{
				ret |= curse(board, word, 0, i, j);
			}
		}
		return ret;
	}
	bool curse(vector<vector<char>>& board, string& word, int curr, int i, int j) {
		if (curr > word.size()) return false;
		if (curr == word.size()) return true;
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*') return false;
		//Printer::print(curr, board);

		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };

		bool ret = false;
		for (int z = 0; z < 4; z++)
		{
			if (board[i][j] != word[curr]) continue;
			char backup = board[i][j];
			board[i][j] = '*';
			ret |= curse(board, word, curr + 1, i + dx[z], j + dy[z]);
			board[i][j] = backup;
			if (ret) return ret;
		}
		return ret;
	}

	// TLE
	bool solutionX(vector<vector<char>> board, string word) {
		bool ret = false;
		for (size_t i = 0; i < board.size(); i++)
		{
			for (size_t j = 0; j < board[0].size(); j++)
			{
				ret |= curseX(board, word, "", i, j);

			}
		}
		return ret;
	}
	bool curseX(vector<vector<char>>& board, string& word, string tmp, int i, int j) {
		if (tmp.size() > word.size()) return false;
		if (!word.rfind(tmp, 0) == 0) return false;
		if (tmp == word) return true;
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*') return false;
		Printer::print(tmp, tmp.size(), word.size(), tmp == word);

		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };

		bool ret = false;
		for (int z = 0; z < 4; z++)
		{
			char backup = board[i][j];
			board[i][j] = '*';
			ret |= curseX(board, word, tmp + backup, i + dx[z], j + dy[z]);
			board[i][j] = backup;
			if (ret) return ret;
		}
		return ret;
	}
	vector<int> output = {
		true,
		true,
		false,
		true
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<char>>> input1 = {
		{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},
		{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},
		{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},
		{{'A'}}
	};
	vector<string> input2 = {
		"ABCCED",
		"SEE",
		"ABCB",
		"A"
	};
};