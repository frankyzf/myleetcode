#include "common.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int loc[256];
        memset(loc, -1, sizeof(loc));
        int start = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(loc[s[i]] != -1)
            {
                for(int j = start; j < loc[s[i]]; ++j)
                    loc[s[j]] = -1;
                start = loc[s[i]] + 1;
            }
            if(i - start +1 > max)
                max =  i - start +1;
            loc[s[i]] = i;
        }
        return max;
    }
};


int main() {

    return 1;
}