#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/search-suggestions-system/

class SearchSuggestionsSystem
{
public:
	// 232 ms, faster than 38.79% : 67.8 MB, less than 56.93%
	vector<vector<string>> solution(vector<string> products, string searchWord) {
		unordered_map<string, vector<int>> m;

		for (size_t i = 0; i < products.size(); i++)
		{
			string pre = "";
			for (size_t j = 0; j < products[i].size(); j++)
			{
				pre += products[i][j];
				if (m[pre].size() < 3)
					m[pre].push_back(i);
				else if (products[i] < products[m[pre][2]])
					m[pre][2] = i;

				sort(begin(m[pre]), end(m[pre]), [&](int x, int y) {return products[x] < products[y]; });
			}
		}

		vector<vector<string>> ans(searchWord.size());

		string pre = "";
		for (size_t i = 0; i < ans.size(); i++)
		{
			pre += searchWord[i];
			vector<string> v;
			transform(begin(m[pre]), end(m[pre]),
				back_inserter(v), [&](int x) {return products[x]; });
			ans[i] = v;
		}
		return ans;
	}

	// 247 ms, faster than 36.39% : 67.7 MB, less than 56.93%
	vector<vector<string>> solution2(vector<string> products, string searchWord) {
		unordered_map<string, vector<int>> m;

		for (size_t i = 0; i < products.size(); i++)
		{
			string pre = "";
			for (size_t j = 0; j < products[i].size(); j++)
			{
				pre += products[i][j];
				if (m[pre].size() < 4)
					m[pre].push_back(i);
				else
					m[pre][3] = i;

				sort(begin(m[pre]), end(m[pre]), [&](int x, int y) {return products[x] < products[y]; });
			}
		}

		vector<vector<string>> ans(searchWord.size());

		string pre = "";
		for (size_t i = 0; i < ans.size(); i++)
		{
			pre += searchWord[i];
			vector<string> v;
			transform(begin(m[pre]), m[pre].size() > 3 ? begin(m[pre]) + 3 : end(m[pre]),
				back_inserter(v), [&](int x) {return products[x]; });
			ans[i] = v;
		}
		return ans;
	}
	vector<vector<vector<string>>> output = {
		{{"mobile","moneypot","monitor"},{"mobile","moneypot","monitor"},{"mouse","mousepad"},{"mouse","mousepad"},{"mouse","mousepad"}},
		{{"havana"},{"havana"},{"havana"},{"havana"},{"havana"},{"havana"}},
		{{"baggage","bags","banner"},{"baggage","bags","banner"},{"baggage","bags"},{"bags"}}
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"mobile","mouse","moneypot","monitor","mousepad"},
		{"havana"},
		{"bags","baggage","banner","box","cloths"}
	};
	vector<string> input2 = {
		"mouse",
		"havana",
		"bags"
	};
};