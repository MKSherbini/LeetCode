#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/destination-city/

class DestinationCity
{
public:
	// 4 ms, faster than 96.89% : 11 MB, less than 59.81%
	string solution(vector<vector<string>> paths) {
		unordered_map<string, int> m;
		for (auto& v : paths) {
			m[v[0]]++;
			m[v[1]]--;
		}
		for (auto& [s, c] : m) {
			if (c == -1) return s;
		}
		return "";
	}
	vector<string> output = {
		"Sao Paulo",
		"A",
		"Z"
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<string>>> input1 = {
		{{"London","NewYork"},{"NewYork","Lima"},{"Lima","Sao Paulo"}},
		{{"B","C"},{"D","B"},{"C","A"}},
		{{"A","Z"}}
	};
};