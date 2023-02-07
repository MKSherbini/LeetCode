#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/fruit-into-baskets/

class FruitIntoBaskets
{
public:
	// 117 ms, faster than 96.03% : 66.1 MB, less than 96.23%
	int solution(vector<int> fruits) {
		int n = size(fruits);
		vector<int> t(2, -1);

		int st = 0, ans = 0, c = 0;
		for (size_t i = 0; i < n; i++) {
			if (t[0] != -1 && t[1] != -1 && t[0] != fruits[i] && t[1] != fruits[i]) {
				st = i - 1, c = 0;
				t[0] = fruits[st], t[1] = fruits[i];
				while (st >= 0 && fruits[st] == t[0]) --st, ++c;
			}
			else if (t[0] == -1)
				t[0] = fruits[i];
			else if (t[1] == -1 && fruits[i] != t[0])
				t[1] = fruits[i];

			ans = max(ans, ++c);
			Printer::print(fruits[i], c, t[0], t[1]);
		}

		return ans;
	}
	vector<int> output = {
		3,
		3,
		3,
		4
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{1,2,1},
		{0,1,2,2},
		{0,1,1,4,3},
		{1,2,3,2,2}
	};
};