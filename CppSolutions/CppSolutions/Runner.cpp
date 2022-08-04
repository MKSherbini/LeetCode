#include "stdc++.h"
#include "MyCalendarI.h"

//#include <bits/stdc++.h>
//using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	//Runner(false).run<KthSmallestElementInASortedMatrix>();

	MyCalendarI c;
	Printer::print(c.book(10, 20));
	Printer::print(c.book(15, 30));
	Printer::print(c.book(30, 40));
}

