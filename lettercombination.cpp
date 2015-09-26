#include "common.h"
//not checked yet
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mm{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        for (int i = 0; i < digits.length(); ++i) {
            string& ss = mm[digits[i] -'0'];
            size_t num = res.size();
            vector<string> tt{res};
            for(int j = 0; j < ss.length(); ++j){
                if(num == 0){
                    res.push_back(ss.substr(j, 1));
                }
                else{
                    vector<string> tmp(tt.begin(), tt.end());
                    if(j == 0) {
                        for_each(tmp.begin(), tmp.end(), [&ss, j](string& str){str.push_back(ss[j]);});
                        res.swap(tmp);
                    }
                    else {
                        for_each(tmp.begin(), tmp.end(), [&ss, j](string& str){str.push_back(ss[j]);});
                        res.insert(res.end(), tmp.begin(), tmp.end());
                    }
                }

            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};


int main() {
    auto r = Solution().letterCombinations("23");
    for(auto s: r)
        cout << s<< ",";
    return 1;
}