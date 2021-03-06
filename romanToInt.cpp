#include "common.h"
//not checked yet

class Solution {
public:
    inline int c2n(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        const int len = s.length();
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            if(i >0 && c2n(s[i]) > c2n(s[i-1])) {
                sum += c2n(s[i]) - 2 * c2n(s[i - 1]);
            }
            else {
                sum += c2n(s[i]);
            }
        }
        return sum;
    }
};


int main() {

    return 1;
}