#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/edit-distance/

class EditDistance
{
public:
	// 11 ms, faster than 77.86% : 6.5 MB, less than 93.87%
	int solution(string word1, string word2) {
		int n = size(word1), m = size(word2);
		vector<vector<int>> mem(2, vector<int>(m + 1, 0));
		
		bool cur = 0, other = 1;
		for (size_t j = 0; j < m; j++)
			mem[other][j] = m - j;

		for (int i = n - 1; i >= 0; i--) {
			mem[cur][m] = n - i;
			for (int j = m - 1; j >= 0; j--) {
				int ret = OO;
				if (word1[i] == word2[j])
					ret = min(ret, mem[other][j + 1]);
				ret = min(ret, 1 + mem[other][j]);
				ret = min(ret, 1 + mem[cur][j + 1]);
				ret = min(ret, 1 + mem[other][j + 1]);

				mem[cur][j] = ret;
			}
			other = cur;
			cur = !cur;
		}
		Printer::print(mem);
		return mem[other][0];
	}
	// 11 ms, faster than 77.86% : 9 MB, less than 63.2%
	int solution3(string word1, string word2) {
		int n = size(word1), m = size(word2);
		vector<vector<int>> mem(n + 1, vector<int>(m + 1, 0));

		for (size_t i = 0; i < n; i++)
			mem[i][m] = n - i;
		for (size_t j = 0; j < m; j++)
			mem[n][j] = m - j;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				int ret = OO;
				if (word1[i] == word2[j])
					ret = min(ret, mem[i + 1][j + 1]);
				ret = min(ret, 1 + mem[i + 1][j]);
				ret = min(ret, 1 + mem[i][j + 1]);
				ret = min(ret, 1 + mem[i + 1][j + 1]);

				mem[i][j] = ret;
			}
		}
		Printer::print(mem);
		return mem[0][0];
	}
	// 18 ms, faster than 53% : 8.9 MB, less than 64.49%
	int solution2(string word1, string word2) {
		vector<vector<int>> mem(word1.size(), vector<int>(word2.size(), -1));
		auto ret = curse(word1, word2, mem, 0, 0);
		Printer::print(mem);
		return ret;
	}
	int curse(string& s1, string& s2, vector<vector<int>>& mem, int i, int j) {
		if (i >= s1.size()) return s2.size() - j;
		if (j >= s2.size()) return s1.size() - i;
		if (mem[i][j] != -1) return mem[i][j];
		int ret = OO;
		if (s1[i] == s2[j])
			ret = curse(s1, s2, mem, i + 1, j + 1);

		ret = min(ret, 1 + curse(s1, s2, mem, i + 1, j));
		ret = min(ret, 1 + curse(s1, s2, mem, i, j + 1));
		ret = min(ret, 1 + curse(s1, s2, mem, i + 1, j + 1));
		return mem[i][j] = ret;
	}
	const int OO = (int)1e8;
	vector<int> output = {
		3,
		5
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"horse",
		"intention"
	};
	vector<string> input2 = {
		"ros",
		"execution"
	};
};