//
// Created by feng on 8/14/15.
//

#include "common.h"

class Solution {
public:
    string shortestPalindrome(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());

        auto f = [&s1, &s](int ei, int si1){
            return s.substr(0, ei+1) == s1.substr(si1, s.length()-si1);
        };

        string res;


        for (int j = 0; j < s1.length(); ++j) {
            int l = s.length() - j ;
            string cs1 = s.substr(0, l);
            string cs2 = s1.substr(j, string::npos);
            if(cs1 == cs2){
                auto it = s1.begin();
                res.assign(it,it + j );
                reverse(res.begin(), res.end());
                copy(s.begin(), s.begin() + l+1, back_inserter(res));
                return res;
            }
        }
        return res;

    }
};


int main(){
    cout << Solution().shortestPalindrome("ab");

    return 1;
}