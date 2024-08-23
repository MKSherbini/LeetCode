#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/fraction-addition-and-subtraction/description/

class FractionAdditionAndSubtraction {
public:
    // 0 ms, faster than 100% : 7.67 MB, less than 70.54%
    string solution(string expression)
    {
        int n = size(expression);

        pair<int, int> ans { 0, 1 };
        for (size_t i = 0; i < n; i++) {
            pair<int, int> p;
            int j = i + 1;
            while (expression[j] != '/') {
                j++;
            }
            p.first = stoi(expression.substr(i, j - i));
            j++;
            int sep = j;
            while (j < n && expression[j] != '-' && expression[j] != '+') {
                j++;
            }
            p.second = stoi(expression.substr(sep, j - sep));
            Printer::print(expression.substr(i, j - i));

            i = j - 1;
            int up = ans.second * p.first + ans.first * p.second;
            int down = ans.second * p.second;

            ans = { up, down };
            Printer::print(p);
            Printer::print(ans);
        }

        int t = abs(gcd(ans.first, ans.second));
        ans.first /= t;
        ans.second /= t;
        Printer::print(ans);

        return to_string(ans.first) + "/" + to_string(ans.second);
    }
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    vector<string> output = {
        "0/1",
        "1/3",
        "-1/6"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "-1/2+1/2",
        "-1/2+1/2+1/3",
        "1/3-1/2"
    };
};