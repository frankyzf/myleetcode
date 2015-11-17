#include "common.h"
//not checked yet
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n <= 0 || k <= 0)
            return res;
        vector<int> data(n, 1);
        accumulate(data.begin(), data.end(), data.begin(), 0);
        vector<int> perm(n, 0);
        for(int i = 0; i < k; ++k){
            perm[i] = 1;
        }
        sort(perm.begin(), perm.end());
        do{
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if(perm[i]){
                    v.push_back(data[i]);
                }
            }
            res.push_back(move(v));
        }while(next_permutation(perm.begin(), perm.end()));
        return res;

    }
};
int main() {

    return 1;
}