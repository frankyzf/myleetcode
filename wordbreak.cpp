#include "common.h"

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        std::vector<std::set<int>  > v;

        set<int> cs;
        cs.emplace(-1);
        if(dict.find(s.substr(0,1)) != dict.end())
            cs.emplace(0);
        v.emplace_back(cs);

        for (int i = 0; i < s.length(); ++i)
        {
            std::set<int>& pv = v[i];
            std::set<int> cs = pv;
            cs.emplace(-1);
            for (std::set<int>::iterator it = pv.begin(); it != pv.end(); ++it)
            {
                int start = *it + 1;
                int len = i - start +1;
                if(dict.find(s.substr(start,len)) != dict.end())
                {
                    cs.insert(i);

                }
                else
                    cs.insert(start-1);

            }


            v.emplace_back(cs);
        }
        auto eit = *(v.end() - 1);
        auto size = s.length();


        if(eit.find(size -1) != eit.end())
            return true;
        else
            return false;
    }
};


int main() {

    return 1;
}