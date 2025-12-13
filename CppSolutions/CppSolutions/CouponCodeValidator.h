#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/coupon-code-validator

class CouponCodeValidator {
public:
    // 0 ms, faster than 100% : 67.86 MB, less than 87.28%
    vector<string> solution(vector<string> code, vector<string> businessLine, vector<uint8_t> isActive)
    {
        vector<string> validBisnessLine = { "electronics", "grocery", "pharmacy", "restaurant" };
        auto validCode = [&](const string& s) {
            for (char c : s) {
                if (!isalnum(c) && c != '_')
                    return false;
            }
            return !s.empty();
        };

        vector<int> ans;
        for (size_t i = 0; i < code.size(); i++) {
            Printer::print("checking index ", i);
            if (isActive[i] == false)
                continue;
            Printer::print("valid active");
            if (find(validBisnessLine.begin(), validBisnessLine.end(), businessLine[i]) == validBisnessLine.end())
                continue;
            Printer::print("valid business line");
            if (!validCode(code[i]))
                continue;
            Printer::print("valid code");
            ans.push_back(i);
        }

        sort(ans.begin(), ans.end(), [&](int i, int j) {
            int order1 = find(validBisnessLine.begin(), validBisnessLine.end(), businessLine[i]) - begin(validBisnessLine);
            int order2 = find(validBisnessLine.begin(), validBisnessLine.end(), businessLine[j]) - begin(validBisnessLine);
            if (order1 != order2)
                return order1 < order2;

            return code[i] < code[j];
        });

        Printer::print(ans);

        vector<string> ansStr;
        for (int i : ans) {
            ansStr.push_back(code[i]);
        }

        return ansStr;
    }
    vector<vector<string>> output = {
        { "PHARMA5", "SAVE20" },
        { "ELECTRONICS_50" }
    };
    static constexpr int const& inputs = 3;
    vector<vector<string>> input1 = {
        { "SAVE20", "", "PHARMA5", "SAVE@20" },
        { "GROCERY15", "ELECTRONICS_50", "DISCOUNT10" }
    };
    vector<vector<string>> input2 = {
        { "restaurant", "grocery", "pharmacy", "restaurant" },
        { "grocery", "electronics", "invalid" }
    };
    vector<vector<uint8_t>> input3 = {
        { true, true, true, true },
        { false, true, true }
    };
};