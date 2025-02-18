#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/construct-smallest-number-from-di-string

class ConstructSmallestNumberFromDiString {
public:
    // 0 ms, faster than 100% : 8.12 MB, less than 49.49%
    string solution(string pattern)
    {
        int n = size(pattern);

        string ans;
        function<bool(string)> f = [&](string s) -> bool {
            if (size(s) == n + 1) {
                ans = s;
                return true;
            }
            for (char c = '1'; c <= '9'; c++) {
                if (find(begin(s), end(s), c) != end(s)) {
					continue;
				}

                if (s.empty() || (pattern[size(s) - 1] == 'I' && c > s.back()) || (pattern[size(s) - 1] == 'D' && c < s.back())) {
					if (f(s + c)) {
						return true;
					}
				}
            }

            return false;
        };
        f("");

        return ans;
    }
    vector<string> output = {
        "123549876",
        "4321"
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "IIIDIDDD",
        "DDD"
    };
};