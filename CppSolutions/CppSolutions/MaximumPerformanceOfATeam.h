#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-performance-of-a-team/

class MaximumPerformanceOfATeam
{
public:
	// 83 ms, faster than 98.59% : 35.3 MB, less than 98.24%
	int solution(int n, vector<int> speed, vector<int> efficiency, int k) {
		const int mod = 1e9 + 7;
		auto effCmp = [](auto const& x, auto const& y)
		{return x.second != y.second ? x.second > y.second : x.first > y.first; };
		vector<pair<int, int>> eng(n);

		long long speeds = 0, eff = 0;
		long long ans = 0;

		for (size_t i = 0; i < n; i++)
			eng[i] = { speed[i], efficiency[i] };
		sort(begin(eng), end(eng), effCmp);
		Printer::print(eng);

		priority_queue<int, vector<int>, greater<int> > p;

		for (size_t i = 0; i < n; i++)
		{
			eff = eng[i].second;
			speeds += eng[i].first;
			p.push(eng[i].first);

			ans = max(ans, speeds * eff);
			if (size(p) == k) speeds -= p.top(), p.pop();
		}

		return ans % mod;
	}
	//
	//int solution(int n, vector<int> speed, vector<int> efficiency, int k) {
	//	const int mod = 1e9 + 7;
	//	auto effCmp = [](auto const& x, auto const& y)
	//	{return x.second != y.second ? x.second > y.second : x.first > y.first; };

	//	auto perfCmp = [](auto const& x, auto const& y)
	//	{return x.second * x.first > y.second * y.first; };
	//	vector<pair<int, int>> eng(n);

	//	long long speeds = 0, eff = 0;
	//	long long ans = 0;

	//	k--;
	//	for (size_t i = 0; i < n; i++) {
	//		eng[i] = { speed[i], efficiency[i] };
	//		if ((long long)speed[i] * efficiency[i] > ans)
	//			speeds = speed[i], eff = efficiency[i], ans = (long long)speed[i] * efficiency[i];
	//	}
	//	sort(begin(eng), end(eng), effCmp);
	//	Printer::print(eng);

	//	//auto speedCmp = [&](int x, int y)
	//	//{return eng[x].first != eng[y].first ? eng[x].first > eng[y].first : eng[x].second > eng[y].second; };
	//	auto speedCmp = [](auto const& x, auto const& y)
	//	{return x.first != y.first ? x.first < y.first : x.second < y.second; };


	//	int it = lower_bound(begin(eng), end(eng), pair{ speeds, eff }, effCmp) - begin(eng);
	//	Printer::print(it);
	//	priority_queue<int> p;
	//	for (size_t i = 0; i < it; i++)
	//		p.push(eng[i].first);

	//	Printer::print(p);
	//	it++;
	//	while (k--) {
	//		long long option1 = 0;
	//		if (!p.empty())
	//			option1 = (speeds + p.top()) * eff;
	//		long long option2 = 0;
	//		if (it < n)
	//			option2 = (speeds + eng[it].first) * eng[it].second;

	//		if (option1 > option2)
	//			ans = max(ans, option1), speeds += p.top(), p.pop();
	//		else
	//			ans = max(ans, option2), speeds += eng[it].first, eff = eng[it].second, it++;

	//		Printer::print(option1, option2);
	//	}


	//	return ans % mod;
	//}
	vector<int> output = {
		60,
		68,
		72,
		56
	};
	static constexpr int const& inputs = 4;
	vector<int> input1 = {
		6,
		6,
		6,
		3
	};
	vector<vector<int>> input2 = {
		{2,10,3,1,5,8},
		{2,10,3,1,5,8},
		{2,10,3,1,5,8},
		{2,8,2}
	};
	vector<vector<int>> input3 = {
		{5,4,3,9,7,2},
		{5,4,3,9,7,2},
		{5,4,3,9,7,2},
		{2,7,1}
	};
	vector<int> input4 = {
		2,
		3,
		4,
		2
	};
};