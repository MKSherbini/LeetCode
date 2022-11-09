#include "stdc++.h"
#include "OnlineStockSpan.h"

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(true).run<OnlineStockSpan>();

	OnlineStockSpan obj;
	Printer::print(obj.next(100));
	Printer::print(obj.next(80));
	Printer::print(obj.next(60));
	Printer::print(obj.next(70));
	Printer::print(obj.next(60));
	Printer::print(obj.next(75));
	Printer::print(obj.next(85));
	Printer::print(obj.next(100));
	Printer::print(obj.next(85));
}

