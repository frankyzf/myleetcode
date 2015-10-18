#include "common.h"
//not checked yet

class Solution {
public:
    int numDecodings(string s) {
        const int size = s.length();
        if(size == 0)
            return 0;
        vector<int> res(size+1, 0);
        res[0] = 1;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(ch == '0'){
                if(i-1 >= 0  && (s[i-1] == '1' || s[i-1] == '2') ){
                    res[i+1] = res[i-1];
                }
                else{
                    return 0;
                }
            }
            else{
                if(i-1>=0 && ( s[i-1] == '1' || s[i-1] == '2' && ch >= '1' && ch <= '6')){
                    res[i+1] = res[i] + res[i-1];
                }
                else{
                    res[i+1] = res[i];
                }
            }
        }
        return res.back();
    }
};



int main() {
    cout << Solution().numDecodings("100");
    return 1;
}