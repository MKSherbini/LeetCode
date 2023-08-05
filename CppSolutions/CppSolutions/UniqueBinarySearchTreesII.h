#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/unique-binary-search-trees-ii/

class UniqueBinarySearchTreesII
{
public:
	// 6 ms, faster than 99.57% : 15.2 MB, less than 82.28%
	vector<TreeNode*> solution(int n) {
		vector mem(n + 1, vector(n + 1, vector<TreeNode*>()));

		function<vector<TreeNode*>(int, int)> f = [&](int from, int to) -> vector<TreeNode*> {
			if (from > to) return { NULL };
			if (!empty(mem[from][to])) return mem[from][to];
			if (from == to) return mem[from][to] = { new TreeNode(from) };

			vector<TreeNode*> ret;
			for (size_t i = from; i <= to; i++) {
				auto l = f(from, i - 1), r = f(i + 1, to);
				for (auto ll : l) {
					for (auto rr : r) {
						ret.push_back(new TreeNode(i, ll, rr));
					}
				}
			}

			return ret;
		};

		return f(1, n);
	}
	vector<vector<vector<int>>> output = {
		{{1,NULL,2,NULL,3},{1,NULL,3,2},{2,1,3},{3,1,NULL,NULL,2},{3,2,NULL,1}},
		{{1}}
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		3,
		1
	};
};