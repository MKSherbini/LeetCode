#pragma once
#include "stdc++.h"
using namespace std;

// https://leetcode.com/problems/sentence-similarity-iii/description/

class SentenceSimilarityIII {
public:
    // 0 ms, faster than 100% : 7.56 MB, less than 99.54%
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        auto& small = size(sentence1) > size(sentence2) ? sentence2 : sentence1;
        auto& big = size(sentence1) > size(sentence2) ? sentence1 : sentence2;

        int i = -1;
        int spaceFromStart = -1;
        for (size_t k = 0; k < size(big); k++) {
            // Printer::print(small[i + 1], big[k]);
            if (i + 1 < size(small) && small[i + 1] == big[k]) {
                if (i + 1 < size(small) && small[i + 1] == ' ')
                    spaceFromStart = i + 1;
                i++;
            } else
                break;
        }

        int j = size(small);
        int spaceFromEnd = -1;
        for (int k = size(big) - 1; k >= 0; k--) {
            // Printer::print(small[j - 1], big[k]);
            if (j - 1 >= 0 && small[j - 1] == ' ' && big[k] == ' ')
                spaceFromEnd = j - 1;
            if (j > spaceFromStart + 1 && small[j - 1] == big[k]) {
                j--;
            } else
                break;
        }

        Printer::print(i, j);
        Printer::print(spaceFromStart, spaceFromEnd);

        if ((spaceFromStart == spaceFromEnd && spaceFromEnd != -1)
            || (j == 0 && (size(big) == size(small) || big[size(big) - size(small) - 1] == ' '))
            || (i == (int)size(small) - 1 && (size(big) == size(small) || big[i + 1] == ' ')))
            return 1;

        return 0;
    }
};