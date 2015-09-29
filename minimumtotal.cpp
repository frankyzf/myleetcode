#include "common.h"
//not checked yet
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        vector<int> costs;
        costs.push_back(triangle[0][0]);
        for(int i = 1; i < triangle.size(); ++i){
            vector<int> cs;
            cs.push_back(costs[0] + triangle[i][0]);
            for(int j = 1; j < triangle[i].size()-1; ++j){
                cs.push_back(triangle[i][j] + min(costs[j-1], costs[j]));
            }
            cs.push_back(costs.back() + triangle[i].back());
            costs.swap(cs);
        }
        auto it = min_element(costs.begin(), costs.end());
        return *it;
    }
};
int main() {

    return 1;
}