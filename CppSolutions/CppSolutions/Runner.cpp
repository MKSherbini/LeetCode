#include "LetterCasePermutation.h"
#include "Printer.h"
#include "Runner.h"

// todo improve printing + examples running
// todo handle unmatched order

int main()
{
	freopen("output.txt", "w", stdout);
	Runner(true).run<LetterCasePermutation, 1>();
}
