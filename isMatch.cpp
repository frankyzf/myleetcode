#include "common.h"
//not checked yet
class Solution {
public:
    bool isMatch(string s, string p) {
#ifdef DEBUG
        cout << "string:" << s << " pattern:" << p << endl;
#endif

        auto remainp = [&s, &p](int pi) {
            while (pi + 1 < p.length() && p[pi + 1] == '*') {
                pi = pi + 2;
            }
            return pi == p.length();
        };


        function<bool(int, int)> ff = [&remainp, &s, &p, &ff, &remainp ](int i, int j) {
#ifdef DEBUG
            cout << " --> i:" << i << " j:" << j << endl;
#endif

            if (i == s.length())
                return remainp(j);
            else if (j == p.length())
                return false;
            else {
                bool bstar = false;
                if (j < p.length() - 1 && p[j + 1] == '*')
                    bstar = true;

                if (!bstar) {
                    if (p[j] == '.' || s[i] == p[j]) {
                       return ff(i + 1, j + 1);
                    }
                    else {
                        return false;
                    }
                }
                else {
                    if (p[j] == '.' || s[i] == p[j]) {
                        int ii = i;
                        do {
                            if(ff(ii, j+2))
                                return true;
                            ++ii;
                        }while(ii < s.length() && (p[j] == '.' || s[ii] == p[j]));
                        if(ii == s.length())
                            return remainp(j+2);
                        else
                            return ff(ii, j+2);
                    }
                    else {
                        return  ff(i, j + 2);
                    }
                }
            }
            return false;
        };

        return ff(0,0);
    }
};


int main() {
    cout << boolalpha <<  Solution().isMatch("aa", ".*");
    return 1;
}