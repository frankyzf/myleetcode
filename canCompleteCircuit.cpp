#include "common.h"
//not checked yet
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.size() == 0){
            return -1;
        }
        vector<int> diff;
        for (int i = 0; i < gas.size(); ++i) {
            diff.push_back(gas[i] - cost[i]);
        }
        int startpos = 0, left = 0, sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            left += diff[i];
            sum += diff[i];
            if(sum < 0){
                startpos = i+1;
                sum = 0;
            }
        }
        if(left < 0)
            return -1;
        else{
            return startpos;
        }
    }
};

int main() {

    return 1;
}