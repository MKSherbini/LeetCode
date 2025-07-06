#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/finding-pairs-with-a-certain-sum

class FindingPairsWithACertainSum {
public:
    // 63 ms, faster than 83.72% : 81.68 MB, less than 97.91%
    FindingPairsWithACertainSum(vector<int>& nums1, vector<int>& nums2)
        : nums1(nums1)
        , nums2(nums2)
    {
        sort(nums1.begin(), nums1.end());
        for (auto& x : nums2) {
            m[x]++;
        }
    }

    void add(int index, int val)
    {
        // remove old value
        auto it = m.find(nums2[index]);
        if (it != m.end()) {
            if (--it->second == 0) {
                m.erase(it);
            }
        }
        // add new value
        nums2[index] += val;
        m[nums2[index]]++;
    }

    int count(int tot)
    {
        int count = 0;
        for (auto& x : nums1) {
            int target = tot - x;
            auto it = m.find(target);
            if (it != m.end()) {
                count += it->second;
            }
        }
        return count;
    }

private:
    unordered_map<int, int> m;
    vector<int> nums1;
    vector<int> nums2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */