#pragma once
#include "stdc++.h"
using namespace std;

//https://leetcode.com/problems/goal-parser-interpretation/

class GoalParserInterpretation
{
public:
	// 0 ms, faster than 100.00% : 6 MB, less than 81.74%
	string solution(string command) {
		for (int i = command.size() - 1; i > 0; i--)
			if (command.compare(i - 1, 2, "()") == 0)
				command.replace(i - 1, 2, "o");
			else if (i - 3 >= 0 && command.compare(i - 3, 4, "(al)") == 0)
				command.replace(i - 3, 4, "al");

		return command;
	}
	vector<string> output = {
		"alGalooG",
		"Gooooal",
		"Goal"
	};
	vector<string> input1 = {
		"(al)G(al)()()G",
		"G()()()()(al)",
		"G()(al)"
	};
};

