#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/next-greater-numerically-balanced-number

class NextGreaterNumericallyBalancedNumber {
public:
    // 527 ms, faster than 33.67% : 200.06 MB, less than 28.64%
    int solution(int n)
    {
        function<bool(int x)> f = [](int x) -> bool {
            vector<int> count(6, 0);
            while (x) {
                int d = x % 10;
                if (d == 0 || d > 6) {
                    return false;
                }
                count[d - 1]++;
                x /= 10;
            }

            for (int i = 0; i < 6; ++i) {
                if (count[i] != 0 && count[i] != i + 1) {
                    return false;
                }
            }

            return true;
        };

        for (int i = n + 1; i <= 1224444; i++) {
            if (f(i))
                return i;
        }

        return 666;
    }

    // WA has mixing digits
    int solution2(int n)
    {
        string row;
        vector<int> v;
        bitset<6> taken;
        function<void()> f = [&]() {
            if (taken.any()) {
                v.push_back(stoi(row));
            }

            for (int i = 1; i <= 6; ++i) {
                if (!taken.test(i - 1) && row.size() + i < 7) {
                    auto t = row;
                    row += string(i, '0' + i);
                    taken.set(i - 1);
                    f();
                    taken.reset(i - 1);
                    row = t;
                }
            }
        };

        f();
        sort(v.begin(), v.end());
        Printer::print(v);
        for (auto num : v) {
            if (num > n) {
                return num;
            }
        }
        return -1;
    }

    vector<int> output = {
        22,
        1333,
        3133
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        1,
        1000,
        3000
    };
};