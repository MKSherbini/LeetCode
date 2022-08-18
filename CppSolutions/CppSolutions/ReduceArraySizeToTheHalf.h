#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/reduce-array-size-to-the-half/

class ReduceArraySizeToTheHalf
{
public:
	// 223 ms, faster than 89.92% : 78.2 MB, less than 84.42%
	int solution(vector<int> arr) {
		int n = size(arr);
		unordered_map<int, int> f;
		for (size_t i = 0; i < n; i++)
			f[arr[i]]++;

		Printer::print(f);
		priority_queue<int> p;
		while (!f.empty())
			p.push(f.begin()->second), f.erase(f.begin());

		Printer::print(p);
		int ans = 0, cnt = 0;
		while (!p.empty() && cnt < n / 2)
			ans++, cnt += p.top(), p.pop();

		return ans;
	}
	// 289 ms, faster than 68.95% : 97.5 MB, less than 5.75%
	int solution3(vector<int> arr) {
		int n = size(arr);
		unordered_map<int, int> f;
		for (size_t i = 0; i < n; i++)
			f[arr[i]]++;

		Printer::print(f);
		multiset<int, greater<int>> s;
		while (!f.empty())
			s.insert(f.begin()->second), f.erase(f.begin());

		Printer::print(s);
		int ans = 0, cnt = 0;
		while (!s.empty() && cnt < n / 2)
			ans++, cnt += *s.begin(), s.erase(s.begin());

		return ans;
	}
	// 232 ms, faster than 86.85% : 69.7 MB, less than 91.87%
	int solution2(vector<int> arr) {
		int n = size(arr);
		const int mx = 1e5 + 1;
		vector f(mx, 0);
		for (size_t i = 0; i < n; i++)
			f[arr[i]]++;

		sort(begin(f), end(f), greater());

		int ans = 0, cnt = 0;
		for (size_t i = 0; i < mx && cnt < n / 2; i++)
			ans++, cnt += f[i];

		return ans;
	}
	vector<int> output = {
		2,
		1,
		5
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,3,3,3,5,5,5,2,2,7},
		{7,7,7,7,7,7},
		{1,2,3,4,5,6,7,8,9,10}
	};
};