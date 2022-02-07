#include "utils.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>

vector<string> tokenizeCSVLine(string line) {
    vector<string> tokens;
    stringstream lineStream(line);
    string temp;

    while(getline(lineStream, temp, '"')) {
        stringstream lineStream2(temp);
        while (getline(lineStream2, temp, ',')) {
            tokens.push_back(temp);
        }

        if (getline(lineStream, temp, '"')) {
            tokens.push_back(temp);
        }
    }

    return tokens;
}

vector<int> parseZip(string line) {
    vector<int> tokens;
    stringstream lineStream(line);
    string temp;

    while (getline(lineStream, temp, '-')) {
        tokens.push_back(stoi(temp));
    }

    return tokens;
}

long parsePrice(string line) {
    if (line.empty()) {
        return 0;
    }

    line.erase(remove_if(line.begin(), line.end(),
                [](char c) {
                    return c == ',' || c == '$';
                }));

    return stol(line);
}
