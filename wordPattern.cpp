#include "common.h"
//not checked yet



class Solution {
public:
    bool wordPattern(string pattern, string str) {
        const int plen = pattern.length();
        const int strlen = str.length();
        size_t pos = 0;
        while(pos <strlen && str[pos] == ' ')
            ++pos;

        if(plen == 0)
            return pos == strlen;

        unordered_map<char, string> dict;
        unordered_map<string, char> rdict;
        int i = 0;
        for (; pos != string::npos && pos < strlen && i < plen; ++i) {
            char ch = pattern[i];
            auto pos2 = str.find(' ', pos);
            string word = (pos2 == string::npos)? str.substr(pos): str.substr(pos, pos2-pos);
            if(dict.find(ch) == dict.end() ) {
                if (rdict.find(word) == rdict.end()) {
                    dict[ch] = word;
                    rdict[word] = ch;
                }
                else{
                    return false;
                }
            }
            else{
                if(rdict.find(word) == rdict.end())
                    return false;
                else if(word != dict[ch] || rdict[word] != ch) {
                    return false;
                }
            }
            if(pos2 == string::npos)
                pos = pos2;
            else{
                pos = pos2;
                while(pos < strlen && str[pos] == ' ')
                    ++pos;
            }
        }
        return (pos == string::npos || pos == strlen) && (i == plen);
    }
};



int main() {
    cout << Solution().wordPattern("abba", "dog dog dog dog");
    return 1;
}