#include "common.h"
//not checked yet


class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
         if(s1.length() + s2.length() != s3.length())
             return false;
         const int len1 = s1.length(), len2 = s2.length();


        vector<vector<bool>> flags(len1+1, vector<bool>(len2+1, false));
        flags[0][0] = true;
        for (int i = 1; i <= len1; ++i) {
            flags[i][0] = flags[i-1][0] && s1[i-1] == s3[i-1];
        }
        for (int j = 1; j <= len2; ++j) {
            flags[0][j] = flags[0][j-1] && s2[j-1] == s3[j-1];
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if(flags[i-1][j] && s1[i-1] == s3[i+j-1] ||flags[i][j-1] && s2[j-1] == s3[i+j-1])
                    flags[i][j] = true;
            }
        }
        return flags[len1][len2];
    }

};


int main() {
    cout << boolalpha << Solution().isInterleave("db", "b", "cbb") << endl;

    cout << Solution().isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
                                    "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
                                    "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababb"
                                    "bababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");

        return 1;
}