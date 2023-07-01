#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/fair-distribution-of-cookies/

class FairDistributionOfCookies
{
public:
	// 135 ms, faster than 74.44% : 6.7 MB, less than 100%
	int solution(vector<int> cookies, int k) {
		int n = size(cookies);
		vector<int> groups(k);

		const int OO = 1e7;
		function<int(int, int, int)> f = [&](int i, int mx, int empty)-> int {
			if (n - i < empty) return OO;

			if (i == n) {
				return mx;
			}

			int ret = OO;
			for (int8_t j = 0; j < k; j++) {
				empty -= groups[j] == 0;
				groups[j] += cookies[i];
				ret = min(ret, f(i + 1, max(mx, groups[j]), empty));
				groups[j] -= cookies[i];
				empty += groups[j] == 0;
			}

			return ret;
		};

		return f(0, 0, k);
	}
	// 1110 ms, faster than 64.45% : 136.5 MB, less than 5.4%
	int solution2(vector<int> cookies, int k) {
		int n = size(cookies);
		if (n == k) return *max_element(begin(cookies), end(cookies));
		if (n == 1) return accumulate(begin(cookies), end(cookies), 0);

		const int OO = 1e7;
		function<int(int, int)> f = [&](int i, int g)-> int {
			if (i == n) {
				vector<int> v(k);
				int ret = 0;
				for (size_t i = 0; i < n; i++) {
					int8_t c = (g >> (i * 3)) & 0b111;
					v[c] += cookies[i];
					ret = max(ret, v[c]);
				}
				return ret;
			}

			int ret = OO;
			for (int8_t c = 0; c < k; c++) {
				ret = min(ret, f(i + 1, g | (c << (i * 3))));
			}

			return ret;
		};

		return f(0, 0);
	}
	vector<int> output = {
		31,
		7
	};
	static constexpr int const& inputs = 2;
	vector<vector<int>> input1 = {
		{8,15,10,20,8},
		{6,1,3,2,2,4,1,2}
	};
	vector<int> input2 = {
		2,
		3
	};
};