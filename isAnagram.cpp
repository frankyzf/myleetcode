//
// Created by feng on 8/3/15.
//

#include "common.h"


class Solution {
public:
    bool isAnagram(string s, string t) {
        auto f = [](char c, vector<int>& cnt){ ++cnt[c-'a'];};
        vector<int> a (26,0);
        vector<int> b (26,0);
        for_each(s.begin(), s.end(), bind(f, placeholders::_1, ref(a) ));
        for_each(t.begin(), t.end(), bind(f, placeholders::_1, ref(b) ));

        for(int i = 0; i < 26; ++i)
        {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};


int main()
{
    cout << Solution().isAnagram("anagram", "nagaram");
    return 1;
}