//
// Created by tjuzf_000 on 4/10/2016.
//

#include "common.h"


class Solution {
public:
    int maxProduct(vector<string>& words) {
        auto mapf = [](const string& w){
            static vector<int> mm;
            if(mm.size() ==0){
                int mask = 1;
                for (int i = 0; i < 26; ++i) {
                    mm.push_back(mask);
                    mask <<= 1;
                }
            }
            int num = 0;
            for(auto& ch:  w){
                int n = mm[ch-'a'];
                num |= n;
            }
            return num;
        };

        unordered_map<string, int> mm;
        for(auto& w: words){
            mm[w] = mapf(w);
        }
        int maxvalue = 0;
        for(auto it = mm.begin(); it != mm.end(); ++it){
            auto it2 = it;
            for(; it2 != mm.end(); ++it2 ){
                if((it->second & it2->second) == 0){
                    maxvalue = max(maxvalue, (int)(it->first.length() * it2->first.length()));
                }
            }
        }
        return maxvalue;
    }

};


int main(){
    vector<string> v{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << Solution().maxProduct(v);
}



