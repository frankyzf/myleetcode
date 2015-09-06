//
// Created by feng on 8/7/15.
//

#include "common.h"

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length()-1;
        unsigned int val = 0;
        for(auto c:s){
            int i = c-'A'+1;
            val += i* pow(26, len);
            --len;
        }
        return val;

    }
};



int main(){
    cout << Solution().titleToNumber("A");
    return 1;
}