#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/word-search-ii/


class WordSearchII
{
public:
	// 1002 ms, faster than 63.57% : 19.8 MB, less than 7.45%
	vector<string> solution(vector<vector<char>> board, vector<string> words) {
		int n = size(board), m = size(board[0]);
		auto trie = new TrieNode();

		for (auto& w : words)
			trie->add(w);

		Printer::print(trie);

		vector<string> ans;

		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				f(board, words, trie, ans, i, j);

		Printer::print(board);
		return ans;
	}

	void f(vector<vector<char>>& board, vector<string>& words, TrieNode* trie, vector<string>& ans, int i, int j) {
		if (!valid(i, size(board)) || !valid(j, size(board[0])) || board[i][j] == 0) return;
		trie = trie->next[board[i][j]];
		if (!trie) return;

		char t = board[i][j];
		board[i][j] = 0;
		if (trie->isTerminal) ans.push_back(trie->word), trie->remove();

		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };

		for (int k = 0; k < 4; k++)
			f(board, words, trie, ans, i + dx[k], j + dy[k]);

		board[i][j] = t;
	}

	bool valid(int x, int n) {
		return x >= 0 && x < n;
	}

	// WA, can move freely
	vector<string> solution2(vector<vector<char>> board, vector<string> words) {
		int n = size(board), m = size(board[0]);
		unordered_map<string, int> mp;

		for (int i = 0; i < size(words); i++) {
			mp[words[i]] = i;
			reverse(begin(words[i]), end(words[i]));
			mp[words[i]] = i;
			reverse(begin(words[i]), end(words[i]));
		}

		vector<string> ans;
		for (size_t i = 0; i < n; i++) {
			for (size_t sj = 0; sj < m; sj++) {
				string t = "";
				for (size_t j = sj; j < m; j++) {
					t += board[i][j];
					Printer::print(t);
					if (mp.contains(t)) ans.push_back(words[mp[t]]);
				}
			}
		}
		for (size_t i = 0; i < m; i++) {
			for (size_t sj = 0; sj < n; sj++) {
				string t = "";
				for (size_t j = sj; j < n; j++) {
					t += board[j][i];
					Printer::print(t);
					if (mp.contains(t)) ans.push_back(words[mp[t]]);
				}
			}
		}

		return ans;
	}
	vector<vector<string>> output = {
		{"eat","oath"},
		{},
		{"abc","abcd"}
	};
	static constexpr int const& inputs = 2;
	vector<vector<vector<char>>> input1 = {
		{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}},
		{{'a','b'},{'c','d'}},
		{{'a','b','c','e'},{'x','x','c','d'},{'x','x','b','a'}}
	};
	vector<vector<string>> input2 = {
		{"oath","pea","eat","rain"},
		{"abcb"},
		{"abc","abcd"}
	};
};