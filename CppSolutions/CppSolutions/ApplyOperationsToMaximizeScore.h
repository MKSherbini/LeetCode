#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/apply-operations-to-maximize-score

class ApplyOperationsToMaximizeScore {
public:
    // 574 ms, faster than 26.83% : 311.74 MB, less than 10.36%
    int solution(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<int> sieve(1e5 + 1, 1);
        vector<int> primes;

        for (int i = 2; i < sieve.size(); i++) {
            if (sieve[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j < sieve.size(); j += i) {
                    sieve[j] = 0;
                }
            }
        }

        vector<int> primeScores(n);
        for (int index = 0; index < n; index++) {
            int num = nums[index];

            for (auto prime : primes) {
                if (prime * prime > num)
                    break;
                if (num % prime != 0)
                    continue;
                primeScores[index]++;
                while (num % prime == 0)
                    num /= prime;
            }
            if (num > 1)
                primeScores[index]++;
        }

        Printer::print(primeScores);
        vector<int> nextHigh(n, n), prevHigh(n, -1);
        stack<int> st;

        for (int index = 0; index < n; index++) {
            while (!st.empty() && primeScores[st.top()] < primeScores[index]) {
                nextHigh[st.top()] = index;
                st.pop();
            }
            st.push(index);
        }

        while (!st.empty())
            st.pop();

        for (int index = n - 1; index >= 0; index--) {
            while (!st.empty() && primeScores[st.top()] <= primeScores[index]) {
                prevHigh[st.top()] = index;
                st.pop();
            }
            st.push(index);
        }

        auto cmp = [&](int a, int b) {
            return nums[a] < nums[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (int index = 0; index < n; index++) {
            pq.push(index);
        }

        int MOD = 1e9 + 7;
        auto pwr = [&](long long a, int b) {
            long long ret = 1;
            while (b > 0) {
                if (b & 1) {
                    ret *= a;
                    ret %= MOD;
                }
                a *= a;
                a %= MOD;
                b >>= 1;
            }
            return ret;
        };
        long long ans = 1;
        while (k > 0) {
            int index = pq.top();
            pq.pop();

            long long subs = 1ll * (nextHigh[index] - index) * (index - prevHigh[index]);
            if (subs > k) {
                subs = k;
            }
            k -= subs;

            Printer::print(nums[index], nextHigh[index], prevHigh[index], subs);
            ans *= pwr(nums[index], subs);
            ans %= MOD;
        }

        return ans;
    }
    vector<int> output = {
        81,
        4788,
        256720975
    };
    static constexpr int const& inputs = 2;
    vector<vector<int>> input1 = {
        { 8, 3, 9, 3, 8 },
        { 19, 12, 14, 6, 10, 18 },
        { 3289, 2832, 14858, 22011 }
    };
    vector<int> input2 = {
        2,
        3,
        6
    };
};