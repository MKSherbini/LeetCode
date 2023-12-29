#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/string-compression-ii/

class StringCompressionII
{
public:
	// 48 ms, faster than 78.65% : 8.7 MB, less than 71.91%
	int solution(string s, int k) {
		int n = size(s);
		vector<pair<int, int>> goals = { {0, 0}, {1, 1}, {9, 2}, {99, 3} };
		const int OO = 1e9;
		vector mem(n, vector<int>(k + 1, -1));
		auto countDigits = [](int x) {return x == 1 ? 0 : x <= 9 ? 1 : x <= 99 ? 2 : 3; };
		function<int(int, int)> f = [&](int i, int left) -> int {
			if (i + left >= n) return 0;

			auto& ret = mem[i][left];
			if (ret != -1) return ret;

			ret = left > 0 ? f(i + 1, left - 1) : OO;
			int freq = 1;
			for (size_t j = i + 1; j <= n; j++) {
				ret = min(ret, f(j, left) + 1 + countDigits(freq));
				if (j == n) break;
				if (s[i] == s[j]) freq++;
				else if (left > 0) left--;
				else break;
			}

			return ret;
		};
		f(0, k);
		Printer::print(mem);
		return f(0, k);
	}

	// WA
	int solution2(string s, int k) {
		vector<pair<char, int>> v;
		for (auto c : s) {
			if (empty(v) || v.back().first != c) {
				v.push_back({ c, 1 });
			}
			else {
				v.back().second++;
			}
		}

		Printer::print(v);
		vector<pair<int, int>> goals = { {0, 0}, {1, 1}, {9, 2}, {99, 3} };
		int n = size(v);
		function<int(int, int)> f = [&](int i, int left) -> int {
			if (i == n || left == 0) return 0;

			auto& [c, cnt] = v[i];
			int ret = INT_MAX;
			for (auto& [goal, len] : goals) {
				if (cnt <= goal) {
					break;
				}

				int d = cnt - goal;
				if (left >= d) {
					ret = min(ret, f(i + 1, left - d));
				}
			}

		};

		return f(0, k);
	}
	vector<int> output = {
		4,
		2,
		3
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"aaabcccd",
		"aabbaa",
		"aaaaaaaaaaa"
	};
	vector<int> input2 = {
		2,
		2,
		0
	};
};