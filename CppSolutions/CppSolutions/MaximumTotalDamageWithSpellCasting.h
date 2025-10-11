#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/maximum-total-damage-with-spell-casting

class MaximumTotalDamageWithSpellCasting {
public:
    // 358 ms, faster than 46.8% : 203.68 MB, less than 67.42%
    int solution(vector<int> power)
    {
        map<int, int> m;
        for (int p : power) {
            m[p]++;
        }
        vector<pair<int, int>> arr(m.begin(), m.end());
        int n = arr.size();

        vector mem(n, 0ll);
        mem.back() = 1ll * arr[n - 1].first * arr[n - 1].second;
        for (int i = n - 2; i >= 0; i--) {
            int next = i + 1;
            while (next < n && (arr[next].first == arr[i].first + 1 || arr[next].first == arr[i].first + 2))
                next++;
            mem[i] = max(mem[i + 1], 1ll * arr[i].first * arr[i].second + (next < n ? mem[next] : 0));
        }

        return mem[0];
    }

    // why TLE
    int solution3(vector<int> power)
    {
        Printer::print(power);
        map<int, int> m;
        for (int p : power) {
            m[p]++;
        }
        vector<pair<int, int>> arr(m.begin(), m.end());
        int n = arr.size();

        vector mem(n, -1ll);
        function<long long(int)> f = [&](int i) -> long long {
            if (i >= n)
                return 0;

            if (mem[i] != -1)
                return mem[i];

            long long ret = f(i + 1);

            int next = i + 1;
            while (next < n && (arr[next].first == arr[i].first + 1 || arr[next].first == arr[i].first + 2))
                next++;
            ret = max(ret, 1ll * arr[i].first * arr[i].second + f(next));

            return mem[i] = ret;
        };

        return f(0);
    }

    // why TLE
    int solution2(vector<int> power)
    {
        Printer::print(power);
        map<int, int> m;
        for (int p : power) {
            m[p]++;
        }
        vector<pair<int, int>> arr(m.begin(), m.end());
        int n = arr.size();

        vector mem(n, -1ll);
        function<long long(int, int)> f = [&](int i, int last) -> long long {
            if (i >= n)
                return 0;

            if (arr[i].first == last + 1 || arr[i].first == last + 2)
                return f(i + 1, last);

            if (mem[i] != -1)
                return mem[i];

            long long ret = f(i + 1, last);
            ret = max(ret, 1ll * arr[i].first * arr[i].second + f(i + 1, arr[i].first));

            return mem[i] = ret;
        };

        return f(0, -66);
    }
    vector<int> output = {
        6,
        13
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 1, 1, 3, 4 },
        { 7, 1, 6, 6 }
    };
};