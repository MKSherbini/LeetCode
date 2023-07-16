#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/smallest-sufficient-team/

class SmallestSufficientTeam
{
public:
	// 89 ms, faster than 71.61% : 85.1 MB, less than 22.58%
	vector<int> solution(vector<string> req_skills, vector<vector<string>> people) {
		int n = size(people);
		int k = size(req_skills);
		int full = (1 << k) - 1;

		unordered_map<string, int> skillIds;
		for (int i = 0; i < k; i++) {
			skillIds[req_skills[i]] = i;
		}

		vector<bitset<16>> skillSets(n);
		for (int i = 0; i < n; i++) {
			for (auto& s : people[i]) {
				skillSets[i].set(skillIds[s]);
			}
		}

		vector<vector<bitset<61>>> mem(n, vector<bitset<61>>(full, -1));
		function<bitset<61>(int, bitset<16>)> f = [&](int i, bitset<16> skillset)-> bitset<61> {
			if (skillset == full) return 0;
			if (i >= n) return full;
			int j = skillset.to_ulong();
			if (mem[i][j] != -1) return mem[i][j];

			bitset<61> ret = f(i + 1, skillset);

			bitset<16> newSkillSet = skillSets[i] | skillset;
			if (newSkillSet != skillset) {
				bitset<61> pick = f(i + 1, newSkillSet);
				if (pick.count() < ret.count())
					ret = pick.set(i);
			}

			return mem[i][j] = ret;
		};

		auto chosen = f(0, 0);
		vector<int> ans;
		for (size_t i = 0; i < 60; i++) {
			if (chosen.test(i))
				ans.push_back(i);
		}

		return ans;
	}

	// WA
	vector<int> solution2(vector<string> req_skills, vector<vector<string>> people) {
		int n = size(people);
		unordered_map<string, int> m;

		for (auto& p : people) {
			for (auto& s : p) {
				m[s]++;
			}
		}

		vector<int> ppl(n);
		iota(begin(ppl), end(ppl), 0);
		sort(begin(ppl), end(ppl), [&](const auto& a, const auto& b) { return size(people[a]) > size(people[b]); });

		vector<int> ans;
		for (int i = size(ppl) - 1; i >= 0; i--) {
			bool f = 1;
			for (auto& s : people[ppl[i]])
				f &= m[s] > 1;
			if (f) {
				for (auto& s : people[ppl[i]])
					m[s]--;
			}
			else ans.push_back(ppl[i]);
		}

		return ans;
	}
	vector<vector<int>> output = {
		{0,2},
		{1,2}
	};
	static constexpr int const& inputs = 2;
	vector<vector<string>> input1 = {
		{"java","nodejs","reactjs"},
		{"algorithms","math","java","reactjs","csharp","aws"}
	};
	vector<vector<vector<string>>> input2 = {
		{{"java"},{"nodejs"},{"nodejs","reactjs"}},
		{{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}}
	};
};