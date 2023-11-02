#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

class CountNodesEqualToAverageOfSubtree
{
public:
	// 3 ms, faster than 92.8% : 12.4 MB, less than 34.12%
	int solution(TreeNode* root) {
		int ans = 0;
		function<pair<int, int>(TreeNode*)> f = [&](TreeNode* node) -> pair<int, int> {
			if (!node) return { 0,0 };

			auto l = f(node->left), r = f(node->right);

			int cnt = 1 + l.first + r.first, sum = node->val + l.second + r.second;
			if (node->val == sum / cnt) ans++;

			return { cnt, sum };
		};
		f(root);

		return ans;
	}
	vector<int> output = {
		5,
		1
	};
	static constexpr int const& inputs = 1;
	vector<vector<int>> input1 = {
		{4,8,5,0,1,NULL,6},
		{1}
	};
};