#pragma once
#include <vector>
#include <string>
using namespace std;

class Tokenizer{
public:
    static vector<string> parse(string line, string sep){
        vector<string> tokens;
        
        int startIdx = 0;
        size_t foundIdx = line.find(sep, startIdx);
        while(foundIdx != string::npos){
            int cnt = foundIdx - startIdx;
            string token = line.substr(startIdx, cnt);
            tokens.push_back(token);

            startIdx = foundIdx + sep.length();
            foundIdx = line.find(sep, startIdx);
        }
        int cnt = line.length() - startIdx;
        string token = line.substr(startIdx, cnt);
        tokens.push_back(token);
        return tokens;
    }
};