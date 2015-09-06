//
// Created by feng on 8/7/15.
//

#include "common.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m(256, -1);
        const int len = s.length();
        const int gap = 'A' -'a';
        for(int i=0; i < len; ++i)
        {
            int c = tolower((unsigned int)s[i]);
            int b = tolower((unsigned char) t[i]);

            vector<int>::iterator it;
            if( (it = find(m.begin(), m.end(), b)) != m.end())
            {
                const int d = distance(m.begin(), it);
                if(c != d) {
                    cout << i << endl;
                    cout << "1, c:" << (unsigned char) c << " b:" << (unsigned char)  b << endl;
                    return false;
                }
            }
            else if(m[c] == -1)
                m[c] = b;
            else if (m[c] != b) {
                cout << i << endl;
                cout << "c:" << (unsigned char) c << " mc:" << (unsigned char) m[c] << " b:" << (unsigned char)  b << endl;
                return false;
            }

        }
        return true;
    }
};

