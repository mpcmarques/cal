//
// Created by mateus on 05/04/18.
//

#include <string>
#include <sstream>
#include "StringSplitter.h"

using namespace std;

vector<string> StringSplitter::split(const string s, char token) {

    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, token)) {
        result.push_back(item);
    }

    return result;
}
