#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/bag-of-tokens/

class BagOfTokens
{
public:
	// 0 ms, faster than 100% : 13 MB, less than 55.08%
	int solution(vector<int> tokens, int power) {
		sort(begin(tokens), end(tokens));

		int i = 0, j = size(tokens) - 1;
		int ans = 0, score = 0;
		while (i <= j) {
			if (power >= tokens[i]) score++, power -= tokens[i++];
			else if (score > 0) score--, power += tokens[j--];
			else break;
			ans = max(ans, score);
		}

		return ans;
	}

	// 6 ms, faster than 84.07% : 10.5 MB, less than 67.18%
	int solution2(vector<int> tokens, int power) {
		sort(begin(tokens), end(tokens));
		Printer::print(tokens);
		int pwr = size(tokens) - 1;
		int ans = 0;

		for (int i = 0; i <= pwr; i++)
		{
			Printer::print(power, tokens[i], tokens[pwr], ans);
			if (power >= tokens[i]) {
				ans++;
				power -= tokens[i];
			}
			else if (ans > 0 && i != pwr && tokens[pwr] + power > tokens[i]) {
				power += tokens[pwr--] - tokens[i];
			}
			else
				break;
		}
		return ans;
	}
	vector<int> output = {
		0,
		1,
		2,
		0,
		2
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{100},
		{100,200},
		{100,200,300,400},
		{},
		{39,41,65,0,19}
	};
	vector<int> input2 = {
		50,
		150,
		200,
		10,
		33
	};
};