#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/longest-square-streak-in-an-array
class UnionFind {
private:
    int numsets;

public:
    unordered_map<int, int> p, sizes;
    int mxSize = 1;
    UnionFind()
    {
        numsets = 0;
    }

    int findSet(int i)
    {
        if (p.find(i) == end(p))
            p[i] = i, ++numsets, sizes[i] = 1;
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
            p[x] = y;
            sizes[y] += sizes[x];
            mxSize = max(mxSize, sizes[y]);
        }
    }

    int numOfSets()
    {
        return numsets;
    }

    int maxOfSetSize()
    {
        return mxSize;
    }
};

class LongestSquareStreakInAnArray {
public:
    // 63 ms, faster than 58.57% : 109.08 MB, less than 50.31%
    int solution(vector<int> nums)
    {
        UnionFind dsu;
        unordered_set<int> s;

        for (auto x : nums)
            s.insert(x);

        for (auto x : s)
            if (x < 320 && s.count(x * x))
                dsu.unionSet(x, x * x);

        return dsu.maxOfSetSize() < 2 ? -1 : dsu.maxOfSetSize();
    }
    vector<int> output = {
        3,
        -1
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 4, 3, 6, 16, 8, 2 },
        { 2, 3, 5, 6, 7 }
    };
};