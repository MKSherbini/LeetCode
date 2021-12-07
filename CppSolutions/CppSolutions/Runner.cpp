#include "ReverseString.h"
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
	run(ReverseString(), vector<char>{ 'h', 'e', 'l', 'l', 'o'});
}