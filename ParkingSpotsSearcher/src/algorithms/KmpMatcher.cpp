//
// Created by mateus on 10-05-2018.
//

#include "KmpMatcher.h"

std::vector<int> KmpMatcher::computePrefixFunction(std::string p){
    std::vector<int> pi;
    pi.push_back(0);
    int k = 0;

    for(int q = 2; q <= p.size(); q++){
        while(k > 0 && p[k+1] != p[q]){
            k = pi[k];
        }

        if (p[k+1] == p[q])
            k = k+1;

        pi[q] = k;
    }

    return pi;
}

bool KmpMatcher::matches(std::string t, std::string p){
    KmpMatcher matcher;

    int q = 0; // number of characters matched

    if (t == "Rua da Igreja da Areosa"){
        q = 0;
    }

    for(int i = 1; i <= t.size(); i++){ // scan the text from left to right

        while (q > 0 && p[q+1] != t[i]){
            q = matcher.computePrefixFunction(p)[q]; // next character does not match
        }

        if (p[q+1] == t[i])
            q = q+1; // next character matches

        if (q == p.size()){
            // is all of p matched?
            return true; // character matches

            q = matcher.computePrefixFunction(p)[q]; // look for the next match
        }
    }
}
