//
// Created by mateus on 10-05-2018.
//

#include <algorithm>
#include "KmpMatcher.h"

std::vector<int> KmpMatcher::computePrefixFunction(std::string p) {

    std::vector<int> pi(p.size());
    int k = 0;

    for (int q = 1; q < p.size(); q++) {
        char target = p[q];

        while (k > 0 && p[k] != target) {
            k = pi[k - 1];
        }

        if (p[k + 1] == target) {
            k++;
        }

        pi[q] = k;
    }

    return pi;
}

bool KmpMatcher::matches(std::string t, std::string p) {
    KmpMatcher matcher;

    // convert strings to uppercase
    std::transform(p.begin(), p.end(), p.begin(), ::toupper);
    std::transform(t.begin(), t.end(), t.begin(), ::toupper);

    int q = 0; // number of characters matched

    for (int i = 1; i <= t.size(); i++) { // scan the text from left to right

        while (q > 0 && q+1 < p.size() && p[q+1] != t[i]) {
            q = matcher.computePrefixFunction(p)[q]; // next character does not match
        }

        if (p[q + 1] == t[i])
            q = q + 1; // next character matches

        if (q == p.size()) {
            // is all of p matched?
            return true; // character matches

            q = matcher.computePrefixFunction(p)[q]; // look for the next match
        }
    }
}
