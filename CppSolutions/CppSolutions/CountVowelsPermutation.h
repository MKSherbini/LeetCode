#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-vowels-permutation/

class CountVowelsPermutation
{
public:
	// 57 ms, faster than 59.97% : 21.5 MB, less than 45.17%
	int solution(int n) {
		vector<long> aeiou(5, 1);
		const int m = 1e9 + 7;

		for (size_t i = 2; i <= n; i++)
		{
			vector<long> t(aeiou);

			t[0] = aeiou[1];
			t[1] = aeiou[0] + aeiou[2];
			t[1] %= m;
			t[2] = (aeiou[0] + aeiou[1]) % m + (aeiou[3] + aeiou[4]) % m;
			t[2] %= m;
			t[3] = aeiou[2] + aeiou[4];
			t[3] %= m;
			t[4] = aeiou[0];

			aeiou = t;
		}

		int ans = 0;
		for (auto x : aeiou)
			ans += x, ans %= m;
		return ans;
	}
	vector<int> output = {
		5,
		10,
		68
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		1,
		2,
		5
	};
};