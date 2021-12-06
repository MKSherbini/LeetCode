#include "TwoSum2.h"
#include "Printer.h"

// todo improve printing + examples running

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
	run(TwoSum2(), vector<int>{ 2, 3, 7, 11, 15}, 14);
	run(TwoSum2(), vector<int>{ 2, 3, 4}, 6);
	run(TwoSum2(), vector<int>{ -1, 0}, -1);
	run(TwoSum2(), vector<int>{ 5, 25, 75}, 100);
}