//
// Created by feng on 9/3/15.
//
#include "common.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        function<bool(int, int)> f = [&s, &p, &f](int si, int pi){
            if(si == s.length()){
                while(pi < p.length() && p[pi] == '*')
                    ++pi;
                return pi == p.length();
            }
            else if (pi == p.length())
                return false;

            if(p[pi] != '?' && p[pi] != '*'){
                if(s[si] != p[pi])
                    return false;
                return f(si+1, pi+1);
            }
            else if (p[pi] == '?'){
                return f(si+1, pi+1);
            }
            else { // p[pi] == '*'
                while(pi < p.length() && p[pi] == '*')
                    ++pi;
                int cnt = 0;
                for(int pii = pi; pii < p.length(); ++pii){
                    if(p[pii] != '*')
                        ++cnt;
                }

                --pi;
                int sii = si;
                while(sii +cnt < s.length()){
                    if(f(sii, pi+1))
                        return true;
                    ++sii;
                }

                if(sii == s.length()){
                    return (pi +1) ==  p.length();
                }
                else
                    return false;
            }

        };
        return f(0, 0);
    }
};

int main(){
    cout << boolalpha <<
            Solution().isMatch(
                    "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
                    "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");

    return 1;
}