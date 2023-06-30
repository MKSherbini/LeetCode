#pragma once

class Printer
{
public:
	template<typename... Args>
	static void print(const Args&... args) {
	}
};
// assume answer and try to prove it with searching
// int vis = (taken & (1 << i));  taken | (1 << i)

// MinimumWindowSubstring, use frequence as equilibrium to check characters matching with sliding window
// SetMismatch, use array index and values +ve/-ve to mark visited

//const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//const vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
//for (auto [dx, dy] : dir)

//function<int(int, int)> valid = [&](int x, int n)->int {
//	return x >= 0 && x < n;
//};
bool valid(int x, int n) {
	return x >= 0 && x < n;
}

// 26 1 case, 

//	std::lower_bound - returns iterator to first element in the given range which is EQUAL_TO or Greater than val.
//	std::upper_bound - returns iterator to first element in the given range which is Greater than val.

// intersecting intervals min(a[1], b[1]) >= max(a[0], b[0])

//sort(begin(ans), end(ans));
//ans.erase(unique(begin(ans), end(ans)), end(ans));

//priority_queue<int, vector<int>, greater<int>> q;

// sum of all until n = n*(n+1)/2
// sum of odds = n*n, where n = number of odds

int gcd(int a, int b) {
	if (b > a) return gcd(b, a);
	return b == 0 ? a : gcd(b, a % b);
}