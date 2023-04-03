#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/boats-to-save-people/

class BoatsToSavePeople
{
public:
	// 83 ms, faster than 81.96% : 41.9 MB, less than 93.02%
	int solution(vector<int> people, int limit) {
		int i = 0;
		sort(begin(people), end(people));

		int ans = 0;
		for (int j = size(people) - 1; j >= i; j--) {
			if (j > 0 && people[j] + people[j - 1] <= limit) j--, Printer::print("j+j");
			else if (i != j && people[j] + people[i] <= limit) i++, Printer::print("j+i");
			ans++;
		}

		return ans;
	}
	vector<int> output = {
		1,
		3,
		4,
		2
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,2},
		{3,2,2,1},
		{3,5,3,4},
		{5,1,4,2}
	};
	vector<int> input2 = {
		3,
		3,
		5,
		6
	};
};