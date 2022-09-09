#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

class TheNumberOfWeakCharactersInTheGame
{
public:
	// 788 ms, faster than 81.29% : 143.1 MB, less than 21.71%
	int solution(vector<vector<int>> properties) {
		auto cmp = [](const vector<int>& a, const vector<int>& b)
		{return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; };
		sort(begin(properties), end(properties), cmp);

		int mx = INT_MIN;

		int ans = 0;

		for (auto p : properties)
			if (mx > p[1]) ans++;
			else mx = p[1];

		Printer::print(properties);
		return ans;
	}
	////
	//int solution(vector<vector<int>> properties) {
	//	auto cmp = [](const vector<int>& a, const vector<int>& b)
	//	{return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0]; };
	//	auto cmp2 = [](const vector<int>& a, const vector<int>& b)
	//	{return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1]; };

	//	set<vector<int>, decltype(cmp)> properties1(cmp);
	//	set<vector<int>, decltype(cmp2)> properties2(cmp2);

	//	for (auto p : properties) // use indices
	//		properties1.insert(p), properties2.insert(p);

	//	removeUseless(properties1, properties2);
	//	removeUseless(properties2, properties1);

	//	int ans = 0;
	//	while (!properties1.empty())
	//	{
	//		auto last1 = prev(end(properties1));

	//		auto i = properties2.find(*last1);
	//		if (i != begin(properties2)) ans++;

	//		Printer::print(*last1, ans);
	//		properties1.erase(last1);
	//		properties2.erase(i);
	//		Printer::print(properties1, properties2);

	//		removeUseless(properties1, properties2);
	//		removeUseless(properties2, properties1);
	//	}


	//	return ans;
	//}
	//template<typename C1, typename C2>
	//void removeUseless(set<vector<int>, C1>& s1, set<vector<int>, C2>& s2) {
	//	while (size(s1) > 1)
	//	{
	//		auto last1 = prev(end(s1));
	//		auto prev1 = prev(last1);

	//		if ((*last1)[0] == (*prev1)[0]) {
	//			auto i = s2.find(*prev1);
	//			s1.erase(prev1);
	//			s2.erase(i);
	//		}
	//		else
	//			break;

	//	}
	//}
	//struct cmp {
	//	bool operator()(const vector<int>& a, const vector<int>& b)
	//	{
	//		return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
	//	};
	//};
	//struct cmp2 {
	//	bool operator()(const vector<int>& a, const vector<int>& b)
	//	{
	//		return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
	//	};
	//};

	vector<int> output = {
		1,
		3,
		0,
		1,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{1,1},{2,2},{1,2}, {2,1}},
		{{5,5},{6,3},{3,6}, {7,7}},
		{{5,5},{6,3},{3,6}},
		{{2,2},{3,3}},
		{{1,5},{10,4},{4,3}}
	};
};