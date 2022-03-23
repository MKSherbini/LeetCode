#pragma once
#include "stdc++.h"
using namespace std;

class Runner
{
public:
	Runner(bool anyOrder = false) {
		this->anyOrder = anyOrder;
	}

	template<typename T, int n>
	void run() {
		run<T, n>(T());
	}

	template<typename T>
	void run() {
		run<T, T::inputs>();
	}

private:
	bool anyOrder = false;

	template<typename T, typename R, typename ...Args>
	void run(T t, R res, Args ... r) {
		R ret = t.solution(r...);
		Printer::printOne(ret);
		if (anyOrder)
			Sorter::sort(ret), Sorter::sort(res);
		bool acc = Validator::valid(ret, res);
		cout << "judge: " << (acc ? "Accepted" : "Wrong answer") << "\n\n";
	}

	template<typename T, int params, typename std::enable_if<params == 1, int*>::type = nullptr>
	void run(T t) {
		for (int i = 0; i < t.output.size(); i++)
			run(t, t.output[i], t.input1[i]);
	}

	template<typename T, int params, typename std::enable_if<params == 2, int*>::type = nullptr>
	void run(T t) {
		for (int i = 0; i < t.output.size(); i++)
			run(t, t.output[i], t.input1[i], t.input2[i]);
	}

	template<typename T, int params, typename std::enable_if<params == 3, int*>::type = nullptr>
	void run(T t) {
		for (int i = 0; i < t.output.size(); i++)
			run(t, t.output[i], t.input1[i], t.input2[i], t.input3[i]);
	}
};
