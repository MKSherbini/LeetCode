#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/defanging-an-ip-address/

class DefangingAnIpAddress
{
public:
	//
	string solution(string address) {
		return regex_replace(address, regex("\\."), "[.]");
	}
	vector<string> output = {
		"1[.]1[.]1[.]1",
		"255[.]100[.]50[.]0"
	};
	static constexpr int const& inputs = 1;
	vector<string> input1 = {
		"1.1.1.1",
		"255.100.50.0"
	};
};