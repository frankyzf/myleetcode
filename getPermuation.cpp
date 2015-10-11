#include "common.h"
//not checked yet


class Solution {
public:
    string getPermutation(int n, int k) {
        if(n == 0 || k == 0){
            return "";
        }
        vector<int> v(n, 1);
        partial_sum(v.begin(), v.end(), v.begin());

        function<void(int, vector<int>& )> f = [&f](int k,  vector<int>& v){
            if(k <= 0)
                return ;
            else if ( k ==1){
                iter_swap(v.end()-1, v.end()-2);
                return ;
            }
            int i = 1;
            int num = 1;
            while (num < k) {
                ++i;
                num *= i;
            }

            if(num > k){
                num /= i;
                --i;
            }
            int pos = v.size() -i;
            int j = pos;
            for (; j < v.size(); ++j) {
                if(v[j]>v[pos-1])
                    break;
            }
            swap(v[pos-1], v[j]);
            f(k-num, v);

        };

        f(k-1, v);
        stringstream ss;
        for_each(v.begin(), v.end(), [&ss](int i){ss << i;});
        return ss.str();
    }
};


int main() {
    cout << Solution().getPermutation(3, 5);
    return 1;
}