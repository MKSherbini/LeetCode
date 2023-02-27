#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/construct-quad-tree/

class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {
		val = false;
		isLeaf = false;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};
class ConstructQuadTree
{
public:
	// 4 ms, faster than 100% : 17.9 MB, less than 40.65%
	Node* solution(vector<vector<int>> grid) {
		int n = size(grid);
		if (n == 1) return new Node(grid[0][0], 1);
		Node* ret = f(grid, 0, 0, n, n);
		return ret != NULL ? ret : new Node(grid[0][0], 1);
	}

	Node* f(vector<vector<int>>& grid, int x, int y, int xLen, int yLen) {
		if (xLen == 2) {
			int s = 0;
			for (size_t i = x; i < x + xLen; i++)
				for (size_t j = y; j < y + yLen; j++)
					s += grid[i][j];
			if (s == 4 || s == 0) {
				return NULL;
			}
			else {
				return new Node(0, 0,
					new Node(grid[x][y], 1), new Node(grid[x][y + 1], 1),
					new Node(grid[x + 1][y], 1), new Node(grid[x + 1][y + 1], 1)
				);
			}
		}

		int xHalf = xLen / 2, yHalf = yLen / 2;
		Node* g00 = f(grid, x, y, xHalf, yHalf);
		Node* g01 = f(grid, x, y + yHalf, xHalf, yHalf);
		Node* g10 = f(grid, x + xHalf, y, xHalf, yHalf);
		Node* g11 = f(grid, x + xHalf, y + yHalf, xHalf, yHalf);

		if (!g00 && !g01 && !g10 && !g11) {
			int s = grid[x][y] + grid[x][y + yHalf]
				+ grid[x + xHalf][y] + grid[x + xHalf][y + yHalf];
			if (s == 4 || s == 0) {
				return NULL;
			}
		}
		return new Node(0, 0,
			g00 != NULL ? g00 : new Node(grid[x][y], 1), g01 != NULL ? g01 : new Node(grid[x][y + yHalf], 1),
			g10 != NULL ? g10 : new Node(grid[x + xHalf][y], 1), g11 != NULL ? g11 : new Node(grid[x + xHalf][y + yHalf], 1)
		);
	}

	static constexpr int const& inputs = 1;
	vector<vector<vector<int>>> input1 = {
		{{0,1},{1,0}},
		{{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0}}
	};
};

// 0 1 2 3 4 5 6 7
