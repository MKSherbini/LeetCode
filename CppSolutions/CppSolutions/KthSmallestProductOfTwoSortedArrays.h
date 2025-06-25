#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays

class KthSmallestProductOfTwoSortedArrays {
public:
    // 811 ms, faster than 6.04% : 97.95 MB, less than 90.33%
    long long solution(vector<int> nums1, vector<int> nums2, int k)
    {
        int n1 = nums1.size(), n2 = nums2.size();

        auto f = [&](long long md, int x) -> int {
            int left = 0, right = n2 - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                long long prod = 1ll * nums2[mid] * x;
                if ((x >= 0 && prod <= md) || (x < 0 && prod > md)) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (x >= 0) {
                return left;
            } else {
                return n2 - left;
            }
        };

        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i = 0; i < n1; i++) {
                count += f(mid, nums1[i]);
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
    vector<int> output = {
        8,
        0,
        -6
    };
    static constexpr int const& inputs = 3;
    vector<vector<int>> input1 = {
        { 2, 5 },
        { -4, -2, 0, 3 },
        { -2, -1, 0, 1, 2 }
    };
    vector<vector<int>> input2 = {
        { 3, 4 },
        { 2, 4 },
        { -3, -1, 2, 4, 5 }
    };
    vector<int> input3 = {
        2,
        6,
        3
    };
};