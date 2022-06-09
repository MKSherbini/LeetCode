#pragma once
#include "stdc++.h"
using namespace std;

class Printer
{
public:
	template<typename T>
	static void printOne(const T& v, bool newLine = 0) {
		cout << v << (newLine ? "\n" : " ");
	}

	template<typename... Args>
	static void print(const Args&... args) {
		//((cout << " " << std::forward<Args>(args)), ...);
		//(cout << ... << forward<Args>(args)) << '\n';
		//((cout << std::forward<Args>(args) << " "), ...);
		((printOne(std::forward<const Args>(args))), ...);
		cout << '\n';
	}

	static void printOne(ListNode* head) {
		auto t = head;
		while (t)
		{
			cout << t->val << " ";
			t = t->next;
		}
		cout << endl;
	}

	static const int SPACING = 1;

	static void printOne(TreeNode* root, int space = 0) {
		if (root == NULL)
			return;
		space += SPACING;
		printOne(root->right, space);
		for (int i = SPACING; i < space; i++)
			cout << "\t";
		cout << root->val << "\n";
		printOne(root->left, space);
	}

	template<typename T>
	static void printOne(const vector<T>& v) {
		for (auto a : v) {
			printOne(a);
		}
		cout << '\n';
	}

	template<typename T>
	static void printOne(const set<T>& v) {
		for (auto a : v) {
			printOne(a);
		}
		cout << '\n';
	}

	template<typename T, typename R>
	static void printOne(const map<T, R>& v) {
		for (auto a : v) {
			printOne(a.first);
			cout << ": ";
			printOne(a.second);
		}
		cout << '\n';
	}

	static void printOne(const vector<string>& v) {
		for (auto a : v) {
			printOne(a);
			cout << '\n';
		}
		cout << '\n';
	}

	template<typename T>
	static void printBinary(T t, int sz = 32) {
		for (uint64_t i = (1ULL << (sz - 1)); i > 0; i >>= 1)
			cout << ((t & i) > 0);
		cout << endl;
	}
};

