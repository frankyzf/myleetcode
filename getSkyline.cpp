//
// Created by feng on 8/14/15.
//

#include "common.h"

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> data;
        vector<pair<int,int>> res;
        if (buildings.size() == 0) {
            return res;
        }
        for(auto v: buildings) {
            data.push_back({v[0], -v[2]});
            data.push_back({v[1], v[2]});
        }
        sort(data.begin(), data.end());
        multiset<int> m;
        int prev = 0, cur = 0;
        m.insert(0);
        for (auto d: data) {
            if (d.second < 0) {
                m.insert(-d.second);
            }
            else {
                m.erase(m.find(d.second));
            }
            if((cur = *m.rbegin()) != prev) {
                prev = cur;
                res.push_back({d.first, cur});
            }
        }
        return res;
    }
};



int main(){
    vector< vector<int>> data {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    auto r = Solution().getSkyline(data);
    for(auto v: r) {
        cout << v.first << "," << v.second<< endl;
    }
    return 1;
}