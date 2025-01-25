#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements

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
class MakeLexicographicallySmallestArrayBySwappingElements {
public:
    // 262 ms, faster than 43.92% : 165.88 MB, less than 70.27%
    vector<int> solution(vector<int> nums, int limit)
    {
        int n = size(nums);
        UnionFind dsu(n);
        vector<int> v(n);
        for (size_t i = 0; i < n; i++) {
            v[i] = i;
        }
        auto cmp = [&](const auto& i, const auto& j) {
            return nums[i] < nums[j];
        };
        sort(begin(v), end(v), cmp);
        for (size_t i = 1; i < n; i++) {
            if (nums[v[i]] - nums[v[i - 1]] <= limit)
                dsu.unionSet(v[i], v[i - 1]);
        }

        unordered_map<int, int> sets;
        int c = 0;
        for (size_t i = 0; i < n; i++) {
            if (!sets.count(dsu.findSet(i)))
                sets[dsu.findSet(i)] = c++;
        }

        vector<vector<int>> vs(size(sets));
        for (size_t i = 0; i < n; i++) {
            int p = dsu.findSet(i);
            vs[sets[p]].push_back(nums[i]);
        }

        for (size_t i = 0; i < size(sets); i++) {
            sort(begin(vs[i]), end(vs[i]), greater());
        }

        for (size_t i = 0; i < n; i++) {
            int p = dsu.findSet(i);
            nums[i] = vs[sets[p]].back();
            vs[sets[p]].pop_back();
        }

        return nums;
    }
    vector<vector<int>> output = {
        { 1, 3, 5, 8, 9 },
        { 1, 6, 7, 18, 1, 2 },
        { 1, 7, 28, 19, 10 }
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 1, 5, 3, 9, 8 },
        { 1, 7, 6, 18, 2, 1 },
        { 1, 7, 28, 19, 10 }
    };
    vector<int> input2 = {
        2,
        3,
        3
    };
};