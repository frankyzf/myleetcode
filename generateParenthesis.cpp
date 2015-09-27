#include "common.h"
//not checked yet
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<01)
            return res;
        res.push_back("()");
        for (int i = 1; i < n; ++i) {
            //left parenthesis
            set<string> tmp;
            for(const auto& str: res){
                for(int j = 0; j < str.length(); ++j){
                    if(j == 0 || str[j-1] != '('){
                        string tmpstr(str);
                        tmpstr.insert(j, 1, '(');
                        tmp.insert(move(tmpstr));
                    }
                }
            }
            //right parenthensis
            set<string> tmp2;
            for(const auto& str: tmp) {
                int left = 0;
                int right = 0;
                for (int j = 0; j < str.length(); ++j) {
                    if (j>0 && left > right && str[j - 1] == '(') {
                        int k = j;
                        int kleft = left;
                        int kright = right;
                        bool binsert = true;
                        for (int k = j; k < str.length() ; ++k){
                            if(str[k] == '(')
                                ++kleft;
                            else{
                                ++kright;
                                if(kleft <= kright)
                                    binsert = false;
                            }
                        }

                        if(binsert ){
                            string tmpstr(str);
                            tmpstr.insert(j, 1, ')');
                            #ifdef DEBUG
                                cout << j << ":" << str << "-->" << tmpstr << "\n";
                            #endif
                            tmp2.insert(move(tmpstr));
                        }
                    }
                    if(str[j] == '(')
                        ++left;
                    else if(str[j] == ')')
                        ++right;
                }
            }
            res.assign(tmp2.begin(), tmp2.end());
        }
        return res;
    }
};


int main() {
    auto res = Solution().generateParenthesis(5);
    for (auto &s: res) {
        cout << s << ",";
    }
    return 1;
}