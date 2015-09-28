#include "common.h"
//not checked yet
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int size = nums.size();
        if(size == 0)
            return 0;
        function<pair<bool, int>(int, int)> f  = [&nums, &f](int begin, int end){
            if(begin>end)
                return make_pair(false, 0);

            int mid = (begin+end)/2;
            int maxn = 0;

            if(nums[mid] != 0) {
                vector<pair<bool, int>> left(3, {false, 0});
                int n = 1;
                for (int i = mid-1; i >= begin; --i) {
                    n *= nums[i];
                    if(n> 0 && (left[0].first == false || left[0].second < n)){
                        left[0].first = true;
                        left[0].second = n;
                    }
                    else if ( n< 0 &&  (left[1].first == false || left[1].second > n)){
                        left[1].first = true;
                        left[1].second = n;
                    }
                    else if(n == 0 && left[2].first == false){
                        left[2].first = true;
                    }
                }
                vector<pair<bool, int>> right(3, {false, 0});
                n = 1;
                for (int i = mid; i <= end ; ++i) {
                    n*= nums[i];
                    if(n > 0 && (right[0].first == false || right[0].second < n)){
                        right[0].first  = true;
                        right[0].second = n;
                    }
                    else if( n<0 &&  (right[1].first == false || right[1].second > n)){
                        right[1].first = true;
                        right[1].second = n;
                    }
                    else if(n == 0 && right[2].first == false){
                        right[2].first = true;
                    }
                }
                for(int i = 0; i < 3; ++i){
                    if(right[i].first){
                        maxn = right[i].second;
                        break;
                    }
                }

                if(right[0].first){
                    if(left[0].first){
                        maxn = max(maxn, right[0].second * left[0].second);
                    }
                    else{
                        maxn = max(maxn, right[0].second);
                    }
                }
                if(right[1].first){
                    if(left[1].first){
                        maxn = max(maxn, right[1].second * left[1].second);
                    }
                    else{
                        maxn = max(maxn, right[1].second);
                    }
                }

            }

            auto leftmax = f(begin, mid-1);
            if(leftmax.first ){
                maxn = max(maxn, leftmax.second);
            }

            auto rightmax = f(mid+1, end);
            if(rightmax.first )
                maxn = max(maxn, rightmax.second);
            return make_pair(true, maxn);
        };

        auto res =  f(0, nums.size()-1);
        return res.second;

    }
};

int main() {
    vector<int> data{0,-1,3,1,-3,2,1,1};
    cout << Solution().maxProduct(data);
    return 1;
}