#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/combinations/

class Combinations
{
public:
	vector<vector<int>> solution(int n, int k) {
		//vector<int> vis(21, 0);
		//findAll(arr, vis, n, k, {}, -1);
		vector<vector<int>> arr;
		curse(arr, n, k, {});
		return arr;
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

	void findAll(vector<vector<int>>& arr, vector<int>& vis, int n, int k, vector<int> row, int x) {
		if (row.size() == k) return arr.push_back(row);

		cout << "X: " << x << ", Visited: ";
		for (auto a : vis) {
			cout << a << " ";
		}
		cout << endl;

		if (x >= 1 && !vis[x]) {
			row.push_back(x);
			vis[x] = 1;
		}

		for (int j = max(x, 1); j <= n; j++)
		{
			//cout << "X: " << x << ", J: " << j << ", Visited: " << vis{j} << endl;
			if (!vis[j])
				findAll(arr, vis, n, k, row, j);
		}
		if (x >= 1)
			vis[x] = 0;
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
