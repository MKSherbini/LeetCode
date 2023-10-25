#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/k-th-symbol-in-grammar/

class KThSymbolInGrammar
{
public:
	// 0 ms, faster than 100% : 6.2 MB, less than 65.8%
	int solution(int n, int k) {
		function<bool(int, int)> f = [&](int n, int k) -> bool {
			if (n == 0) return 0;

			bool c = f(n - 1, k / 2);

			//return c ? (k % 2) ? 0 : 1 : (k % 2) ? 1 : 0;
			return c ^ (k % 2);
		};

		return f(n - 1, k - 1);
	}
	vector<int> output = {
		0,
		0,
		1
	};
	static constexpr int const& inputs = 2;
	vector<int> input1 = {
		1,
		2,
		2
	};
	vector<int> input2 = {
		1,
		1,
		2
	};
};