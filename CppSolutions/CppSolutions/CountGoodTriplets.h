#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-good-triplets

class CountGoodTriplets {
public:
    // 3 ms, faster than 97.36% : 10.89 MB, less than 93.67%
    int solution(vector<int> arr, int a, int b, int c)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    vector<int> output = {
        4,
        0
    };
    static constexpr int const& inputs = 4;
    vector<vector<int>> input1 = {
        { 3, 0, 1, 1, 9, 7 },
        { 1, 1, 2, 2, 3 }
    };
    vector<int> input2 = {
        7,
        0
    };
    vector<int> input3 = {
        2,
        0
    };
    vector<int> input4 = {
        3,
        1
    };
};