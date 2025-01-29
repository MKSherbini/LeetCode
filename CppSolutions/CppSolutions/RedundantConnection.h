#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/redundant-connection

class UnionFind {
private:
    vector<int> p, ranks, setsize;
    int numsets;
    int maxSize = 0;

public:
    UnionFind(int N)
    {
        p.assign(N, 0), setsize.assign(N, 1), numsets = N, ranks.assign(N, 0);

        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }

    bool sameSet(int i, int j)
    {
        return (findSet(i) == findSet(j));
    }

    void unionSet(int i, int j)
    {
        if (!sameSet(i, j)) {
            numsets--;
            int x = findSet(i), y = findSet(j);
            if (ranks[x] > ranks[y]) {
                p[y] = x;
                setsize[x] += setsize[y];
            } else {
                p[x] = y;
                setsize[y] += setsize[x];
                if (ranks[x] == ranks[y])
                    ranks[y]++;
            }
        }
    }

    int numOfSets()
    {
        return numsets;
    }

    int sizeOfSet(int i)
    {
        return setsize[findSet(i)];
    }
};
class RedundantConnection {
public:
    // 0 ms, faster than 100% : 12.72 MB, less than 93.59%
    vector<int> solution(vector<vector<int>> edges)
    {
        int n = size(edges);
        UnionFind dsu(n + 1);

        for (auto& e : edges) {
            if (!dsu.sameSet(e[0], e[1]))
                dsu.unionSet(e[0], e[1]);
            else
                return e;
        }

        return {};
    }
    vector<vector<int>> output = {
        { 2, 3 },
        { 1, 4 }
    };
    static constexpr int const& inputs = 1;
    vector<vector<vector<int>>> input1 = {
        { { 1, 2 }, { 1, 3 }, { 2, 3 } },
        { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 4 }, { 1, 5 } }
    };
};