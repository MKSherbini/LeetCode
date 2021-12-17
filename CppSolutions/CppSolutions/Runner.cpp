#include "RichestCustomerWealth.h"
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
	run(RichestCustomerWealth(), vector<vector<int>> { {1, 2, 3}, { 3,2,1 }});
}