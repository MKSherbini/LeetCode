#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/min-cost-to-connect-all-points/

class UnionFind {
private:
	vector<int> p, ranks, setsize;
	int numsets;
	int maxSize = 0;
public:
	UnionFind(int N) {
		p.assign(N, 0), setsize.assign(N, 1), numsets = N, ranks.assign(N, 0);

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
				setsize[x] += setsize[y];
			}
			else {
				p[x] = y;
				setsize[y] += setsize[x];
				if (ranks[x] == ranks[y])
					ranks[y]++;
			}
		}
	}

	int numOfSets() {
		return numsets;
	}

	int sizeOfSet(int i) {
		return setsize[findSet(i)];
	}
};
class MinCostToConnectAllPoints
{
public:
	// 1630 ms, faster than 11.41% : 42.7 MB, less than 76.44%
	int solution(vector<vector<int>> points) {
		int n = size(points);
		UnionFind dsu(n);
		auto dis = [&](pair<int, int> x) {return abs(points[x.first][0] - points[x.second][0]) + abs(points[x.first][1] - points[x.second][1]); };
		auto cmp = [&](pair<int, int> x, pair<int, int> y) {return dis(x) > dis(y); };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		for (size_t i = 0; i < n; i++) {
			for (size_t j = i + 1; j < n; j++) {
				pq.push({ i,j });
			}
		}
		Printer::print(pq);

		int ans = 0;
		while (!pq.empty() || dsu.numOfSets() != 1) {
			auto& [x, y] = pq.top();

			if (!dsu.sameSet(x, y))
				dsu.unionSet(x, y), ans += dis(pq.top());

			pq.pop();
		}

		return ans;
	}
	vector<int> output = {
		20,
		18
	};
	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,0},{2,2},{3,10},{5,2},{7,0}},
		{{3,12},{-2,5},{-4,1}}
	};
};