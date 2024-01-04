#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/3sum/

class Sum3
{
public:
	// 141 ms, faster than 56.09% : 24.3 MB, less than 97.76%
	vector<vector<int>> solution(vector<int> nums) {
		sort(begin(nums), end(nums));
		vector<vector<int>> ans;
		for (int k = 0; k < (int)size(nums) - 2; k++) {
			if (k > 0 && nums[k] == nums[k - 1]) continue;

			int i = k + 1, j = size(nums) - 1;
			while (i < j) {

				if (nums[i] + nums[j] + nums[k] < 0) {
					i++;
				}
				else if (nums[i] + nums[j] + nums[k] > 0) {
					j--;
				}
				else {
					ans.push_back({ nums[i], nums[j], nums[k] });
					do {
						i++, j--;
					} while (i < j && nums[i] == nums[i - 1] && nums[j] == nums[j + 1]);
				}
			}
		}
		return ans;
	}

	// 80 ms, faster than 86.18% : 19.8 MB, less than 99.92%
	vector<vector<int>> solution4(vector<int> nums) {
		sort(begin(nums), end(nums));
		vector<vector<int>> ans;
		for (int i = 0; i < (int)nums.size() - 2; i++)
		{
			for (int j = i + 1, k = nums.size() - 1; k < nums.size() && j < nums.size() - 1 && k>j; j++)
			{
				int target = -nums[i] - nums[j];

				while (nums[k] > target) {
					k--;
					if (k <= j) break;
				}
				while (k != nums.size() && nums[k] == target) {
					if (k != i && k != j) {
						ans.push_back({ nums[i], nums[j], nums[k] });
						break;
					}
					k++;
				}

				if (j + 1 < nums.size() && nums[j] == nums[j + 1])
					j = upper_bound(begin(nums) + j + 1, end(nums), nums[j]) - begin(nums) - 1;

				if (i + 1 < nums.size() && nums[i] == nums[i + 1])
					i = upper_bound(begin(nums) + i + 1, end(nums), nums[i]) - begin(nums) - 1;
			}
		}
		return ans;
	}

	// 432 ms, faster than 16.47% : 19.8 MB, less than 99.92%
	vector<vector<int>> solution3(vector<int> nums) {
		if (nums.size() < 3) return {};
		sort(begin(nums), end(nums));
		vector<vector<int>> ans;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				int target = -nums[i] - nums[j];
				int k = lower_bound(begin(nums) + j + 1, end(nums), target) - begin(nums);

				if (k == nums.size() || nums[k] != target) continue;

				while (k != nums.size() && nums[k] == target) {
					if (k != i && k != j) {
						ans.push_back({ nums[i], nums[j], nums[k] });
						break;
					}
					k++;
				}

				if (j + 1 < nums.size() && nums[j] == nums[j + 1])
					j = upper_bound(begin(nums) + j + 1, end(nums), nums[j]) - begin(nums) - 1;

				if (i + 1 < nums.size() && nums[i] == nums[i + 1])
					i = upper_bound(begin(nums) + i + 1, end(nums), nums[i]) - begin(nums) - 1;
			}
		}
		return ans;
	}

	// 436 ms, faster than 16.41% : 21.1 MB, less than 45.53%
	vector<vector<int>> solution2(vector<int> nums) {
		if (nums.size() < 3) return {};
		sort(begin(nums), end(nums));
		//Printer::print(nums);
		vector<vector<int>> ans;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				int target = -nums[i] - nums[j];
				int k = lower_bound(begin(nums) + j + 1, end(nums), target) - begin(nums);

				if (k == nums.size() || nums[k] != target) continue;

				while (k != nums.size() && nums[k] == target) {
					if (k != i && k != j) {
						ans.push_back({ nums[i], nums[j], nums[k] });
						break;
					}
					k++;
				}
				while (j + 1 < nums.size() && nums[j] == nums[j + 1])
					j++;
				while (i + 1 < nums.size() && nums[i] == nums[i + 1])
					i++;
			}
		}
		return ans;
	}
	vector<vector<vector<int>>> output = {
		{{-1,-1,2},{-1,0,1}},
		{},
		{},
		{{-4,-2,6},{-4,0,4},{-4,1,3},{-4,2,2},{-2,-2,4},{-2,0,2}}
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{-1,0,1,2,-1,-4},
		{},
		{0},
		{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 }
	};
};

//1 2 3 4 5 6
//
//1
//2			3		 4		5
//3 4 5 6	  4 5 6    5 6	  6
//, [](vector<int> a, vector<int> b) {
//	cout << "comparing" << endl;
//	Printer::print(a);
//	Printer::print(b);
//	cout << "result: " << (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) << endl;
//	return a[0] == b[0] && a[1] == b[1] && a[2] == b[2]; })