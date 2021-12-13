#include "FloodFill.h"
#include "Printer.h"

// todo improve printing + examples running

template<typename T>
static void print(const vector< vector<T> >& v) {
	for (auto a : v) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}
}

template<typename T>
static void print(const vector<T>& v) {
	for (auto a : v) {
		cout << a << " ";
	}
	cout << endl;
}

template<typename T>
static void print(const T& v) {
	cout << v << endl;
}

template<typename T, typename ...Args>
void run(T t, Args ... r) {
	print(t.solution(r...));
}

int main()
{
	run(FloodFill(), vector<vector<int>> { {1, 1, 1}, { 1, 1, 0 }, { 1, 0, 1 } }, 0, 0, 2);
	run(FloodFill(), vector<vector<int>> { {0, 0, 0}, { 0, 0, 0 }}, 0, 0, 2);
	run(FloodFill(), vector<vector<int>> { {0, 0, 0}, { 0, 1, 1 }}, 1, 1, 1);
}