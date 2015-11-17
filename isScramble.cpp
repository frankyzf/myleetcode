#include "common.h"
//not checked yet


class Solution {
public:
    bool isScramble(string s1, string s2) {
        auto hashf = [](const pair<string, string>& p){return hash<string>()(p.first) + hash<string>()(p.second);};

        unordered_map<pair<string, string>, bool, decltype(hashf)> flags(10, hashf);

        function<bool(string, string, bool)> f = [&](string s1, string s2, bool reversed){
            if(s1.length() != s2.length() )
                return false;
            if(s1.length() == 0)
                return true;
            else if(s1.length() ==1)
                return s1 == s2;

            if(flags.count(make_pair(s1,s2)) != 0)
                return flags[make_pair(s1,s2)];

            map<char, int> m1, m2;
            int i = 0;
            m1[s1[i]] = 1;
            m2[s2[i]] = 1;
            ++i;
            while(i < s1.length()){
                while(i < s1.length() && m1 != m2){
                    m1[s1[i]]++;
                    m2[s2[i]]++;
                    ++i;
                }
                if(m1 != m2)
                    return false;
                else if (i < s1.length()){
                    if( f(s1.substr(0, i), s2.substr(0, i), false) && f(s1.substr(i), s2.substr(i), false)){
                        flags[make_pair(s1,s2)] = true;
                        return true;
                    }
                    else {
                        m1[s1[i]]++;
                        m2[s2[i]]++;
                        ++i;
                    }
                }
            }
            // reverse again
            bool b = false;
            if(reversed == false){
                reverse(s1.begin(), s1.end());
                b = f(s1, s2, true);
            }
            flags[make_pair(s1,s2)] = b;
            return b;
        };

        return f(s1, s2, false);
    }
};




int main() {
    cout << boolalpha << Solution().isScramble("rgeat", "great") << endl;
    cout << boolalpha << Solution().isScramble("rgtae", "great") << endl;
    cout << boolalpha << Solution().isScramble("xstjzkfpkggnhjzkpfjoguxvkbuopi", "xbouipkvxugojfpkzjhnggkpfkzjts") << endl;

    return 1;
}