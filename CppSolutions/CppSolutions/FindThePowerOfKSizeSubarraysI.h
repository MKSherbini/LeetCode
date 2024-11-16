#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i

class FindThePowerOfKSizeSubarraysI {
public:
    // 2 ms, faster than 51.67% : 32.82 MB, less than 91.28%
    vector<int> solution(vector<int>& nums, int k)
    {
        if (k == 1)
            return nums;

        int n = size(nums);
        vector<int> ans(n - k + 1, -1);

        int c = k - 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                c--;
            } else {
                c = k - 1;
            }

            if (c <= 0) {
                ans[i - k + 1] = nums[i];
                cout << nums[i] << " " << c << endl;
            }
        }

        return ans;
    }
};