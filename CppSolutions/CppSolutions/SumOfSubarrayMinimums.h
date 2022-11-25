#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/sum-of-subarray-minimums/

class SumOfSubarrayMinimums
{
public:
	// 89 ms, faster than 98.49% : 40.8 MB, less than 81.41%
	int solution(vector<int> arr) {
		const int MOD = 1e9 + 7;
		stack<int> st;
		vector<int> mem(size(arr));

		for (size_t i = 0; i < size(arr); i++) {
			while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();

			if (!st.empty())
				mem[i] = mem[st.top()] + (i - st.top()) * arr[i];
			else
				mem[i] = (i + 1) * arr[i];

			st.push(i);
		}

		long long ans = 0;
		for (auto x : mem)
			ans += x, ans %= MOD;
		
		return ans;
	}
	vector<int> output = {
		17,
		444
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,1,2,4},
		{11,81,94,43,3}
	};
};