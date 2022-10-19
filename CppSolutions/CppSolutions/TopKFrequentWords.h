#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/top-k-frequent-words/

class TopKFrequentWords
{
public:
	// 4 ms, faster than 99.62% : 12.3 MB, less than 95.61%
	vector<string> solution(vector<string> words, int k) {
		unordered_map<string, int> m;
		for (auto& w : words)
			m[w]++;

		vector<pair<string, int>> v(begin(m), end(m));
		sort(begin(v), end(v), [](auto& x, auto& y) { return x.second != y.second ? x.second > y.second : x.first < y.first; });

		vector<string> ans;
		for (size_t i = 0; i < k; i++)
			ans.push_back(v[i].first);

		return ans;
	}
	vector<vector<string>> output = {
		{"i","love"},
		{"the","is","sunny","day"}
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"i","love","leetcode","i","love","coding"},
		{"the","day","is","sunny","the","the","the","sunny","is","is"}
	};
	vector<int> input2 = {
		2,
		4
	};
};