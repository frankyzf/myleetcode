//
// Created by feng on 8/3/15.
//
#include "common.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        function<vector<int>(string)> f = [&f](string str) {
            vector<int> res;
            for (int m = 0; m < str.length(); ++m) {
                if (str[m] == '-' || str[m] == '+' || str[m] == '*') {
                    vector<int> left = f(str.substr(0, m));
                    vector<int> right = f(str.substr(m+1));
                    for (auto i = left.begin(); i != left.end(); ++i) {
                        for (auto j = right.begin(); j != right.end(); ++j) {
                            switch(str[m]){
                                case '+':
                                    res.push_back((*i)+(*j));
                                    break;
                                case '-':
                                    res.push_back((*i) - (*j));
                                    break;
                                case '*':
                                    res.push_back((*i) * (*j));
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                }
            }
            if(res.empty()){
                res.push_back(atoi(str.c_str()));
            }
            return res;
        };
        auto res = f(input);
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