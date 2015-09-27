#include "common.h"
//not checked yet
class Solution {
public:
    bool isMatch(string s, string p) {
#ifdef DEBUG
        cout << "string:" << s << " pattern:" << p << endl;
#endif
        const int slen = s.length();
        const int plen = p.length();
        vector<vector<int>> flags(slen+1, vector<int>(plen+1, -1));
        auto remainp = [&s, &p](int pi) {
            while (pi + 1 < p.length() && p[pi + 1] == '*') {
                pi = pi + 2;
            }
            return (pi == p.length() || (pi == p.length() - 2 && p[pi + 1] == '*'));
        };
        bool result = false;

        function<bool(int, int)> ff = [&remainp, &s, &p, &ff, &flags, slen, plen, &result](int i, int j) {
#ifdef DEBUG
            cout << " --> i:" << i << " j:" << j << endl;
#endif
            if (flags[i][j] != -1)
                return (bool) flags[i][j];

            if (i == s.length())
                return remainp(j);
            else if (j == p.length())
                return false;
            else {
                bool bstar = false;
                if (j < plen - 1 && p[j + 1] == '*')
                    bstar = true;

                if (!bstar) {
                    if (p[j] == '.' || s[i] == p[j]) {
                        if (i == slen - 1) {
                            flags[i][j] = remainp(j + 1);
                            return flags[i][j] == 0 ? false : true;
                        }
                        else if (j == plen - 1) {
                            flags[i][j] = false;
                            return false;
                        }
                        else {
                            flags[i][j] = ff(i + 1, j + 1);
                            return flags[i][j] == 0 ? false : true;
                        }
                    }
                    else {
                        flags[i][j] = false;
                        return false;
                    }
                }
                else {
                    if (p[j] == '.' || s[i] == p[j]) {
                        if (ff(i, j + 2)) {
                            flags[i][j] = true;
                            return true;
                        }
                        int k = 1;
#ifdef DEBUG
                        cout << "i:" << i << " j:" << j << endl;
#endif
                        for (; k <= slen - i; ++k) {
                            if (p[j] == '.' || s[i + k - 1] == p[j]) {
                                if (ff(i + k, j + 2)) {
                                    flags[i][j] = true;
                                    return true;
                                }
                            }
                            else {
                                flags[i][j] = false;
                                return false;
                            }
                        }

                    }
                    else {
                        if (j == plen - 2) {
                            flags[i][j] = false;
                            return false;
                        }

                        flags[i][j] = ff(i, j + 2);
                        return flags[i][j] == 0 ? false : true;
                    }
                }
            }
            return false;
        };

        return ff(0,0);
    }
};


int main() {
    cout << boolalpha <<  Solution().isMatch("aa", "a*");
    return 1;
}