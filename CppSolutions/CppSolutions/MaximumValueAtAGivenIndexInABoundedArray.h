#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class MaximumValueAtAGivenIndexInABoundedArray
{
public:
	// 0 ms, faster than 100% : 5.9 MB, less than 92.49%
	int solution(int n, int index, int maxSum) {
		int sd1 = index, sd2 = n - 1 - index;
		int mn = min(sd1, sd2), dif = abs(sd1 - sd2);

		auto calcSum = [&](int top) -> long long {
			long long ret = 0;
			if (top > sd1) {
				ret += 1LL * (top + top - index) * (index + 1) / 2;
			}
			else {
				ret += 1LL * (top + 1) * top / 2 + index - top + 1;
			};
			if (top > sd2) {
				ret += 1LL * (top + top - n + 1 + index) * (n - index) / 2;
			}
			else {
				ret += 1LL * (top + 1) * top / 2 + n - index - top;
			}

			return ret - top;
		};
		int l = 0, r = maxSum;
		while (l < r) {
			int md = l + (r - l + 1) / 2;
			long long sum = calcSum(md);
			Printer::print(l, r, md, sum);
			if (sum <= maxSum) {
				l = md;
			}
			else {
				r = md - 1;
			}
		}
		Printer::print(l, r);
		return l;
	}
	// WA? num can be 0 ...
	int solution2(int n, int index, int maxSum) {
		int sd1 = index, sd2 = n - 1 - index;
		int mn = min(sd1, sd2), dif = abs(sd1 - sd2);

		auto sumAllUntil = [&](int x) -> long long {
			return  (1LL * x * (x + 1) / 2);
		};
		auto calcSum = [&](int top) -> long long {
			long long dec = sumAllUntil(top);
			long long ret = 2 * dec;
			if (top - sd1 - 1 > 0) ret -= sumAllUntil(top - sd1 - 1);
			if (top - sd2 - 1 > 0) ret -= sumAllUntil(top - sd2 - 1);

			Printer::print(dec, sumAllUntil(top - sd1 - 1), sumAllUntil(top - sd2 - 1));
			return ret - top;
		};
		int l = 0, r = maxSum;
		int lastMd = -1;
		while (l < r) {
			int md = l + (r - l) / 2;
			long long sum = calcSum(md);
			Printer::print(l, r, md, sum);
			if (lastMd == md) break;
			if (sum <= maxSum) {
				l = md;
			}
			else {
				r = md - 1;
			}
			lastMd = md;
		}
		Printer::print(l, r);
		if (l == r)
			return l;
		if (calcSum(r) <= maxSum) return r;
		return l;
	}
	vector<int> output = {
		2,
		3,
		7,
		24,
		1
	};
	static constexpr int const& inputs = 3;
	vector<int> input1 = {
		4,
		6,
		3,
		1,
		4
	};
	vector<int> input2 = {
		2,
		1,
		2,
		0,
		0
	};
	vector<int> input3 = {
		6,
		10,
		18,
		24,
		4
	};
};