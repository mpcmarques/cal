//
// Created by mateus on 12-05-2018.
//

#include "EditDistance.h"
#include <vector>

using namespace std;

int min3(int a, int b, int c) {
    int mina = min(a, b);
    return min(mina, c);
}

int EditDistance::editDistance(string p, string t) {
    int i, j;
    vector<vector<int>> d(p.size());

    // init
    for (i = 0; i < p.size(); i++) {
        d[i].resize(t.size());
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

    return d[p.size()-1][t.size()-1];

}