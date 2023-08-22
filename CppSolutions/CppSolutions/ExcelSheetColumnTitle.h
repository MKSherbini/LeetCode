#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/excel-sheet-column-title/

class ExcelSheetColumnTitle
{
public:
	// 0 ms, faster than 100% : 5.8 MB, less than 79.56%
	string solution(int columnNumber) {
		string ans;
		const int base = 26;
		while (columnNumber >= 0) {
			columnNumber--;
			Printer::print((columnNumber % base), columnNumber / base);
			ans += 'A' + (columnNumber % base);
			columnNumber /= base;
			if (!columnNumber) break;
		}
		reverse(begin(ans), end(ans));

		return ans;
	}
	vector<string> output = {
		"A",
		"AB",
		"ZY"
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		1,
		28,
		701
	};
};