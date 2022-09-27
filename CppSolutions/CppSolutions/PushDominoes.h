#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/push-dominoes/

class PushDominoes
{
public:
	// 26 ms, faster than 99.31% : 12.5 MB, less than 97.92%
	string solution(string dominoes) {
		int i = 0;

		while (i < size(dominoes)) {
			if (dominoes[i] == 'R') {
				int j = i + 1;
				int lastR = i;
				while (j < size(dominoes) && dominoes[j] != 'L') {
					if (dominoes[j] == 'R') lastR = j;
					j++;
				}
				// can also assume Rs and edit them later, bs kfaya kda zhe2t
				for (size_t k = i + 1; k < lastR; k++)
					dominoes[k] = 'R';
				if (j == size(dominoes)) {
					for (size_t k = lastR + 1; k < j; k++)
						dominoes[k] = 'R';
				}
				else {
					int diff = (j - lastR - 1) / 2;
					for (size_t k = 1; k <= diff; k++)
						dominoes[lastR + k] = 'R', dominoes[j - k] = 'L';
				}
				i = j + 1;
				Printer::print('R', i, j);
			}
			else if (dominoes[i] == '.') {
				int j = i + 1;
				while (j < size(dominoes) && dominoes[j] == '.')
					j++;
				if (j < size(dominoes) && dominoes[j] == 'L') {
					for (size_t k = i; k < j; k++)
						dominoes[k] = 'L';
				}
				Printer::print('.', i, j);
				i = j;
			}
			else
				i++;
		}
		return dominoes;
	}
	// 145 ms, faster than 12.83% : 40.7 MB, less than 5.03%
	string solution2(string dominoes) {
		list<int> l, r;

		for (int i = 0; i < size(dominoes); i++)
			if (dominoes[i] == 'R') r.push_back(i);
			else if (dominoes[i] == 'L') l.push_back(i);

		while (!l.empty() && !r.empty())
		{
			updateR(r, dominoes);
			Printer::print(dominoes);
			updateL(l, dominoes);
			Printer::print(dominoes);
		}
		while (!r.empty())
		{
			updateR(r, dominoes);
			Printer::print(dominoes);
		}
		while (!l.empty())
		{
			updateL(l, dominoes);
			Printer::print(dominoes);
		}

		return dominoes;
	}
	void updateR(list<int>& r, string& dominoes)
	{
		for (auto it = begin(r); it != end(r);) {
			int i = *it;
			if ((i + 1 == size(dominoes)) ||
				dominoes[i + 1] == 'L' ||
				(i + 2 < size(dominoes) && dominoes[i + 1] == '.' && dominoes[i + 2] == 'L')
				|| dominoes[i + 1] == 'R')
				r.erase(it++);
			else if (i + 3 < size(dominoes) && dominoes[i + 1] == '.' && dominoes[i + 2] == '.' && dominoes[i + 3] == 'L')
				dominoes[i + 1] = 'R', r.erase(it++), dominoes[i + 2] = 'L';
			else if (dominoes[i + 1] == '.')
				dominoes[i + 1] = 'R', * it = i + 1, ++it;

		}
	}
	void updateL(list<int>& l, string& dominoes)
	{
		for (auto it = begin(l); it != end(l);) {
			int i = *it;
			if ((i == 0) ||
				dominoes[i - 1] == 'R' ||
				(i - 2 >= 0 && dominoes[i - 1] == '.' && dominoes[i - 2] == 'R')
				|| dominoes[i - 1] == 'L')
				l.erase(it++);
			else if (dominoes[i - 1] == '.')
				dominoes[i - 1] = 'L', * it = i - 1, ++it;
		}
	}
	vector<string> output = {
		"RR.L",
		"LL.RR.LLRRLL..",
		"LLLLLL.RR.LLRRLL.."
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"RR.L",
		".L.R...LR..L..",
		".....L.R...LR..L.."
	};
};