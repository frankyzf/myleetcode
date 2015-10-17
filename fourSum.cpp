#include "common.h"

//not checked yet
//dp solution  --> n^2
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int,int>>> mm;
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i+1; j < num.size(); ++j) {
                mm[num[i]+num[j]].emplace_back(i, j);
            }
        }
        for(auto& v: mm){
            int part1 = v.first;
            int part2 = target - part1;
            if(part1 == part2){
                for(auto it1 = v.second.begin(); it1 != v.second.end(); ++it1){
                    for(auto it2 = it1+1; it2 != v.second.end(); ++it2){
                        vector<int> tv{it1->first, it1->second, it2->first, it2->second};
                        sort(tv.begin(), tv.end());
                        if(unique(tv.begin(), tv.end()) == tv.end())
                            res.push_back(move(tv));
                    }
                }
            }
            else if (part1 < part2){
                auto it = mm.find(part2);
                if(it != mm.end()){
                    for(auto& item1: v.second){
                        for(auto& item2: it->second){
                            vector<int> tv{item1.first, item1.second, item2.first, item2.second};
                            sort(tv.begin(), tv.end());
                            if(unique(tv.begin(), tv.end()) == tv.end())
                                res.push_back(move(tv));
                        }
                    }
                }
            }
        }

        set<vector<int>> rv;
        for(auto pos: res){
            vector<int> t;
            for(auto i: pos){
                t.push_back(num[i]);
            }
            rv.insert(move(t));
        }
        return vector<vector<int>>(rv.begin(), rv.end());
    }
};


int main() {
    vector<int> data {-3,-2,-1,0,0,1,2,3};

    auto res = Solution().fourSum(data, 0);
    for (auto &v: res) {
        for (auto n: v) {
            cout << n << ",";
        }
        cout << endl;
    }
    return 1;
}
