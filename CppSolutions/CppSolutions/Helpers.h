#pragma once
#include "stdc++.h"
using namespace std;

template<typename T>
static void print(const T& v) {
	cout << v << endl;
}

template<typename T>
static void print(const vector<T>& v) {
	for (auto a : v) {
		cout << a << " ";
	}
	cout << endl;
}

template<typename T>
static void print(const vector< vector<T> >& v) {
	for (auto a : v) {
		print(a);
	}
}

template<typename T>
static int8_t valid(const T& v, const T& v2) {
	return v == v2;
}

template<typename T>
static int8_t valid(const vector<T>& v, const vector<T>& v2) {
	if (v.size() != v2.size()) return 0;

	for (int i = 0; i < v.size(); i++)
		if (!valid(v[i], v2[i])) return 0;

	return 1;
}

template<typename T>
static int8_t valid(const vector< vector<T> >& v, const vector< vector<T> >& v2) {
	if (v.size() != v2.size()) return 0;

	for (int i = 0; i < v.size(); i++)
		if (!valid(v[i], v2[i])) return 0;

	return 1;
}

template<typename T, typename R, typename ...Args>
void run(T t, R res, Args ... r) {
	R ret = t.solution(r...);
	print(ret);
	cout << "judge: " << (valid(ret, res) ? "Accepted" : "Wrong answer") << endl;
}

template<typename T, int params, typename std::enable_if<params == 1, int*>::type = nullptr>
void run(T t) {
	for (int i = 0; i < t.outputs.size(); i++)
		run(t, t.outputs[i], t.input1[i]);
}

template<typename T, int params, typename std::enable_if<params == 2, int*>::type = nullptr>
void run(T t) {
	for (int i = 0; i < t.outputs.size(); i++)
		run(t, t.outputs[i], t.input1[i], t.input2[i]);
}

template<typename T, int params, typename std::enable_if<params == 3, int*>::type = nullptr>
void run(T t) {
	for (int i = 0; i < t.outputs.size(); i++)
		run(t, t.outputs[i], t.input1[i], t.input2[i], t.input3[i]);
}

template<typename T, int n>
void run() {
	run<T, n>(T());
}