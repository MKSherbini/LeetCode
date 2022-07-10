#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/jump-game-vi/

class JumpGameVi
{
public:
	// 230 ms, faster than 80.23% : 90.2 MB, less than 52.95%
	int solution(vector<int> nums, int k) {
		int n = nums.size();

		priority_queue<pair<int, int>> pq;
		int ans = 0;

		for (int i = n - 1; i >= 0; i--) {
			while (!pq.empty() && pq.top().second > i + k)
				pq.pop();

			ans = nums[i] + (pq.empty() ? 0 : pq.top().first);
			pq.push({ ans, i });
		}
		return ans;
	}
	// 295 ms, faster than 56.42% : 93.5 MB, less than 42.46%
	int solution4(vector<int> nums, int k) {
		int n = nums.size();
		vector<int> mem(n, 0);

		priority_queue<pair<int, int>> pq;

		for (int i = n - 1; i >= 0; i--) {
			while (!pq.empty() && pq.top().second > i + k)
				pq.pop();

			mem[i] = nums[i] + (pq.empty() ? 0 : pq.top().first);
			pq.push({ mem[i], i });
		}
		return mem[0];
	}
	// TLE
	int solution3(vector<int> nums, int k) {
		vector<int> mem(size(nums), -OO);
		curse(nums, mem, size(nums) - 1, k);
		Printer::print(mem);
		return mem[size(nums) - 1];
	}
	int curse(vector<int>& nums, vector<int>& mem, int i, int k) {
		if (i == 0)
			return nums[0];

		if (mem[i] != -OO) return mem[i];

		int mx = -OO;

		for (int j = max(0, i - k); j < i; j++)
			mx = max(mx, nums[i] + curse(nums, mem, j, k));

		return mem[i] = mx;
	}

	const int OO = 1e9;

	//
	int solution2(vector<int> nums, int k) {
		priority_queue<int> q;

		size_t i = 1, end = min(size(nums), i + k);
		for (; i < end; i++)
			q.push(nums[i]);

		int ans = nums[0];

		while (!q.empty())
		{
			int picked = q.top() >= 0;

			while (!q.empty() && q.top() >= 0) {
				Printer::print(ans, q.top());
				ans += q.top(), q.pop();
			}

			if (!picked) {
				ans += q.top();
				Printer::print(q.top());
				if (size(nums) == end)
					break;
			}
			cout << endl;

			while (!q.empty()) q.pop();

			end = min(size(nums), i + 1 + k);
			for (; i < end; i++)
				q.push(nums[i]);
		}
		return ans;
	}
	vector<int> output = {
		7,
		17,
		0
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{1,-1,-2,4,-7,3},
		{10,-5,-2,4,0,3},
		{1,-5,-20,4,-1,3,-6,-3}
	};
	vector<int> input2 = {
		2,
		3,
		2
	};
};