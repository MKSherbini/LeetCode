#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class MaximumLengthOfAConcatenatedStringWithUniqueCharacters
{
public:
	// 0 ms, faster than 100% : 10.5 MB, less than 78.59%
	int solution(vector<string> arr) {
		int ans = 0;
		vector<bitset<26>> v;
		for (auto& s : arr) {
			bitset<26> b;
			for (auto c : s)
				if (b.test(c - 'a'))
					goto end;
				else
					b.set(c - 'a');
			v.push_back(b);
		end:;
		}

		int n = size(v);
		function<int(int, bitset<26>)> f = [&](int i, bitset<26> taken) -> int {
			if (i == n) return 0;

			int ret = f(i + 1, taken);
			if ((taken & v[i]).none())
				ret = max(ret, (int)v[i].count() + f(i + 1, taken | v[i]));

			return ret;
		};

		return f(0, {});
	}

	// 0 ms, faster than 100% : 8 MB, less than 99.91%
	int solution4(vector<string> arr) {
		int ans = 0;
		int n = size(arr);

		Printer::printBinary((1 << n) - 1, 16);

		vector<bitset<26>> v;

		for (auto& s : arr) {
			bitset<26> b;
			for (auto c : s)
				if (b.test(c - 'a'))
					goto end;
				else
					b.set(c - 'a');
			v.push_back(b);
		end:;
		}
		f(v, {}, 0, (1 << n) - 1, ans);
		return ans;
	}

	void f(vector<bitset<26>>& arr, bitset<26> chars, int st, int ava, int& ans) {
		ans = max(ans, (int)chars.count());

		Printer::print("st: ", st);
		for (int i = st; i < size(arr); i++)
		{
			if (!(ava & (1 << i))) continue;

			Printer::print("i: ", i);

			if ((chars & arr[i]).none())
				f(arr, (chars | arr[i]), i + 1, ava & ~(1 << i), ans);
		}
	}

	// 42 ms, faster than 73.74% : 11.6 MB, less than 70.91%
	int solution3(vector<string> arr) {
		int ans = 0;
		int n = size(arr);
		vector<bool> chars(26, 0);

		Printer::printBinary((1 << n) - 1, 16);

		f(arr, chars, 0, (1 << n) - 1, ans, 0);
		return ans;
	}

	void f(vector<string>& arr, vector<bool>& chars, int st, int ava, int& ans, int len) {
		ans = max(ans, len);

		Printer::print("st: ", st);
		for (int i = st; i < size(arr); i++)
		{
			if (!(ava & (1 << i))) continue;

			auto vis = chars;

			for (auto c : arr[i]) {
				if (vis[c - 'a'])
					goto end;
				else
					vis[c - 'a'] = 1;
			}
			Printer::print("i: ", i, ava & ~(1 << i));

			f(arr, vis, i + 1, ava & ~(1 << i), ans, len + size(arr[i]));

		end:;
		}
	}

	// WA subsequence not subset
	int solution2(vector<string> arr) {
		int n = size(arr);
		int ans = 0;

		for (size_t i = 0; i < n; i++) {
			vector<bool> vis(26, 0);
			int len = 0;
			for (size_t j = i; j < n; j++) {
				for (auto c : arr[j]) {
					if (vis[c - 'a'])
						goto end;
					else
						vis[c - 'a'] = 1;
				}

				len += size(arr[j]);
			}
		end:
			Printer::print(i, len);
			ans = max(ans, len);
		}

		return ans;
	}
	vector<int> output = {
		4,
		6,
		26,
		16
	};
	static constexpr int const& inputs = 1;
	vector<vector<string>> input1 = {
		{"un","iq","ue"},
		{"cha","r","act","ers"},
		{"abcdefghijklmnopqrstuvwxyz"},
		{"ab","ba","cd","dc","ef","fe","gh","hg","ij","ji","kl","lk","mn","nm","op","po"}
	};
};