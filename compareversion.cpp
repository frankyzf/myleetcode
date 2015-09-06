//
// Created by feng on 8/9/15.
//
#include "common.h"
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int a1, a2;
        size_t s1, s2;
        if(version1.length() == 0)
            a1 = 0;
        else{
            s1 = version1.find('.');
            a1 = (s1 == string::npos)? atoi(version1.c_str()):atoi(version1.substr(0, s1).c_str());
        }
        if (version2.length() == 0 )
            a2 = 0;
        else{
            s2 = version2.find('.');
            a2 = (s2 == string::npos)? atoi(version2.c_str()): atoi(version2.substr(0, s2).c_str());
        }

        if(a1 > a2)
            return 1;
        else if (a2 > a1)
            return -1;
        else{
            if(version1.length() == 0 || version2.length() ==0)
                    return 0;
            else{
                string substr1 = (s1 == string::npos)?"":version1.substr(s1+1, version1.length()-s1-1);
                string substr2 = (s2 == string::npos)?"":version2.substr(s2+1, version2.length()-s2-1);
                return compareVersion(substr1, substr2);
            }


        }
    }
};

int main()
{
    cout << Solution().compareVersion("1.0", "1");
    return 1;
}