#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/flatten-nested-list-iterator/

 // You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger>& getList() const;
};


class FlattenNestedListIterator
{
public:
	// 13 ms, faster than 85.96% : 14.8 MB, less than 20.98%
	FlattenNestedListIterator(vector<NestedInteger> nestedList) {
		idx = 0;
		fillList(nestedList);
	}

	void fillList(vector<NestedInteger> nestedList) {

		for (size_t i = 0; i < nestedList.size(); i++)
		{
			if (nestedList[i].isInteger()) list.push_back(nestedList[i].getInteger());
			else fillList(nestedList[i].getList());
		}
	}

	int next() {
		return list[idx++];
	}

	bool hasNext() {
		return idx < list.size();
	}
private:
	vector<int> list;
	int idx;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */