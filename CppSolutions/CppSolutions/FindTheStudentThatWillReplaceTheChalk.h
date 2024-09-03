#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/

class FindTheStudentThatWillReplaceTheChalk {
public:
    // 89 ms, faster than 81.51% : 76.85 MB, less than 30.17%
    int solution(vector<int> chalk, int k)
    {
        long long round = accumulate(begin(chalk), end(chalk), 0ll);
        k %= round;
        for (size_t i = 0; i < size(chalk); i++) {
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        return 66;
    }
    vector<int> output = {
        0,
        1
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 5, 1, 5 },
        { 3, 4, 1, 2 }
    };
    vector<int> input2 = {
        22,
        25
    };
};