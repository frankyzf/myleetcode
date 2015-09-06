//
// Created by feng on 8/17/15.
//

#include "common.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> charmap  {{'A',0}, {'C',1}, {'G', 2}, {'T', 3}};
        auto hashf = [&charmap](const string& ms){
            unsigned  long l = 0;
            for (int i = 0; i < 10; ++i) {
               l += charmap[ms[i]];
                l  = l << 4;
            }
            return l;
        };

        unordered_map<string, int, decltype(hashf)> mm(1, hashf);
        vector<string> res;
        if(s.length() < 10) {
            return res;
        }
        for(int i = 9; i < s.length()-9; ++i){
            if(++mm[s.substr(i-9, 10)] == 2)
                res.push_back(s.substr(i-9, 10));
        }
        return res;
    }
};


int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto r = Solution().findRepeatedDnaSequences(s);
    for(auto v: r){
        cout << v << endl;
    }
    return 1;
}