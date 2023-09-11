#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class GroupThePeopleGivenTheGroupSizeTheyBelongTo
{
public:
	// 7 ms, faster than 87.01% : 12.6 MB, less than 80.59%
	vector<vector<int>> solution(vector<int> groupSizes) {
		int n = size(groupSizes);
		unordered_map<int, int> m;
		vector<vector<int>> ans;
		for (size_t i = 0; i < n; i++) {
			int sz = groupSizes[i];
			if (!m.count(sz) || size(ans[m[sz]]) == sz)
				ans.push_back({}), m[sz] = size(ans) - 1;
			ans[m[sz]].push_back(i);
		}

		return ans;
	}

	// 3 ms, faster than 98.93% : 13.1 MB, less than 66.73%
	vector<vector<int>> solution2(vector<int> groupSizes) {
		int n = size(groupSizes);
		unordered_map<int, vector<int>> m;
		for (size_t i = 0; i < n; i++) {
			m[groupSizes[i]].push_back(i);
		}

		vector<vector<int>> ans;
		for (auto& [sz, v] : m) {
			for (size_t i = 0; i < size(v); i++) {
				if (i % sz == 0)
					ans.push_back({});
				ans.back().push_back(v[i]);
			}
		}

		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{5},{0,1,2},{3,4,6}},
		{{1},{0,5},{2,3,4}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{3,3,3,3,3,1,3},
		{2,1,3,3,3,2}
	};
};