#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/combinations/

class Combinations
{
public:
	// 52 ms, faster than 29.92% : 69.8 MB, less than 21.69%
	vector<vector<int>> solution2(int n, int k) {
		vector<vector<int>> arr;
		curse2(1, arr, n, k, {});
		return arr;
	}

	// 12 ms, faster than 92.51% : 14.4 MB, less than 38.20%
	vector<vector<int>> solution(int n, int k) {
		vector<vector<int>> arr;
		curse(arr, n, k, {});
		return arr;
	}

	void curse2(int i, vector<vector<int>>& arr, int n, int k, vector<int> row) {
		if (row.size() == k) return arr.push_back(row);

		if (i > n) return;

		auto mx = max_element(begin(row), end(row));

		curse2(i + 1, arr, n, k, row);

		if (row.size() < k && row.size() + n - i + 1 >= k) {
			row.push_back(i);
			curse2(i + 1, arr, n, k, row);
		}
	}

	void curse(vector<vector<int>>& arr, int n, int k, vector<int> row) {
		if (row.size() == k) return arr.push_back(row);

		auto mx = max_element(begin(row), end(row));

		for (int i = mx == end(row) ? 1 : *mx + 1; i <= n; i++) {
			//cout
			//	<< "i: " << i << " , "
			//	<< "row.size(): " << row.size() << " , "
			//	<< "n: " << n << " , "
			//	<< "k: " << k << " , "
			//	<< "condtion: " << (row.size() < k && row.size() + n - i + 1 >= k) << " , "
			//	<< "row.size() + n - i: " << (row.size() + n - i + 1) << '\n';
			if (row.size() < k && row.size() + n - i + 1 >= k) {
				row.push_back(i);
				//cout << "row: ";
				//Printer<int>::print(row);
				curse(arr, n, k, row);
				row.erase((row.end() - 1));
			}
			else
				break;
		}
	}

	vector<vector<vector<int>>> output = {
		{{1,2}},
		{{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}},
		{{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}},
	};
	vector<int> input1 = {
		2,
		4,
		20,
	};
	vector<int> input2 = {
		2,
		2,
		20,
	};
};
