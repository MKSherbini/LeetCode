#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sort-the-people/description/

class SortThePeople {
public:
    // 21 ms, faster than 90.38% : 22.38 MB, less than 91.2%
    vector<string> solution(vector<string> names, vector<int> heights)
    {
        function<void(int, int)> quickSort = [&](int low, int high) -> void {
            // terminate if range is empty
            if (low >= high)
                return;

            // choose the pivot
            int pivot = heights[high];

            // assume position for the pivot (we move it until it reaches the correct sorted position in the array)
            int pi = low;

            for (int j = low; j < high; j++) {
                if (heights[j] > pivot) {
                    // add the element to the left side and move the pivot forward
                    swap(heights[pi], heights[j]);
                    swap(names[pi], names[j]);
                    pi++;
                }
            }
            swap(heights[pi], heights[high]);
            swap(names[pi], names[high]);

            // repeat for the rest of the array
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        };

        quickSort(0, size(names) - 1);
        return names;
    }
    vector<vector<string>> output = {
        { "Mary", "Emma", "John" },
        { "Bob", "Alice", "Bob" }
    };
    static constexpr int const& inputs = 2;
    vector<vector<string>> input1 = {
        { "Mary", "John", "Emma" },
        { "Alice", "Bob", "Bob" }
    };
    vector<vector<int>> input2 = {
        { 180, 165, 170 },
        { 155, 185, 150 }
    };
};