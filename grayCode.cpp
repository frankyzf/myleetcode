#include "common.h"
//not checked yet
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;

        function<void(int, bitset<32>&, bool)> f = [&f, n, &res](int start, bitset<32>& bt, bool bkeep){
            if(start >= n){
                int i = bt.to_ulong();
                res.push_back(i);
                return;
            }

            if(bkeep){
                f(start+1, bt, true);
                bt.flip(n - start-1);
                f(start+1, bt, true);
            }
            else{
                bt.flip(n - start-1);
                f(start+1, bt, true);
            }

        };

        bitset<32> bt;
        f(0, bt, true);
        return res;

    }
};


int main() {
    auto r = Solution().grayCode(2);
    for(auto d: r)
        cout << d << ";";
    return 1;
}