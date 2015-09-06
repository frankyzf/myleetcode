#include "common.h"
class Solution {
public:
    string longestPalindrome(string s) {
        const int size = s.length();
        if(size <=1) {
            return s;
        }
        vector<bool> flags(size, true);
        int maxlen = 1;
        int startindex = 0;
        vector<bool> flags2(size, false);
        for(int i = 0; i< size - 1 ; i++){
            if(s[i] == s[i+1]){
                flags2[i] = true;
                maxlen = 2;
                startindex = i;
            }
        }

        for(int len = 3; len <= size; ++len){
            vector<bool> nflags(size, false);
            for(int i = 0; i< size - len+1; i++){
                if(s[i] == s[i+len-1]  &&(len == 2 || flags[i+1])){
                    nflags[i] = true;
                    if(maxlen < len) {
                        startindex = i;
                        maxlen = len;
                    }
                }
            }
            flags.swap(flags2);
            flags2.swap(nflags);
        }
        return s.substr(startindex, maxlen);
    }
};



int main() {

    return 1;
}