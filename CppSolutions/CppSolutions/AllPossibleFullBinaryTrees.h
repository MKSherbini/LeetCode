#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/all-possible-full-binary-trees/

class AllPossibleFullBinaryTrees
{
public:
	// 83 ms, faster than 99.41% : 27.9 MB, less than 76.77%
	// lambda again function style didn't work :)
	vector<TreeNode*> solution(int n) {
		mem.resize(n + 1);
		mem[1] = { new TreeNode(0) };
		if (n >= 3)
			mem[3] = { new TreeNode(0, mem[1][0], mem[1][0]) };
		return f(n);
	}
	vector<vector<TreeNode*>> mem;
	vector<TreeNode*> f(int n) {
		if (n % 2 == 0 || n == 0) return {};
		if (!empty(mem[n])) return mem[n];

		vector<TreeNode*> ret;
		for (size_t i = 1; i < n; i++) {
			auto l = f(i), r = f(n - i - 1);

			for (auto& ll : l)
				for (auto& rr : r)
					ret.push_back(new TreeNode(0, ll, rr));
		}


		return mem[n] = ret;
	};
	vector<vector<vector<int>>> output = {
		{{0,0,0,NULL,NULL,0,0,NULL,NULL,0,0},{0,0,0,NULL,NULL,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,NULL,NULL,NULL,NULL,0,0},{0,0,0,0,0,NULL,NULL,0,0}},
		{{0,0,0}}
	};
	static constexpr int const& inputs = 1;
	vector<int> input1 = {
		7,
		3
	};
};