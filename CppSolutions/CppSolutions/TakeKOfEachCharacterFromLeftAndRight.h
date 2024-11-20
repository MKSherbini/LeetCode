#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right

class TakeKOfEachCharacterFromLeftAndRight {
public:
    // 13 ms, faster than 61.46% : 11.87 MB, less than 96.89%
    int solution(string s, int k)
    {
        if (!k)
            return k;

        vector<int> f(3);
        int n = size(s);
        for (int j = 0; j < n; j++) {
            f[s[j] - 'a']++;
        }

        if (f[0] < k || f[1] < k || f[2] < k)
            return -1;

        int ans = n + 1;
        int i = 0, j = 0;
        while (j < n) {
            f[s[j] - 'a']--;

            while (i <= j && (f[0] < k || f[1] < k || f[2] < k)) {
                f[s[i] - 'a']++;
                i++;
            }

            ans = min(ans, n - (j - i + 1));
            j++;
        }

        return ans;
    }

    // fk this
    int solution2(string s, int k)
    {
        if (!k)
            return k;

        vector<int> f(3);

        int n = size(s);
        int j = 0;
        for (; j < n; j++) {
            f[s[j] - 'a']++;
            if (f[0] >= k && f[1] >= k && f[2] >= k)
                break;
        }

        if (j == n)
            return -1;

        int i = n - 1;

        int ans = j + 1;
        while (j > 0) {
            while (f[0] >= k && f[1] >= k && f[2] >= k) {
                ans = min(ans, n - (i - j));
                f[s[j] - 'a']--;
                j--;
                if (j < 0 && (f[0] < k || f[1] < k || f[2] < k))
                    break;
                else if (j < 0)
                    return ans;

                Printer::print("j: ", j);
                Printer::print(f);
            }

            while (f[0] < k || f[1] < k || f[2] < k) {
                f[s[i] - 'a']++;
                i--;
                if (i < 0)
                    return i = n - 1;
                Printer::print("i: ", i);
                Printer::print(f);
            }
            if (j < 0) {
                ans = min(ans, n - (i - max(0, j) + 1));
                break;
            }
            ans = min(ans, n - (i - j + 1));
            Printer::print(i, j, ans);
        }

        return ans;
    }
    vector<int> output = {
        8,
        3,
        -1
    };
    static constexpr int const& inputs = 2;
    vector<string> input1 = {
        "aabaaaacaabc",
        "aabaaaacaabc",
        "a"
    };
    vector<int> input2 = {
        2,
        1,
        1
    };
};