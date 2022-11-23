#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/perfect-squares/

class PerfectSquares
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 98.44%
	int solution(int n) {
		if (pow(round(sqrt(n)), 2) == n) return 1;
		for (size_t i = 1; i * i <= n; i++)
			if (pow(round(sqrt(n - i * i)), 2) == n - i * i) return 2;

		while (n % 4 == 0) n /= 4; // Legendre's 3-square theorem
		if (n % 8 != 7) return 3;

		return 4; // Legendre's 4-square theorem
	}

	// 107 ms, faster than 88.31% : 37.1 MB, less than 14.09%
	int solution2(int n) {
		queue<pair<int, int>> q;
		vector<int> nums;
		for (size_t i = 1; i * i <= n; i++)
			nums.push_back(i * i);

		q.push({ n, 0 });

		while (!q.empty()) {
			auto [x, cnt] = q.front();
			++cnt;
			q.pop();
			for (int i = size(nums) - 1; i >= 0; i--) {
				if (x - nums[i] == 0) return cnt;
				else if (x - nums[i] > 0)
					q.push({ x - nums[i], cnt });
			}
		}
		return -1;
	}
	vector<int> output = {
		3,
		2
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		12,
		13
	};
};