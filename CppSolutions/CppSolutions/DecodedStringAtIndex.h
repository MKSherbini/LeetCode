#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/decoded-string-at-index/

class DecodedStringAtIndex
{
public:
	// 0 ms, faster than 100% : 6.3 MB, less than 11.71%
	string solution(string s, int k) {
		int n = size(s);
		vector<tuple<int, int, long long, long long>> points;
		int i = 0;
		while (i < n) {
			int st = i;
			while (i < n && isalpha(s[i])) {
				i++;
			}
			int end = i - 1;
			long long rep = 1;
			while (i < n && isdigit(s[i])) {
				rep *= s[i++] - '0';
			}

			long long curLen = ((empty(points) ? 0 : get<3>(points.back())) + (end - st + 1)) * rep;
			points.push_back({ st, end, rep, curLen });
			if (curLen >= k) break;
		}
		Printer::print(points);

		k--;
		for (int i = size(points) - 1; i >= 0; i--) {
			auto& [st, end, rep, curLen] = points[i];
			long long stride = curLen / rep;
			long long curStart = stride - (end - st + 1);
			k = k % stride;

			Printer::print(i, stride, curStart, k);
			if (k < curStart) continue;
			k -= curStart;
			return { s[st + k] };
		}

		return "";
	}

	// 0 ms, faster than 100% : 6.4 MB, less than 11.71%
	string solution2(string s, int k) {
		int n = size(s);
		vector<tuple<string, long long, long long>> points;
		int i = 0;
		while (i < n) {
			string t;
			while (i < n && isalpha(s[i])) {
				t += s[i++];
			}
			long long rep = 1;
			while (i < n && isdigit(s[i])) {
				rep *= s[i++] - '0';
			}

			long long curLen = ((empty(points) ? 0 : get<2>(points.back())) + size(t)) * rep;
			points.push_back({ t, rep, curLen });
			if (curLen >= k) break;
		}
		Printer::print(points);

		k--;
		for (int i = size(points) - 1; i >= 0; i--) {
			auto& [t, rep, curLen] = points[i];
			long long stride = curLen / rep;
			long long curStart = stride - size(t);
			k = k % stride;

			Printer::print(i, stride, curStart, k);
			if (k < curStart) continue;
			k -= curStart;
			return { t[k] };
		}

		return "";
	}
	vector<string> output = {
		"o",
		"h",
		"a",
		"c"
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"leet2code3",
		"ha22",
		"a2345678999999999999999",
		"a2b3c4d5e6f7g8h9"
	};
	vector<int> input2 = {
		10,
		5,
		1,
		10
	};
};