#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/student-attendance-record-ii/description/

class StudentAttendanceRecordII {
public:
    // 995 ms, faster than 37.26% : 386.52 MB, less than 46.89%
    int solution(int n)
    {
        if (n == 1)
            return 3;

        vector mem(n, vector(2, vector(3, 0)));
        const int MOD = 1e9 + 7;
        for (size_t i = 0; i < n; i++) {
            mem[0][0][0] = 1;
            mem[0][0][1] = 1;
            mem[0][1][0] = 1;
        }

        int ans = 0;
        for (size_t i = 1; i < n; i++) {
            for (size_t a = 0; a < 2; a++) {
                for (size_t l = 0; l < 3; l++) {
                    mem[i][a][0] += mem[i - 1][a][l], mem[i][a][0] %= MOD; // 0 comes from any L

                    if (a > 0)
                        mem[i][a][0] += mem[i - 1][a - 1][l], mem[i][a][0] %= MOD; // a comes comes from A - 1 and any L, and becomes 0L

                    if (l > 0)
                        mem[i][a][l] += mem[i - 1][a][l - 1], mem[i][a][l] %= MOD; // L comes from L - 1

                    if (i == n - 1 && l != 0)
                        ans += mem[i][a][l], ans %= MOD;
                }

                if (i == n - 1)
                    ans += mem[i][a][0], ans %= MOD;
            }
        }

        Printer::print(mem);

        return ans;
    }

    //
    int solution2(int n)
    {
        vector mem(n, vector(2, vector(3, -1)));
        function<int(int, int, int)> f = [&](int i, int a, int l) -> int {
            if (i == n)
                return 1;

            int& ret = mem[i][a][l];
            if (ret != -1)
                return ret;

            ret = f(i + 1, a, 0);
            if (l < 3)
                ret += f(i + 1, a, l + 1);
            if (a < 1)
                ret += f(i + 1, a + 1, 0);

            return ret;
        };

        return f(0, 0, 0);
    }
    vector<int> output = {
        3,
        8,
        19,
        94
    };
    static constexpr int const& inputs = 1;
    vector<int> input1 = {
        1,
        2,
        3,
        5
    };
};