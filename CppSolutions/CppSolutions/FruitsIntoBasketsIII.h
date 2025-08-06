#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/fruits-into-baskets-iii

class SegmentTree {
    int n;
    vector<int> t;

public:
    SegmentTree(vector<int>& nums)
        : n(size(nums))
        , t(2 * n, 0)
    {
        copy(begin(nums), end(nums), begin(t) + n);
    }
    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
        // Printer::print(t);
    }
    void modify(int p, int value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = max(t[p], t[p ^ 1]);
        // Printer::print(t);
    }
    int query(int l, int r)
    {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = max(res, t[l++]);
            if (r & 1)
                res = max(res, t[--r]);
        }
        // Printer::print(t);
        return res;
    }
};

class FruitsIntoBasketsIII {
public:
    // 323 ms, faster than 35.93% : 182.82 MB, less than 87.19%
    int solution(vector<int> fruits, vector<int> baskets)
    {
        int n = size(fruits);

        SegmentTree st(baskets);
        st.build();

        int ans = n;
        for (int i = 0; i < n; i++) {
            int l = 0, r = n - 1, res = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (st.query(0, mid + 1) >= fruits[i]) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (res != -1 && baskets[res] >= fruits[i]) {
                st.modify(res, 0);
                ans--;
            }
        }

        return ans;
    }
    vector<int> output = {
        1,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 4, 2, 5 },
        { 3, 6, 1 }
    };
    vector<vector<int>> input2 = {
        { 3, 5, 4 },
        { 6, 4, 7 }
    };
};