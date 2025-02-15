#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-punishment-number-of-an-integer

class FindThePunishmentNumberOfAnInteger {
public:
    // 854 ms, faster than 5.04% : 11.18 MB, less than 61.46%
    int solution(int n)
    {
        function<bool(string, string, int)> f = [&](string x, string cur, int target) -> bool {
            if (target < 0)
                return 0;

            if (empty(x))
                return (target - stoi(cur)) == 0;

            cur.push_back(x.back());
            x.pop_back();

            return f(x, cur, target) || f(x, "0", target - stoi(cur));
        };

        int ans = 0;
        for (size_t i = 1; i <= n; i++) {
            string s = to_string(i * i);
            reverse(begin(s), end(s));
            if (f(s, "0", i)) {
                ans += i * i;
            }
        }

        return ans;
    }
    vector<int> output = {
        182,
        1478
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        10,
        37
    };
};