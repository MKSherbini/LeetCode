#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-items-matching-a-rule/

class CountItemsMatchingARule
{
public:
	// 60 ms, faster than 98.02% : 30.8 MB, less than 78.85%
	int solution(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int cnt = 0;
		for (int i = 0; i < items.size(); i++)
		{
			int target = 0;
			if (ruleKey == "color") target = 1;
			else if (ruleKey == "name")	target = 2;
			if (items[i][target] == ruleValue) cnt++;
		}
		return cnt;
	}
	vector<int> output = {
		1,
		2,
	};
	vector<vector<vector<string>>> input1 = {
		{{"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}},
		{{"phone","blue","pixel"},{"computer","silver","phone"},{"phone","gold","iphone"}},
	};
	vector<string> input2 = {
		"color",
		"type",
	};
	vector<string> input3 = {
		"silver",
		"phone",
	};
};

