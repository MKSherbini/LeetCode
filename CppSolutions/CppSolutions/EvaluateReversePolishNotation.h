#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/evaluate-reverse-polish-notation/

class EvaluateReversePolishNotation
{
public:
	// 4 ms, faster than 99.01% : 12 MB, less than 93.63%
	int solution(vector<string> tokens) {
		stack<long long> st;
		for (auto& x : tokens) {
			if (x == "+") {
				long long x = st.top();
				st.pop();
				x += st.top();
				st.pop();
				st.push(x);
			}
			else if (x == "-") {
				long long x = st.top();
				st.pop();
				x = st.top() - x;
				st.pop();
				st.push(x);
			}
			else if (x == "*") {
				long long x = st.top();
				st.pop();
				x *= st.top();
				st.pop();
				st.push(x);
			}
			else if (x == "/") {
				long long x = st.top();
				st.pop();
				x = st.top() / x;
				st.pop();
				st.push(x);
			}
			else {
				st.push(stoi(x));
			}
		}

		return st.top();
	}
	vector<int> output = {
		9,
		6,
		22
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"2","1","+","3","*"},
		{"4","13","5","/","+"},
		{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
	};
};