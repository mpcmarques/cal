//
// Created by mateus on 12-05-2018.
//

#include "EditDistance.h"
#include <vector>
#include <cstring>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

int min3(int a, int b, int c) {
    int mina = min(a, b);
    return min(mina, c);
}

// with optimizations


int EditDistance::calculate(std::string p, std::string t) {
    int minDistance = 10000;

    std::istringstream iss(t);

    std::vector<std::string> results(std::istream_iterator<std::string> {iss}, std::istream_iterator<std::string>());

    for (auto string: results) {
        // convert strings to uppercase
        std::transform(p.begin(), p.end(), p.begin(), ::toupper);
        std::transform(string.begin(), string.end(), string.begin(), ::toupper);

        int value = editDistanceOptimized(p, string);
        if (value < minDistance)
            minDistance = value;
    }

    return minDistance;
}

int EditDistance::editDistanceOptimized(std::string p, std::string t) {
    int i, j;

    vector<int> d(t.length());

    for (j = 0; j < t.size(); j++) {
        d[j] = j;
    }

    for (i = 0; i < p.size(); i++) {
        int old = d[0]; // guard d[i-1, 0]
        d[0] = i; // init d[i,0]

        for (j = 1; j < t.size(); j++) {

            int newValue;

            if (p[i] == t[j]) {
                newValue = old;
            } else {
                newValue = 1 + min3(old, d[j], d[j - 1]);
            }

            old = d[j];
            d[j] = newValue;
        }
    }

    // finalizacao
    return d[t.size() - 1];
}

int EditDistance::editDistance(string p, string t) {
    int i, j;
    vector<vector<int>> d(p.size(), vector<int>(t.size()));

    // init
    for (i = 0; i < p.size(); i++) {
        d[i][0] = i;
    }
    for (j = 0; j < t.size(); j++)
        d[0][j] = j;

    for (i = 1; i < p.size(); i++) {
        for (j = 1; j < t.size(); j++) {

            if (p[i] == t[i]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min3(d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    return d[p.size() - 1][t.size() - 1];

}