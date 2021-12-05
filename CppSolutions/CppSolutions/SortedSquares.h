#pragma once
#include "stdc++.h"
using namespace std;

class SortedSquares
{
public:
	vector<int> solution(vector<int>& nums) {
		int x = 0, y = 0, i = 0, sz = nums.size();

		vector<int> ans(sz);

		x = lower_bound(begin(nums), end(nums), 0) - begin(nums);
		if (x == sz) x--;
		if (x > 0 && abs(nums[x - 1]) < abs(nums[x])) x = x - 1;
		y = x + 1;

		while (x >= 0 && y < sz) {
			cout << "xy " << i << " " << x << " " << y << endl;
			if (abs(nums[x]) < abs(nums[y]))
				ans[i++] = nums[x] * nums[x], x--;
			else
				ans[i++] = nums[y] * nums[y], y++;
		}

		while (x >= 0) {
			cout << "x " << i << " " << x << " " << y << endl;
			ans[i++] = nums[x] * nums[x], x--;
		}

		while (y < sz) {
			cout << "y " << i << " " << x << " " << y << endl;
			ans[i++] = nums[y] * nums[y], y++;
		}

		return ans;
	}
};

