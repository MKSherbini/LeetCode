#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/design-browser-history/

class DesignBrowserHistory
{
public:
	// 120 ms, faster than 98.57% : 56.6 MB, less than 99.05%
	DesignBrowserHistory(string homepage) {
		v.push_back(homepage);
	}

	void visit(string url) {
		if (i + 1 == size(v)) {
			v.push_back(url);
		}
		else {
			v[i + 1] = url;
		}
		i = last = i + 1;
	}

	string back(int steps) {
		i = max(0, i - steps);
		return v[i];
	}

	string forward(int steps) {
		i = min(last, i + steps);
		return v[i];
	}
private:
	vector<string> v;
	int i = 0;
	int last = 0;
};