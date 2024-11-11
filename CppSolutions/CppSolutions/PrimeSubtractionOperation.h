#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/prime-subtraction-operation

class PrimeSubtractionOperation {
public:
    // Meh 
    uint8_t solution2(vector<int> nums)
    {
        vector<int> sieve(1010, 1);
        for (size_t i = 2; i < size(sieve); i++) {
            if (!sieve[i])
                continue;
            for (size_t j = i + i; j < size(sieve); j += i) {
                sieve[j] = 0;
            }
        }

        auto it = 1009;
        for (int i = size(nums) - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                continue;

            while (it > 2 && (nums[i] <= it || !sieve[it])) {
                Printer::print(nums[i], it);
                it--;
            }
            nums[i] -= it;
            if (nums[i] < 1 || nums[i] >= nums[i + 1])
                return 0;
        }
        Printer::print(nums);
        return 1;
    }

    // 0 ms, faster than 100% : 32.33 MB, less than 9.9%
    uint8_t solution(vector<int> nums)
    {
        vector<int> sieve(1010, 1);
        vector<int> primes;
        for (size_t i = 2; i < size(sieve); i++) {
            if (!sieve[i])
                continue;
            primes.push_back(i);
            for (size_t j = i + i; j < size(sieve); j += i) {
                sieve[j] = 0;
            }
        }
        Printer::print(primes);

        for (int i = size(nums) - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                continue;

            auto it = upper_bound(
                begin(primes), end(primes),
                nums[i] - nums[i + 1]);
            while (nums[i] <= *it && it != begin(primes)) {
                it = prev(it);
            }
            nums[i] -= *it;
            if (nums[i] < 1 || nums[i] >= nums[i + 1])
                return 0;
        }
        Printer::print(nums);
        return 1;
    }
    vector<uint8_t> output = {
        true,
        true,
        false,
        false,
        false
    };
    static constexpr int const& inputs = 1;
    vector<vector<int>> input1 = {
        { 4, 9, 6, 10 },
        { 6, 8, 11, 12 },
        { 5, 8, 3 },
        { 17, 2 },
        { 2, 2 }
    };
};