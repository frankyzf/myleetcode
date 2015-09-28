#include "common.h"

//not checked yet
//dp solution  --> n^2
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());

        function<void(int, const map<int, vector<int>>&)> f
                = [&f,&num, &res](int t, int k,  unordered_map<int, vector<int>>& mysort){
            if(k ==1){
                for (auto it = mysort.begin(); it < mysort.end(); ++it) {
                    auto rangeit = equal_range(num.begin(), num.end(), t - it->first);
                    for(auto first = rangeit.first; first != rangeit.second; ++first){
                        auto index = distance(num.begin(), first);
                        if(find(it->second.begin(), it->second.end(), index) == it->second.end()){
                            vector<int> v;
                            for_each(it->second.begin(), it->second.end(), [&v, &num](int i){v.push_back(num[i]);});
                            v.push_back(*first);
                            sort(v.begin(), v.end());
                        }
                    }
                }
            }
            else{

            }
        };
        unordered_multimap<int, pair<int,int>> dp2;
        unordered_multimap<int, vector<int> > dp3;
        sort(num.begin(), num.end());

        //2 num sum;
        for(int i = 0; i < num.size() -1; ++i){
            for(int j = i+1; j < num.size(); ++j){
                int sum = num[i] + num[j];
                dp2.insert(make_pair(sum, make_pair(i, j)));
            }
        }

        // 3 sum
        auto it = dp2.begin();
        while(it != dp2.end()){
            int sum = it->first;
            int first = it->second.first;
            int second = it->second.second;
            for(int j = 0; j < num.size(); ++j){
                if(j != first && j != second){
                    vector<int> v{first, second, j};
                    sum += num[j];
                    dp3.insert(make_pair(sum, move(v)));
                }
            }
            dp2.erase(it++);
        }


        for(int i = 0; i < num.size(); ++i){
            auto rangeit = dp3.equal_range(target - num[i]);
            auto firstit = rangeit.first;
            if(firstit != dp3.end()){
                while(firstit != rangeit.second) {
                    if (find(firstit->second.begin(), firstit->second.end(), i) == firstit->second.end()) {
                        vector<int> v;
                        for_each(firstit->second.begin(), firstit->second.end(),
                                 [&v, &num](int index){v.push_back(num[index]);});
                        v.push_back(num[i]);
                        sort(v.begin(), v.end());
                        res.push_back(move(v));
                    }
                    ++firstit;
                }
            }
        }

        return res;
    }


};


int main() {
    vector<int> data {1,0,-1,0,-2,2};

    auto res = Solution().fourSum(data, 0);
    for (auto &v: res) {
        for (auto n: v) {
            cout << n << ",";
        }
        cout << endl;
    }
    return 1;
}
