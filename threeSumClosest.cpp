#include "common.h"
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int closest = numeric_limits<int>::max();
        int res_sum = numeric_limits<int>::max();
        sort(num.begin(), num.end());
        if(num.size() < 3)
            return closest;
        for(auto it = num.begin(); it != num.end() -2 ; it ++)
        {
            auto b = it +1;
            auto c = num.end() -1;
            while(b < c)
            {
                int dist = abs(*it + *b + *c - target);
                int sum = *it + *b + *c;
                //cout << *it << "," << *b << "," << *c << "," << target << ", " << dist << endl;
                if(dist < closest)
                {
                    res_sum = sum;
                    closest = dist;
                }
                if(sum < target)
                    b++;
                else if (sum > target)
                    c--;
                else
                    return sum;
            }
        }
        return res_sum;
    }
};


int main() {

    return 1;
}