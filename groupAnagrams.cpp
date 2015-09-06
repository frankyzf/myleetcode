//
// Created by feng on 8/17/15.
//

#include "common.h"
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        const int size = strs.size();
        if (size == 0) {
            return res;
        }
        map<vector<int>, vector<string> > mm;
        while(!strs.empty()){
            auto& s = strs[strs.size()-1];
            vector<int> vv(26,0);
            for(auto c: s) {
                ++vv[c - 'a'];
            }
            mm[vv].push_back(move(s));
            strs.pop_back();
        }

        while(!mm.empty()) {
            auto item = mm.begin();
            sort(item->second.begin(), item->second.end());
            res.push_back(move(item->second));
            mm.erase(item->first);
        }

        return res;
    }
};


int main(){
    vector<string> data {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto r = Solution().groupAnagrams(data);
    for(auto v: r) {
        for (auto i : v) {
            cout << i << ".";
        }
        cout <<endl;
    }

    return 1;
}