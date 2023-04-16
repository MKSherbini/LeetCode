#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

class NumberOfWaysToFormATargetStringGivenADictionary
{
public:
	// 286 ms, faster than 59.91% : 53.7 MB, less than 49.57%
	int solution(vector<string> words, string target) {
		int n = size(words[0]);
		int m = size(target);
		vector<vector<int>> v(n, vector<int>(26));
		vector<vector<int>> mem(n, vector<int>(m, -1));

		for (auto& w : words) {
			for (size_t i = 0; i < size(w); i++) {
				v[i][w[i] - 'a']++;
			}
		}
		int ret = f(mem, v, target, n - 1, m - 1);
		Printer::print(mem);
		return ret;
	}
	int f(vector<vector<int>>& mem, vector<vector<int>>& v, string& target, int i, int j) {
		if (i < 0 || j < 0) return j == -1;

		if (mem[i][j] != -1) return mem[i][j];
		long long ret = f(mem, v, target, i - 1, j);
		ret %= MOD;

		if (v[i][target[j] - 'a'])
			ret += 1LL * f(mem, v, target, i - 1, j - 1) * v[i][target[j] - 'a'], ret %= MOD;

		return mem[i][j] = ret;
	}
	const int MOD = 1e9 + 7;
	vector<int> output = {
		6,
		4
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"acca","bbbb","caca"},
		{"abba","baab"}
	};
	vector<string> input2 = {
		"aba",
		"bab"
	};
};
// 
// 
// 
// 
// 
// 
// 
// 

