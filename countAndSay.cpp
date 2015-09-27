#include "common.h"
//not checked yet

class Solution {
public:
    string countAndSay(int n) {
        stringstream ss ;
         ss << 1;
        string str = ss.str();
        for(int i = 0; i < n-1; ++i){
            int j = 0;
            int start = 0;
            stringstream mss;
            while(j < str.length()){
                while(j < str.length() && str[j] == str[start]){
                    ++j;
                }
                mss << (j-start) << str[start];
                start = j;
            }
            str = mss.str();
        }
        return str;
    }
};

int main() {
    cout << Solution().countAndSay(2) ;
    return 1;
}