#include "ShuffleTheArray.h"
#include "Printer.h"
#include "Helpers.h"

// todo improve printing + examples running

int main()
{
	run(ShuffleTheArray(),
		vector<int> { 2, 3, 5, 4, 1, 7 },
		vector<int> { 2, 5, 1, 3, 4, 7 }, 3);
	run(ShuffleTheArray(),
		vector<int> { 1, 4, 2, 3, 3, 2, 4, 1 },
		vector<int> { 1, 2, 3, 4, 4, 3, 2, 1 }, 4);
}