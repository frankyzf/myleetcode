//
// Created by feng on 8/17/15.
//

#include "common.h"
/*
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length()< 1)
            return res;
        auto match = [&s](int start){
            if(start + 19 >= s.length())
                return false;
            int start2 = start+10;
            for (int i = 0; i < 10; ++i) {
                if(s[start+i] != s[start2+i])
                    return false;
            }
            return true;
        };
        int i = 0;
        while(i < s.length()){
            if(match(i)){
                res.push_back(s.substr(i, 10));
                while(i+1 < s.length() && s[i+1] ==s[i])
                    ++i;
            }
            ++i;
        }

        return res;
    }
};


int main(){
    string s = "AAAAACCCCCAAAAACCCCCAAAAAGGGTTT";
    auto r = Solution().findRepeatedDnaSequences(s);
    for(auto str: r){
        cout << str << endl;
    }
    return 1;
}