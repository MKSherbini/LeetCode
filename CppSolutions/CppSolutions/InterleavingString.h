#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/interleaving-string/

class InterleavingString
{
public:
	// 63 ms, faster than 20.49% : 76.6 MB, less than 5.36%
	bool solution(string s1, string s2, string s3) {
		if (size(s1) + size(s2) != size(s3)) return false;
		if (size(s1) == 0) return equal(begin(s2), end(s2), begin(s3));
		if (size(s2) == 0) return equal(begin(s1), end(s1), begin(s3));

		this->s1 = s1;
		this->s2 = s2;
		this->s3 = s3;
		mem.assign(size(s1), vector(size(s2), vector(size(s3), -1)));
		return curse(0, 0, 0, 0);
	}
	bool curse(int i, int j, int k, int dir)
	{
		if (i >= size(s1) || j >= size(s2)) {
			if (i < size(s1) && dir != -1)
				return equal(begin(s1) + i, end(s1), begin(s3) + k);
			else if (j < size(s2) && dir != 1)
				return equal(begin(s2) + j, end(s2), begin(s3) + k);
			else
				return false;
		}
		Printer::print(i, j, k, dir);

		if (mem[i][j][k] != -1) return mem[i][j][k];

		bool ret = false;
		if (dir != -1)
			for (int x = i, y = k; x < size(s1) && y < size(s3) && s1[x] == s3[y]; ++x, ++y) {
				if (ret) return mem[i][j][k] = ret;
				ret |= curse(x + 1, j, y + 1, -1);
			}

		if (dir != 1)
			for (int x = j, y = k; x < size(s2) && y < size(s3) && s2[x] == s3[y]; ++x, ++y) {
				if (ret) return mem[i][j][k] = ret;
				ret |= curse(i, x + 1, y + 1, 1);
			}
		return mem[i][j][k] = ret;
	}

	string s1, s2, s3;
	vector<vector<vector<int>>> mem;

	vector<int> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 3;
	vector<string> input1 = {
		"aabcc",
		"aabcc",
		""
	};
	vector<string> input2 = {
		"dbbca",
		"dbbca",
		""
	};
	vector<string> input3 = {
		"aadbbcbcac",
		"aadbbbaccc",
		""
	};
};