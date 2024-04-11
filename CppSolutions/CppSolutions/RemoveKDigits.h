#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/remove-k-digits/

class RemoveKDigits
{
public:
	// 7 ms, faster than 90.5% : 10 MB, less than 60.42%
	string solution(string num, int k) {
		stack<char> st;
		for (auto c : num) {
			while (!empty(st) && k > 0 && c < st.top()) {
				st.pop(), k--;
			}
			st.push(c);
		}

		while (k--) {
			st.pop();
		}

		string ans;
		while (!empty(st)) {
			ans.push_back(st.top());
			st.pop();
		}
		while (size(ans) > 1 && ans.back() == '0') {
			ans.pop_back();
		}

		reverse(begin(ans), end(ans));
		return empty(ans) ? "0" : ans;
	}
	vector<string> output = {
		"1219",
		"200",
		"0"
	};
	static constexpr int const& inputs = 2;
	vector<string> input1 = {
		"1432219",
		"10200",
		"10"
	};
	vector<int> input2 = {
		3,
		1,
		2
	};
};