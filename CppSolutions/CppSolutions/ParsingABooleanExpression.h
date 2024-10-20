#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/parsing-a-boolean-expression/description/

class ParsingABooleanExpression {
public:
    // 7 ms, faster than 64.18% : 13.83 MB, less than 11.64%
    uint8_t solution(string expression)
    {
        int n = size(expression);
        stack<int> s;
        unordered_map<int, int> m;

        for (size_t i = 0; i < n; i++) {
            if (expression[i] == '(')
                s.push(i);
            else if (expression[i] == ')') {
                m[s.top() - 1] = i;
                s.pop();
            }
        }
        Printer::print(m);

        function<bool(int)> f = [&](int i) -> bool {
            if (!m.count(i))
                return expression[i] == 't';

            int j = i + 2;
            bool ret = f(j);
            Printer::print(i, j, ret);
            if (m.count(j))
                j = m[j];

            if (expression[i] == '!')
                return !ret;
            else if (expression[i] == '|') {
                for (j++; j < m[i]; j++) {
                    if (expression[j] == ',') {
                        ret |= f(j + 1);
                        Printer::print(i, j + 1, ret);
                        if (ret)
                            return ret;
                        if (m.count(j + 1))
                            j = m[j + 1];
                    }
                }
            } else {
                for (j++; j < m[i]; j++) {
                    if (expression[j] == ',') {
                        ret &= f(j + 1);
                        Printer::print(i, j + 1, ret);
                        if (!ret)
                            return ret;
                        if (m.count(j + 1))
                            j = m[j + 1];
                    }
                }
            }

            return ret;
        };

        return f(0);
    }
    vector<uint8_t> output = {
        false,
        true,
        true,
        true,
        false
    };
    static constexpr int const& inputs = 1;
    vector<string> input1 = {
        "&(|(f))",
        "|(f,f,f,t)",
        "!(&(f,t))",
        "|(&(f,t),t,&(f,t))",
        "|(&(t,f,t),!(t))"
    };
};