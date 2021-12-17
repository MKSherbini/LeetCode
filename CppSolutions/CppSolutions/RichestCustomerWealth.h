#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/richest-customer-wealth/

class RichestCustomerWealth
{
public:
	// 4 ms, faster than 90.39% : 7.8 MB, less than 50.02%
	int solution(vector<vector<int>>& accounts) {
		int mx = 0;
		for (int i = 0; i < accounts.size(); i++)
		{
			int w = 0;
			for (int j = 0; j < accounts[0].size(); j++)
			{
				w += accounts[i][j];
			}
			mx = max(mx, w);
		}
		return mx;
	}
};

