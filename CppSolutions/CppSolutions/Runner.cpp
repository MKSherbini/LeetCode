#include "stdc++.h"
#include "MyCalendarIII.h"

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(true).run<MinimumTimeToMakeRopeColorful>();
	MyCalendarIII c;
	Printer::print(c.book(5, 10));
	Printer::print(c.book(8, 10));
	Printer::print(c.book(8, 9));
	Printer::print(c.book(10, 11));
}

