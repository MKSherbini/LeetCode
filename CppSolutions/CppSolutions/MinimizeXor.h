#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/minimize-xor

class MinimizeXor {
public:
    // 0 ms, faster than 100% : 7.76 MB, less than 91.12%
    int solution(int num1, int num2)
    {
        int n2 = __builtin_popcount(num2);

        bitset<32> b(num1), used;
        for (int i = 32 - 1; i >= 0; i--) {
            if (b.test(i)) {
                if (n2)
                    b.reset(i), used.set(i), n2--;
                else
                    break;
            }
        }

        for (size_t i = 0; i < 32; i++) {
            if (!b.test(i) && !used.test(i)) {
                if (n2)
                    b.set(i), used.set(i), n2--;
                else
                    break;
            }
        }

        return (int)(used.to_ulong());
    }
    vector<int> output = {
        3,
        3
    };
    static constexpr int const& inputs = 2;
    vector<int> input1 = {
        3,
        1
    };
    vector<int> input2 = {
        5,
        12
    };
};