#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/greatest-common-divisor-traversal/?envType=daily-question&envId=2024-02-25

class UnionFind {
private:
	vector<int> p, ranks;
	int numsets;
public:
	UnionFind(int N) {
		p.assign(N, 0), numsets = N, ranks.assign(N, 0);

		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}

	bool sameSet(int i, int j) {
		return (findSet(i) == findSet(j));
	}

	void unionSet(int i, int j) {
		if (!sameSet(i, j)) {
			numsets--;
			int x = findSet(i), y = findSet(j);
			if (ranks[x] > ranks[y]) {
				p[y] = x;
			}
			else {
				p[x] = y;
				if (ranks[x] == ranks[y])
					ranks[y]++;
			}
		}
	}

	int numOfSets() {
		return numsets;
	}
};
class GreatestCommonDivisorTraversal
{
public:
	// 703 ms, faster than 52.69% : 301.1 MB, less than 16.77%
	uint8_t solution(vector<int> nums) {
		int n = size(nums);
		int mx = 1e5 + 1;
		if (n == 1) return 1;

		vector<int> sieve(mx);
		for (int d = 2; d < mx; d++) {
			if (sieve[d] == 0) {
				for (int v = d; v < mx; v += d) {
					sieve[v] = d;
				}
			}
		}

		UnionFind dsu(mx);
		for (auto x : nums) {
			if (x == 1) return 0;
			int t = x;
			int valid = 0;
			while (t > 1) {
				int prime = sieve[t];
				dsu.unionSet(prime, x);
				while (t % prime == 0) {
					t /= prime;
				}
			}
		}

		int p = dsu.findSet(nums[0]);
		for (int x : nums) {
			if (dsu.findSet(x) != p) {
				return 0;
			}
		}
		return 1;
	}
	vector<uint8_t> output = {
		true,
		false,
		true
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{2,3,6},
		{3,9,5},
		{4,3,12,8}
	};
};