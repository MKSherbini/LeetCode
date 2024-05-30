#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

class CountTripletsThatCanFormTwoArraysOfEqualXor {
public:
    // 58 ms, faster than 6.46% : 8.85 MB, less than 97.55%
    int solution(vector<int> arr)
    {
        int n = size(arr);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int r = 0;
                for (int k = i; k < j; k++) {
                    r ^= arr[k];
                }
                int l = 0;
                for (int k = j; k < n; k++) {
                    l ^= arr[k];
                    if (r == l)
                        ans++;
                }
            }
        }

        return ans;
    }

    // ??
    int solution2(vector<int> arr)
    {
        int n = size(arr);

        int all = 0;
        for (auto x : arr)
            all ^= x;

        int l = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int r = 0;

            for (int k = n - 1; k > i; k--) {
                int all2 = all ^ l ^ r;
                int l2 = 0;

                for (int j = i; j <= k; j++) {
                    l2 ^= arr[j];
                    all2 ^= arr[j];
                    ans += (l2 == all2);
                }

                r ^= arr[i];
            }

            l ^= arr[i];
        }

        return ans;
    }
    vector<int> output = {
        4,
        10,
        3
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 2, 3, 1, 6, 7 },
        { 1, 1, 1, 1, 1 },
        { 1, 3, 5, 7, 9 },
    };
};