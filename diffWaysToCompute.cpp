//
// Created by feng on 8/3/15.
//
#include "common.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<char> op;
        vector<int> data;
        vector<int> perm;
        int i;
        char c;
        istringstream ss(input);
        while(ss >> i >> c){
            data.push_back(i);
            op.push_back(c);
        }
        data.push_back(i);
        const int size = op.size();
        for(int i = 0; i < size; ++i) {
            perm.push_back(i);
        }
        vector<int> res;
        while(next_permutation(perm.begin(), perm.end()))
        {
            for (auto p: perm)
                cout << "p:" << p  << ",";
            cout << endl;

            int r ;
            vector<int> nd(data.begin(), data.end());
            for( int seq = 0; seq < size; ++seq)
            {
                int i = distance(perm.begin(), find(perm.begin(), perm.end(), seq) );
                int& k = nd[i];
                switch(op[i])
                {
                    case '*':
                        k *= nd[i+1];
                        break;
                    case '-':
                        k -= nd[i+1];
                        break;
                    case '+':
                        k += nd[i+1];
                        break;
                    default:
                        break;
                }
                nd[i+1] = k;
                r = k;
            }
            res.push_back(r);
        }
        sort(res.begin(), res.end());
        return res;
    }
};


int main()
{
    auto r = Solution().diffWaysToCompute("2*3-4*5");
    for(auto v :r)
        cout << v << ",";
    cout << endl;
    return 1;
}