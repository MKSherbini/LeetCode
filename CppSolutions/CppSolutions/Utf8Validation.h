#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/utf-8-validation/
#define test_bit(x, i) ((x) & (1 << (i)))

class Utf8Validation
{
public:
	// 11 ms, faster than 93.02% : 13.8 MB, less than 100%
	bool solution(vector<int> data) {
		int n = size(data);
		for (size_t i = 0; i < n; i++)
		{
			if (!test_bit_cnstexpr(data[i], 7)) continue;

			size_t j = 1;
			for (; j <= 3; j++)
			{
				if (test_bit_cnstexpr(data[i], 7 - j)) {
					Printer::print("next ", j);
					if (i + j >= n) return false;
					if (!(test_bit_cnstexpr(data[i + j], 7) && !test_bit_cnstexpr(data[i + j], 6))) return false;
				}
				else
					break;
			}
			Printer::print(j);
			if (j == 1 || test_bit_cnstexpr(data[i], 7 - j)) return false;
			i += j - 1;
		}
		return true;
	}
	constexpr bool test_bit_cnstexpr(uint8_t x, uint8_t i) { return ((x) & (1 << (i))); }

	// 6 ms, faster than 98.5% : 13.9 MB, less than 76.31%
	bool solution3(vector<int> data) {
		int n = size(data);
		for (size_t i = 0; i < n; i++)
		{
			if (!test_bit(data[i], 7)) continue;

			size_t j = 1;
			for (; j <= 3; j++)
			{
				if (test_bit(data[i], 7 - j)) {
					Printer::print("next ", j);
					if (i + j >= n) return false;
					if (!(test_bit(data[i + j], 7) && !test_bit(data[i + j], 6))) return false;
				}
				else
					break;
			}
			Printer::print(j);
			if (j == 1 || test_bit(data[i], 7 - j)) return false;
			i += j - 1;
		}
		return true;
	}

	// 18 ms, faster than 63.09% : 13.9 MB, less than 91.77%
	bool solution2(vector<int> data) {
		int n = size(data);
		for (size_t i = 0; i < n; i++)
		{
			bitset<8> s(data[i]);
			bitset<8> s2;

			Printer::print(s);
			if (!s.test(7)) continue;

			size_t j = 1;
			for (; j <= 3; j++)
			{
				if (s.test(7 - j)) {
					Printer::print("next ", j);
					if (i + j >= n) return false;
					s2 = data[i + j];
					Printer::print(s2);
					if (!(s2.test(7) && !s2.test(6))) return false;
				}
				else
					break;
			}
			Printer::print(j);
			if (j == 1 || s.test(7 - j)) return false;
			i += j - 1;
		}
		return true;
	}
	vector<int> output = {
		true,
		true,
		false,
		false,
		false,
		false
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{197,130,1},
		{247,140,130,130},
		{255,140,130,130},
		{235,140,4},
		{145},
		{240,162,138,147,145}
	};
};