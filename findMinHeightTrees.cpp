#include "common.h"
//not checked yet


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> stat;
        int sum = edges.size();
        if(sum == 0)
            return vector<int>{0};

        for (int i = 0; i < edges.size(); ++i) {
            stat[edges[i].first].insert(i);
            stat[edges[i].second].insert(i);
        }
        bool bchange = true;
        while(sum > 1 && bchange){

            vector<int> level;
            for(auto& item: stat){
                if(item.second.size() == 1){
                    level.push_back(item.first);
                    //cout << "item:" << item.first << ",";
                }
                // cout << __func__ << endl;
            }
            bchange = level.size() > 0;
            for(auto i: level){
                auto& item = stat[i];
                auto edgeindex = *item.begin();
                auto p = edges[edgeindex];
                auto other = p.first == i? p.second: p.first;
                stat.erase(i);
                stat[other].erase(edgeindex);
                --sum;
            }
        }
        vector<int> res;
        if(sum <=1){
            for(auto& item: stat){
                res.push_back(item.first);
            }
        }

        return res;
    }
};




int main() {
    vector<pair<int,int>> data {{1,0},{1,2},{1,3}};
    auto res = Solution().findMinHeightTrees(4, data);
    for(auto& i: res)
        cout << i << ", " ;
    cout << endl;
    return 1;
}