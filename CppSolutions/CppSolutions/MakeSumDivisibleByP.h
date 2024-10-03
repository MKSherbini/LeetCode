#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/make-sum-divisible-by-p/description/

class MakeSumDivisibleByP {
public:
    // 111 ms, faster than 98.46% : 70.42 MB, less than 73.78%
    int solution(vector<int> nums, int p)
    {
        int n = size(nums);
        int target = 0;
        for (auto x : nums)
            target += x, target %= p;

        if (!target)
            return 0;

        int pre = 0;
        int ans = n;
        unordered_map<int, int> mods;
        mods[0] = -1;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            pre %= p;
            int need = pre - target + p;
            need %= p;
            if (mods.count(need)) {
                ans = min(ans, i - mods[need]);
            }

            Printer::print(pre);
            mods[pre] = i;
        }

        return ans == n ? -1 : ans;
    }

    // WA: mods can help reduce mod
    int solution2(vector<int> nums, int p)
    {
        int n = size(nums);
        vector<int> v(p);
        for (auto x : nums)
            v[x % p]++;

        int remLen = 0;
        unordered_map<int, int> rem;
        for (size_t i = 1; i <= p / 2; i++) {
            int dif = abs(v[i] - v[p - i]) % p;
            remLen += dif;
            if (v[i] > v[p - i])
                rem[i] = dif;
            else if (v[i] < v[p - i])
                rem[p - i] = dif;
        }

        if (remLen == n)
            return -1;

        if (remLen <= 1)
            return remLen;

        int i = 0, j = 0, ans = n;
        for (; j < n; j++) {
            if (rem.count(nums[j] % p)) {
                if (--rem[nums[j] % p] >= 0)
                    remLen--;
            }
            while (remLen == 0) {
                ans = min(ans, j - i + 1);
                if (rem.count(nums[i] % p)) {
                    if (++rem[nums[i] % p] >= 0)
                        remLen++;
                }
                i++;
            }
        }

        return ans;
    }
    vector<int> output = {
        1,
        2,
        0
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 3, 1, 4, 2 },
        { 6, 3, 5, 2 },
        { 1, 2, 3 }
    };
    vector<int> input2 = {
        6,
        9,
        3
    };
};